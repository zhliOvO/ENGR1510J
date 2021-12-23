#include "assignment.h"
#include<string.h>
// ex. 3 function: disptach work to other functions for exercise 3
void ex3() 
{
    char a[100000],b[100];
    int count=0,la,lb;
    FILE *fa=fopen("sentence.txt","r");
    FILE *fb=fopen("word.txt","r");
    FILE *fw=fopen("count.txt","w");
    //open the files
    if(fscanf(fa,"%[^\n]",a)){};
    if(fscanf(fb,"%[^\n]",b)){};
    la=(int)strlen(a);lb=(int)strlen(b); // find the length of the two strings
    for (int i=0;i<=la-lb;i++)
    {
       int f=1;
       for (int j=0;j<lb;j++)
           if (a[i+j]!=b[j]) // compare each character
             f=0;
       if ((a[i+lb]<='z' && a[i+lb]>='a') || (a[i+lb]<='9' && a[i+lb]>='0') || (a[i+lb]<='Z' && a[i+lb]>='A')) f=0;
       if (f==1) count++;
    }
    fprintf(fw,"%d",count);
    fclose(fa);
    fclose(fb);
    fclose(fw);
    //close the file
}
#ifdef JOJ
int main()
{
    ex3();
    return 0;
}
#endif
