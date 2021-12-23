#include "assignment.h"
#include <time.h> 
#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; } 
unsigned long int mult(unsigned long int a, unsigned long int b); 
int findClosestBase2(unsigned long int c, int l);
void ex6(){ 
    unsigned long int a, b;
    srand(time(NULL));
    #ifndef TEST 
        a=rand(); 
        b=rand(); //generate a,b to initialize
        printf("%ld*%ld=%ld %ld\n",a,b,mult(a,b), (unsigned long int)RAND_MAX);
    #endif 
    #ifdef TEST  //test the algorithm for 1000000 times
        int i; 
        for(i=0; i< 1000000; i++) { 
                a=rand(); 
                b=rand(); 
                if(mult(a,b)!=a*b) { 
                    fprintf(stderr,"Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n", i,a,b,a*b,mult(a,b));
                    exit(-1);
                } 
        }
    #endif 
}

//karatsuba
unsigned long int mult(unsigned long int a, unsigned long int b) { 
    int i, n, N; 
    unsigned long int x0,y0,z0,z1=1; 
    if(a<b) SWAP(a,b); // make sure a<b
    if(b==0) return 0; 
    n = findClosestBase2(b, 64)-1;
    N = findClosestBase2(a, 64)-1;//find the greatest 2^n close to a and b
    y0=b&((1<<n)-1); 
    x0=a&((1<<N)-1); //calculate x-closest 2^n
    z0=mult(x0,y0); //recursion 
    i=N+n; 
    return ((z1<<i)+(x0<<n)+(y0<<N)+z0); //add together the result
}

//find it through bitwise operation
int findClosestBase2(unsigned long int c, int l){
    if(l == 1) return c;
    l = l/2;
    unsigned long int a = ((unsigned long int)1<<l)-1;
    a = a & c;
    c = (c ^ a)>>l;
    if(c){
        return findClosestBase2(c,l) + l;
    }else{
        return findClosestBase2(a,l);
    }
}
