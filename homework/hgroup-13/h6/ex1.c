#include "assignment.h"
#include <stdlib.h>
#include <time.h>

//function prototypes
int findMax(int* p, size_t s);
void dispSmaller(int* p, size_t s, int r);
// ex. 1 function: scanf through an array of integers and 
//display the numbers larger than a given random integer smaller than the max of the array
void ex1() {
    //read array
    size_t s;
    scanf("%lu", &s);
    int* a = malloc(s*sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Error: out of memory");
        exit(1);
    }
    for(int i = 0; i < (int)s; i++){
        scanf("%d",&a[i]);
    }

    //disp numbers smaller than random number(<max of the array)
    int* p = a;
    int max = findMax(p,s);
    p = a;
    srand((unsigned int)time(NULL)); 
    int r = rand()%max;
    printf("the numbers in the array smaller than %d\n", r);
    dispSmaller(p,s,r); 
    free(a);
}

//scanf through an array of known size to find max
int findMax(int* p, size_t s){
    int max = *p;
    for(int i = 1; i < (int)s; i++){
        if(p[i] > max) max = p[i];
    }
    return max;
}

//scanf and display numbers smaller than a random value in an array
void dispSmaller(int* p, size_t s, int r){
    for(int i = 0; i < (int)s; i++){
        if(p[i]<r) printf("%d ", p[i]);
    }
}

#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
