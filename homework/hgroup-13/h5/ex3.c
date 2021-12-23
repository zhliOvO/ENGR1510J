#include "assignment.h"
#include <stdio.h>
#include <string.h>
#define N 10000
// ex. 3 function: disptach work to other functions for exercise 1


// get the length of word , sentence
int getlength(char word[]){
    int i=0;
    while(word[i])
    i++;
    return i;
}

void ex3() {

    int i,j;
    int num=0;
    char sentence[N],word[N];

    
    if(fgets(sentence,N,stdin)){};

    if(fgets(word,N,stdin)){};

    if(sentence[strlen(sentence)-1=='\n']){
        sentence[strlen(sentence)-1]='\0';
    }

    if(word[strlen(word)-1=='\n']){
        word[strlen(word)-1]='\0';
    }

    int lengthword=getlength(word);

    /*int lengthsentence=getlength(sentence);*/

    for (i=0;sentence[i];i++)
    {
        int k=0;
        for (j=0;j<lengthword;j++)
        {
            if (sentence[i+j]==word[j])
            {
            k++;
            }
        }

        if (k==lengthword)
        {
            num++;
        }

       /* if((i!=0)&&(i+lengthword+1<lengthsentence)&&(k==lengthword)&&(sentence[i+lengthword]==' ')&&(sentence[i-1]==' '))
        {
        num++;
        }
            else if((i==0)&&(k==lengthword)&&(sentence[i+lengthword]==' '))
            {
            num++;
            }
                else if((i+lengthword+1==lengthsentence)&&(k==lengthword)&&(sentence[i-1]==' '))
                {
                num++;
                }*/
    }

    printf("The string '%s' occurs %d times",word,num);
 
}

#ifdef JOJ
int main(){
    ex3();
    return 0;
}
#endif