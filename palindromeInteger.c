#include<stdio.h>
#include<math.h>

/*C code for finding the nth 'palindrome integer', which means this integer can be written
* reversely with no value changes. For example, the 11st 'palindrome integer' is 111.
*/
int main(){
    long long int k;
    long long int a[1000];
    scanf("%lld",&k);
    k = k + 1;
    int counter = -1;
    long long int m = k;
    while(m > 0){
        counter = counter + 1;
        if(counter%2 == 0)m = m - (int)round(pow(10, counter / 2 ))*9;
        if(counter%2 != 0)m = m - (int)round(pow(10, (counter -1)/2 ))*9;
    }//counter是位数-1
    if(counter % 2 == 0){
        m = m + (int) (round(pow(10, counter /2 )*9) );
        m = m + (int) (round(pow(10, counter /2) ) )- 1;
    }
    else {
        m = m + (int) (round(pow(10, (counter - 1)/2)*9));
        m = m + (int) (round(pow(10, (counter - 1)/2) ) ) - 1;
    }
    long long int i;
    long long int k0;
    if(counter%2 == 0){
        i = 0;
        while(m != 0) {
            k0 = m % 10;
            a[counter / 2 + i] = k0;
            a[counter / 2 - i] = k0;
            i = i + 1;
            m = (m - k0 )/10;
        }
    }
    else{
        i = 0;
        int p = (counter - 1)/2;
        while(m != 0){
            k0 = m % 10;
            a[p + 1 + i] = k0;
            a[p - i] = k0;
            i = i + 1;
            m = (m - k0)/10;
        }
    }
    for(i = 0; i <= counter; i ++)printf("%d",a[i]);
}
