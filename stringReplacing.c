/*We want to replace the sub-string, B, in the main string, A, by small string, C.
* We have to enter 3 rows of strings which reprecent A, B and C, and show the string
* treated and the number of replaces. This is a good example of the use of pointers. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

int replaceStr(char *A, const char *B, const char *C)
{
    int counter = 0;
    int lenb = strlen (B);
    while(strstr(A,B)!=NULL){
        int lena = strlen (A);
        counter = counter + 1;
        char tmp[1000] = "";
        int lenstr0 = lena - strlen(strstr(A,B));
        strncat(tmp, A, lenstr0);
        strcat(tmp,C);
        strcat(tmp,strstr(A,B)+lenb);
        strcpy(A, tmp);
        return 1;
    }
    if(counter != 0)
        if(counter == 0){
            strcat(A,C);
        }
    return counter;
}

int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;
    gets(str1);
    gets(str2);
    gets(str3);
    
    nRes = replaceStr(str1, str2, str3);
    printf("%d\n", nRes);
    printf("%s\n", str1);
    
    return 0;
}
