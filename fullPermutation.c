/*We can use this method to solve full permutation problem.
* Firstly, we enter an integer, n, which is the number of integers to be arranged
* in the first row. Secondly, enter the n integers. Then, We can get all possible 
* permutations in lexicographical order.
*/

#include<stdio.h>
void permutation(int n,int m[],int trace[],int k,int used[]);
int main(){
    int i,n,j,m[13],trace[13]={0},used[13]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(m[j]>m[j+1]){
                int tmp=m[j];
                m[j]=m[j+1];
                m[j+1]=tmp;
            }
            else;
        }
    }
    permutation(n,m,trace,0,used);
}
void permutation(int n,int m[],int trace[],int k,int used[]){
    if(k==n) {
        for(int i=0;i<n;i++){
            printf("%d ",trace[i]);
        }
        printf("\n");
    }
    if(k!=n){
        for(int i=0;i<n;i++){
            if(used[i]==1){
                continue;
            }
            else{
                used[i]=1;
                trace[k]=m[i];
                permutation(n,m,trace,k+1,used);
                used[i]=0;
            }
        }
    }
}
