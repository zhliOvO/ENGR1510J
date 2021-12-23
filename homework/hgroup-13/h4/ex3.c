#include "assignment.h"
#include<math.h>
// ex. 3 function: disptach work to other functions for exercise 3
void ex3() 
{
  float a,b,c,delta;
  double sqd;
  if(scanf("%f%f%f",&a,&b,&c)){};
  if(a!=0)
  {
 	delta=b*b-a*c*4;
 	if (delta==0)
		printf("%.5f",-b/(a*2)); //set the precision of decimal to 5
  	if(delta>0)
  	{
  		sqd=sqrt(delta);
 	 	printf("%.5f\n%.5f",(-b-sqd)/(a*2),(-b+sqd)/(a*2));
  	}
  	if(delta<0)
  	{
  		sqd=sqrt(fabs(delta));
  	 	printf("%.5f-%.5fi\n%.5f+%.5fi",-b/(a*2),fabs(sqd/(a*2)),-b/(a*2),fabs(sqd/(a*2)));
  	}
  }
  else
  {
		if(b!=0) 
		  printf("%.5f",-c/b);
		else //These two situations are not required I add it here to be more rigorous
		  if (c==0)
		    printf("No solution");
		  else 
		    printf("All real numbers");
  }
}

#ifdef JOJ
int main(){
    ex3();
    return 0;
}
#endif