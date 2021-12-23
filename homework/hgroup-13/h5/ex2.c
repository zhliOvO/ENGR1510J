#include "assignment.h"
#include <string.h>
// ex. 2 function: disptach work to other functions for exercise 2
void ex2() 
{
  int m,d=0,day=1;
  char *month[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  char s[4];
  char *mm=month[0];
  if(scanf("%d%s",&m,s)){};
  mm=month[m-1]; //decide the month
  printf("%s\n",mm);
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  if (strcmp(s,"Sun")==0) d=1;
  if (strcmp(s,"Mon")==0) d=2;
  if (strcmp(s,"Tue")==0) d=3;
  if (strcmp(s,"Wed")==0) d=4;
  if (strcmp(s,"Thu")==0) d=5;
  if (strcmp(s,"Fri")==0) d=6;
  if (strcmp(s,"Sat")==0) d=7;
  //printf("%d",d);
  for (int i=1;i<=4*d-2;i++) 
    printf(" ");
  while (day<=md[m-1])
  {
    if (day>=10)
    {
    printf("%d  ",day);
    }
    else
    {
  	printf("%d   ",day);
    }
  	if (d==7&&day<9) 
	  {
	  	printf("\n  ");d=d-7;
	  }
    else if (d==7&&day>=9) 
	  {
	  	printf("\n ");d=d-7;
	  }
    d++;
  	day++;
  }
  
}

#ifdef JOJ
int main()
{
    ex2();
    return 0;
}
#endif