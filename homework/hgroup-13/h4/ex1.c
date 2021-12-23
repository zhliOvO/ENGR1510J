#include "assignment.h"
// ex. 1 function: disptach work to other functions for exercise 1
typedef struct
{
  int re;
  int im;
}ComplexNum; //represent a complex number using a structure
void sum(ComplexNum a,ComplexNum b)
{
	if (a.im+b.im<0)
	printf("%d%di",a.re+b.re,a.im+b.im);
	else
	printf("%d+%di",a.re+b.re,a.im+b.im);
}
void product(ComplexNum a,ComplexNum b)
{
	int rea,ima;
	rea=a.re*b.re-a.im*b.im;
	ima=a.re*b.im+a.im*b.re;
	if (ima<0) 
	printf("%d%di",rea,ima);
	else
	printf("%d+%di",rea,ima);
}
void ex1() 
{
    ComplexNum a,b;
    char opt; 
    if(scanf("%d%di %d%di %c",&a.re,&a.im,&b.re,&b.im,&opt)){};
    //printf("%d+%d %d+%d %c",a.re,a.im,b.re,b.im,opt);
    if (opt=='+')
    	sum(a,b);
    if (opt=='*')
        product(a,b);
}
#ifdef JOJ
int main()
{
    ex1();
    return 0;
}
#endif
