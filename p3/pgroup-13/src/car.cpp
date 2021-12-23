//
// Created by 李卓恒 lizhuoheng 521370910132 on 2021/12/10.
//
/*
This part is the generation, movement of the car
*/
#include<cmath>
#include"car.h"
#include"vec.h"
#define PI 3.1415926535
using namespace std;
void car::rot90()
{
    for (int i=0;i<4;i++)
        sh[i]->rotate(anchor,-PI/2);
    ang-=PI/2;
}
car::car(Vec anc)
//anc for the central point of the car
{
    anchor=anc;
    float r,g,b;
    Vec p;
    p=anc;
    srand((unsigned)time(NULL));
    Vec p1(p.getX()-0.15,p.getY()+0.035);
    Vec p2(p.getX()+0.15,p.getY()+0.035);
    Vec p3(p.getX()+0.15,p.getY()-0.035);
    Vec p4(p.getX()+-0.15,p.getY()-0.035);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[0]=new quadrangle(p1,p2,p3,p4,r,g,b);

    Vec p5(p.getX()-0.1,p.getX()-0.035);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[1]=new circle(p5,0.03,r,g,b);

    Vec p6(p.getX()+0.1,p.getY()-0.035);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[2]=new circle(p6,0.03,r,g,b);

    Vec p7(p.getX()-0.15,p.getY()+0.075);
    Vec p8(p.getX()+0.025,p.getY()+0.075);
    Vec p9(p.getX()+0.1,p.getY()+0.035);
    Vec p10(p.getX()-0.15,p.getY()+0.035);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[3]=new quadrangle(p7,p8,p9,p10,r,g,b);
    rot90();
}
//constructor of the car
car::~car()
{
    for (int i=0;i<4;i++)
        delete sh[i];
}
//destructor of the car
void car::draw()
{
    for (int i=0;i<4;i++)
        sh[i]->draw();
}
//the drawing of the car(consists of four figures)
void car::move(Vec dir)
{
    for (int i=0;i<4;i++)
        sh[i]->move(dir);
    anchor=anchor+dir;
    //cout<<anchor.getX()<<"   "<<anchor.getY()<<endl;
    //*pos=anchor;
}
//the movement of the car(move the four figures together)
void car::rotate(Vec v,double angle)
{
    for (int i=0;i<4;i++)
        sh[i]->rotate(v,angle);
    anchor=((anchor-v)>>angle)+v;
    ang+=angle;
}
//the rotation of the car(rotate the four figures together)

