//
// Created by 李卓恒 lizhuoheng 521370910132 on 2021/12/10.
//
/*
This part is the drawing, movement and rotation of basic figures
*/
#include "vehicle.h"
#include<cmath>
#include"figures.h"
shape::~shape(){}
//destructor of shape
quadrangle::quadrangle(Vec pt1,Vec pt2,Vec pt3,Vec pt4,float re,float gr,float bl)
{
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
    r=re;g=gr;b=bl;
}
//constructor of quadrangle
circle::circle(Vec pot,double rad,float re,float gr,float bl)
{
    pt=pot;radius=rad;
    r=re;g=gr;b=bl;
}
//constructor of circle

void quadrangle::draw()
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2d(p1.getX(), p1.getY()); glVertex2d(p2.getX(), p2.getY());
    glVertex2d(p3.getX(), p3.getY()); glVertex2d(p4.getX(), p4.getY()); 
    glEnd();
}
//the drawing of the quadrangle

void circle::draw()
{
    const int n = 300; 
    const float PI = 3.1415926f;
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2f(pt.getX()+radius*cos(2*PI*i/n), pt.getY()+radius*sin(2*PI*i/n));   
    glEnd();
}
//the drawing of the circle

void quadrangle::move(Vec dir)
{
    p1=p1+dir;
    p2=p2+dir;
    p3=p3+dir;
    p4=p4+dir;
}
//movement of quadrangle(move the four points together)

void circle::move(Vec dir)
{
    pt=pt+dir;
}
//movement of circle(move the center of the circle)

void quadrangle::rotate(Vec v,double angle)
{
    p1=((p1-v)>>angle)+v;
    p2=((p2-v)>>angle)+v;
    p3=((p3-v)>>angle)+v;
    p4=((p4-v)>>angle)+v;
}
//rotation of quadrangle(rotate the four points togetherf)

void circle::rotate(Vec v,double angle)
{
    pt=((pt-v)>>angle)+v;
}
//rotation of circle(rotate the center of the circle)

line::line(Vec pt1,Vec pt2)
{
    p1=pt1;p2=pt2;
}
void line::draw()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES); 
    glVertex2d(p1.getX(), p1.getY()); 
    glVertex2d(p2.getX(), p2.getY());
    glEnd();
}