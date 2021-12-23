#include "homework.h"
#include <iostream>
using namespace std;
void ex1(){
    //Write code for exercise 1
    int curryear=0,age=0,year=0;
    cin>>curryear>>age>>year;
    cout<<year-curryear+age<<endl;
}

#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
