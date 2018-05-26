package guiWork2;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import javax.swing.*;
import guiWork.GUIwork.saveField;
import guiWork.GUIwork.textField;

/*The codes are about how to move a file to another place in your computer and 
show the progress bar to present the progress of uplaod.*/


class CopyingFiles implements Runnable{
	
	
	String filename;
	String filelocation;
	String outputlocation;
	int progress;
	int size;
	
	
	CopyingFiles(String filename, String filelocation, String outputlocation){
		
		this.filename = filename;
		this.filelocation = filelocation;
		this.outputlocation = outputlocation;
		
	}
	
	
	public void run() {
		
		try {
			this.progress = 0;
			FileInputStream fileinputstream = new FileInputStream(filelocation + filename);
			this.size = fileinputstream.available();
			BufferedInputStream input = new BufferedInputStream(fileinputstream,size);
			 
	        FileOutputStream fileoutputstream = new FileOutputStream(outputlocation + filename);
	        BufferedOutputStream output = new BufferedOutputStream(fileoutputstream, size);
	         
	        byte[] buffer=new byte[1];
	        int abyte = 0;
	        while(( abyte =input.read(buffer)) != -1) {
	        	
	        	output.write(buffer,0, abyte);
	        	progress = progress + 1;
	        	System.out.println(progress);
	        	
	        }
	        
	        output.flush();
	        input.close();
	        output.close();
	        System.out.println("Finish");
	        Thread.yield();
	         
		} catch (Exception e) {
			
			e.printStackTrace();
	    
		}
		 
	}
	
	public int getprogress() {
		double a = (double) this.progress;
		double b = (double) this.size;
		
		return (int) ((a / b) * 100 + 1);
	}
	
}

class ProgressBar extends JFrame implements Runnable{
	
	public JProgressBar progressbar = new JProgressBar();
	public ProgressMonitor progressmoniter = new ProgressMonitor(this, "Progress","Test", 0, 100);
	public CopyingFiles cf;
	
	public ProgressBar(CopyingFiles cf){
		
		this.cf = cf;
		setLayout(new FlowLayout());
		add(progressbar);
		
	}
	
	
	public void run() {
		
		int process = 0;
		progressmoniter.setProgress(process);
		while(process != 100) {
			process = cf.getprogress();
			progressmoniter.setProgress(process);
			try{
				Thread.sleep(1000);
				}
			catch( Exception e){}
			
		}
		Thread.yield();
		
	}
}



class GUIwork {
	
	private JButton button1;
	private JButton button2;
	
	private JTextArea textarea1;
	private JTextArea textarea2;
	private JTextArea textarea3;
	
	private JLabel label1;
	private JLabel label2;
	private JLabel label3;

	public class textField extends JFrame implements ActionListener {
		
		textField(){
			
			setLayout(new FlowLayout());
			textarea1 = new JTextArea(1, 50);
			textarea2 = new JTextArea(1, 50);
			textarea3 = new JTextArea(1, 50);
			label1 = new JLabel("文件名称");
			label2 = new JLabel("文件路径");
			label3 = new JLabel("保存路径");
			add(label1);
			add(textarea1);
			add(label2);
			add(textarea2);
			add(label3);
			add(textarea3);
			
			button2 = new JButton("Exit");
			button1 = new JButton("OK");
			add(button1);
			add(button2);
			
			button1.addActionListener(this);
			button2.addActionListener(this);
			
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setVisible(true);
			setSize(700, 300);
			
		}
		public void actionPerformed(ActionEvent e) {
			if(e.getSource() == button1) {
				
				try{
					CopyingFiles cp = new CopyingFiles(textarea1.getText(), textarea2.getText()+'/', textarea3.getText()+'/');
					new Thread(new ProgressBar(cp)).start();
					new Thread(cp).start();
				}
				
				catch ( Exception ee) {}
				}
				
				if(e.getSource() == button2) {
					
					System.exit(0);
				}
		}
		
	}

}


public class GUI{
	
	public static void main(String args[]) {
		GUIwork gWork = new GUIwork();
		gWork.new textField();
		
	}
}
