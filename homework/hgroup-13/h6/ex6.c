#include "assignment.h"
#include <string.h>

void change(char* str, char l, char* new, int o, char rep);
void ex6(){ 
    //input
    char o[10]; char letter[10]; char rep[10] = {0};
    char* str = malloc(1100000*sizeof(char));
    char* new = malloc(1100000*sizeof(char));
    if( str == NULL || new == NULL) exit(1);
    fgets(str,1100000,stdin);
    if(scanf("%[^\n]",o)){};
    getchar();
    if(scanf("%[^\n]",letter)){};
    getchar();
    int op = *o-'0';
    if(op == 1){
        if(scanf("%[^\n]",rep)){};
    }; 
    //replace char or remove char 
    change(str,*letter,new, op, *rep);
    //print result
    printf("Input a string: * Choose 1 to replace a character or 2 to delete a character:   ");
    op == 1? printf("Replace character:   with: "): printf("Delete character: ");
    printf("New string: %s",new);
    free(new); free(str);
}

void change(char* str, char l, char* new, int o, char rep){
    int start = 0;
    int nstart = 0;
    for(int i = 0; i < (int)strlen(str); i++){
        if(str[i] == l){
            memmove(new+nstart,str+start,(size_t)(i-start));//copy char that is not letter
            nstart+=i-start;
            if(o == 1) new[nstart++] = rep;//if need to replace
            start = i + 1;
        }
    }
    memmove(new+nstart,str+start,(size_t)((int)strlen(str)-start+1));
}

#ifdef JOJ
int main(){
    ex6();
    return 0;
}
#endif
