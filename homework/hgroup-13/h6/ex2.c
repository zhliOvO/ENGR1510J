#include <math.h>
#include "assignment.h"
#define pi acos(-1)
typedef struct _cartesian
{
    double real;
    double imag;
}cartesian;
typedef struct _polar{
    double length;
    double radian;
}polar;
polar ctop(const cartesian* C_coordinate);
cartesian ptoc(const polar* P_coordinate);
// ex. 2 function: disptach work to other functions for exercise 2
void ex2()
{
    cartesian C_coordinate[4];
    polar P_coordinate[2];
    C_coordinate[0]=(cartesian){3.,0.8};C_coordinate[1]=(cartesian){0.,log(4)};C_coordinate[2]=(cartesian){45.245,0.235};
    C_coordinate[3]=(cartesian){4*cos(pi/9),4*sin(pi/9)};
    P_coordinate[0]=(polar){3.,pi/17};P_coordinate[1]=(polar){1.,pi/12};
    for(int i=0;i<3;i++){
        polar P_coordinate2=ctop(C_coordinate+i);//concert C to P
        printf("%.5lf+%.5lfi %.5lfe%.5lfi\n",C_coordinate[i].real,C_coordinate[i].imag,P_coordinate2.length,P_coordinate2.radian);
    }
    for(int i=0;i<2;i++){
        cartesian C_coordinate2=ptoc(P_coordinate+i);//convert P to C
        printf("%.5lfe%.5lfi %.5lf+%.5lfi\n",P_coordinate[i].length,P_coordinate[i].radian,C_coordinate2.real,C_coordinate2.imag);\
        if(i==0){
            polar P_coordinate2=ctop(C_coordinate+3);
            printf("%.5lf+%.5lfi %.5lfe%.5lfi\n",C_coordinate[3].real,C_coordinate[3].imag,P_coordinate2.length,P_coordinate2.radian);
        }// to insert the 5th complex number
    }
}
polar ctop(const cartesian* C_coordinate){
    polar P_coordinate;
    P_coordinate.length=pow(pow(C_coordinate->real,2)+pow(C_coordinate->imag,2),0.5);
    if(C_coordinate->real!=0){
        P_coordinate.radian=atan(C_coordinate->imag/C_coordinate->real);
    }
    else if(C_coordinate->imag>0){
        P_coordinate.radian=pi/2;
    }
    else if(C_coordinate->imag<0){
        P_coordinate.radian=-pi/2;
    }
    return P_coordinate;
}
cartesian ptoc(const polar* P_coordinate){
    cartesian C_coordinate;
    C_coordinate.real=P_coordinate->length*cos(P_coordinate->radian);
    C_coordinate.imag=P_coordinate->length*sin(P_coordinate->radian);
    return C_coordinate;
}
#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
