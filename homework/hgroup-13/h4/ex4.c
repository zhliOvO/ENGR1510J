#include "assignment.h"
typedef struct _input{int n;char b;} input;
int choose();
void function1();
void function2();
void datatype(int size);
// ex. 4 function: disptach work to other functions for exercise 4
void ex4() {
int choice=choose();
switch (choice){
    case 1:
        function1();
        break;
    case 2:
        function2();
        break;
    default:
        printf("You didn't choose correctly\n");
        break;
    }   
}
int choose(){
    printf("choose the functionality(1.check whether the letter is a vowel or a consonant 2.show the data types eqaul to the size\n");
    int choice=0;
    if(scanf("%d",&choice)){};
    return choice;
}
void function1(){
    char letter;
    if(scanf("\n%c",&letter)){};
    switch (letter){
        case 'a':case 'e':case 'i':case 'o':case 'u':
            printf("It's a vowel\n");
            break;
        default:
            printf("It's a consonant\n");
            break;
    }
}
void function2(){
    input size;
    if(scanf("\n%d %c",&size.n,&size.b)){};
    switch(size.b){
        case 'B':
            datatype(size.n);
            break;
        case 'b':
            if (size.n%8==0)
                datatype(size.n/8);
            else
                printf("no such data type\n");
            break;
    }          
}
void datatype(int size){
    switch(size){
        case 1:
            printf("char\n");
            break;
        case 2:
            printf("short int\n");
            break;
        case 4:
            printf("int, float, long int in 32bit-computer\n");
            break;
        case 8:
            printf("long long int, double\n");
            break;        
        default:
            printf("no such data type\n");
            break;
    }
}
#ifdef JOJ
int main(){
    ex4();
    return 0;
}
#endif
