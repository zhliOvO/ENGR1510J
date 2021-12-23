#include "homework.h"
#include <iostream>
#include <iomanip>
using namespace std;
int count(int input);
void ex2(){
    //Write code for exercise 2
    int choice=0,precision=0;
    double amount=0;
    cin>>choice>>amount>>precision;
    if(choice==1){
        cout<<setprecision(precision)<<showpoint<<amount*6.20350<<endl;
    }
    else if(choice==2){
        cout<<setprecision(precision)<<showpoint<<amount/6.20350<<endl;
    }
    else{
        cout<<"no such option"<<endl;
    }
}

#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
