#include <stdio.h>

int all_solve = 0;

int is_attack(int colomn[], int row[], int cross_up[], int cross_down[], int x, int y, int len){
    
    if(colomn[x] != 1 && row[y] != 1 && cross_up[x+y] != 1 && cross_down[-y+x+len] != 1){
        
        return 0;
        
    }else{
        
        return 1;
        
    }
    
}

void queen(int colomn[], int row[], int cross_up[], int cross_down[], int len, int x, int series[]){
   
    if(x == len + 1){
        printf("[");
        for(int i = 0; i < len+1; i ++){
            printf("\"");
            for(int j = 0; j < len+1; j ++){
                if(series[i] == j){
                    printf("Q");
                }else{
                    printf(".");
                }
            }
            printf("\",\n");
            
        }
        all_solve = all_solve + 1;
        printf("]\n\n");
        
        
    }else{
        
        for(int i = 0; i < len+1; i++) {
            
            if(is_attack(colomn, row, cross_up, cross_down, x, i, len) == 0){
                
                series[x] = i;
                colomn[x] = 1;
                row[i] = 1;
                cross_up[x+i] = 1;
                cross_down[-i+x+len] = 1;
                queen(colomn, row, cross_up, cross_down, len, x+1, series);
                series[x] = 0;
                colomn[x] = 0;
                row[i] = 0;
                cross_up[x+i] = 0;
                cross_down[-i+x+len] = 0;
                
            }else{
                
                continue;
                
            }
            
        }
        
    }
    
}


int main(int argc, const char * argv[]) {
    
    int d;
    scanf("%d", &d);
    int colomn[100], row[100], cross_up[100], cross_down[100], series[100];
    for(int i = 0; i < 100; i ++){
        colomn[i] = 0;
        row[i] = 0;
        cross_up[i] = 0;
        cross_down[i] = 0;
    }
    
    queen(colomn, row, cross_up, cross_down, d-1, 0, series);
    
}
