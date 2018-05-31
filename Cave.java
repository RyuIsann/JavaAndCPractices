package passingCave;
import java.util.concurrent.*;
import java.util.Date;

class PassingCave implements Runnable{
	
	int passing_time;
	String name;
	
	PassingCave (int passing_time, String name) {
		
		this.passing_time = passing_time;
		this.name = name;
		
	}
	
	public void run() {
		
		try {
			Thread.sleep(this.passing_time * 1000);
		} catch (Exception e){}
		Date now = new Date();
		System.out.println(this.name+" passed the cave at "+ now);
		
		Thread.yield();
		
	}
	
}


public class Cave {
	
	public static void main(String args[]) {
		int cave_size = 2;
		String people[] = new String[] {
				"Amy","Bob","Chris","Dann","Eddie","Frank","Grace","Helen","Iris","Jack"
		};
		int[] time = new int[10];
		
		for(int i = 0; i < 10; i++) {
			time[i] = (int)( Math.random()*(10) + 1);
			System.out.println(time[i]);
		}
		
		ExecutorService exec = Executors.newFixedThreadPool(cave_size);
		
		for(int i = 0; i< 10; i++) {
			exec.execute(new PassingCave(time[i], people[i]) );
		}
	}
	
}
