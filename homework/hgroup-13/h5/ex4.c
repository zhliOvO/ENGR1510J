#include "assignment.h"
#include <math.h>
#include <float.h>
#define g 9.81
#define pi 3.1415926535
void root(double v0,double angle,double height,double range_min,double range_max);
double function(double v0,double angle,double height,double x);
// ex. 4 function: disptach work to other functions for exercise 4
void ex4() {
    double v0=0,angle=0,height=0,range_min=0,range_max=0;
    if(scanf("%lf %lf %lf %lf %lf\n",&v0,&angle,&height,&range_min,&range_max)){
        angle=angle/180.0*pi;//turn degree into radian
        root(v0,angle,height,range_min,range_max);
    }
}
void root(double v0,double angle,double height,double range_min,double range_max){
    if (fabs(function(v0,angle,height,range_min))==0)
        printf("%.6lf",range_min);
    else if (fabs(function(v0,angle,height,range_max))==0)
        printf("%.6lf",range_max);
    else{
        double x=(range_max+range_min)/2.0;
        if(range_max-range_min<=FLT_EPSILON)
            printf("%.6lf",x);
        else{
            if(function(v0,angle,height,x)*function(v0,angle,height,range_min)<0)
                root(v0,angle,height,range_min,x);
            else
                root(v0,angle,height,x,range_max);
    }
    }   
}
double function(double v0,double angle,double height,double x){
    double y=height+tan(angle)*x-pow(x,2.0)*(g/2/pow(v0,2.0)/pow(cos(angle),2.0));
    return y;
}
#ifdef JOJ
int main(){
    ex4();
    return 0;
}
#endif
