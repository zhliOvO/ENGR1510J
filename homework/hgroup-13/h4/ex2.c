#include "assignment.h"
void gcd(int a, int b);
// ex. 2 function: disptach work to other functions for exercise 2
void ex2(){    
    int a = 0;int b = 0;
    if (scanf("%d %d", &a, &b)){};
    gcd(a, b);
}
void gcd(int a, int b)
{
    if (b == 0)
        printf("%d\n",a);
    else
        gcd(b, a % b);
}

#ifdef JOJ
int main()
{
    ex2();
    return 0;
}
#endif
