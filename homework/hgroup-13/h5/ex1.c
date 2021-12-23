#include "assignment.h"
#include <math.h>
void getprime(const int n);
// ex. 1 function: disptach work to other functions for exercise 1
void ex1() {
    int n=0;
    if(scanf("%d",&n)){
        getprime(n);
    }
}
void getprime(const int n){
    int primes[100000];
    int number=0;
    for(int i=2;i<n;i++){
        int flag=0;
        for (int j=2;j<=sqrt(i);j++){
            if(i%j==0){
            flag++;
            break;
            }
        }
        if(flag==0){
            primes[number]=i;
            number++;
        }
    }
    for (int i=0;i<number;i++){
        printf("%d ",primes[i]);
    }
}
#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
