#include "homework.h"
#include <iostream>
using namespace std;
static const char GRADES[12] = {'F','F','F','F','F','F','D','C','B','A','A'};
class Grade{
    public:
        Grade();
        ~Grade();
        void GradePrct(int prct_);
        void GradeLtr(char ltr_);
        void printGrade();
    private:
        int prct;
        char ltr;
};
void ex5(){
    //Write code for exercise 5
    Grade g;
    int prct;char ltr;
    cout<<"Input two space seprated grades (1st in %%, 2nd in letter): ";
    scanf("%d", &prct);
    scanf("\n");
    g.GradePrct(prct);
    g.printGrade();
    ltr=(char)getchar();
    g.GradeLtr(ltr);
    g.printGrade();
}
Grade::Grade(){
    prct=0;ltr='F';
}
void Grade::GradeLtr(char ltr_){
    ltr=ltr_;prct=100 - (ltr - 'A') * 10 - 5;
}
void Grade::GradePrct(int prct_){
    prct=prct_;ltr=GRADES[prct / 10];
}
void Grade::printGrade(){
    cout<<"Grade: "<<Grade::prct<<" -> "<<Grade::ltr<<endl;
}
Grade::~Grade(){};
#ifdef JOJ
int main(){
    ex5();
    return 0;
}
#endif
