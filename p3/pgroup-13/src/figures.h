//
// Created by 李卓恒 lizhuoheng 521370910132 on 2021/12/10.
//
#ifndef __FIGURES_H__
#define __FIGURES_H__
#include "vec.h"
class shape
{
    public:
        virtual void draw()=0;
        virtual ~shape()=0;
        virtual void move(Vec dir)=0;
        virtual void rotate(Vec v,double angle)=0;
    protected:
        float r,g,b;
};
class circle : public shape
{
    public :
        circle(Vec pot,double radius=0.1,float r=1,float g=0,float b=0);
        void draw();
        void move(Vec dir);
        void rotate(Vec v,double angle);
    private: 
        Vec pt;
        double radius;
};
class quadrangle : public shape
{
    public :
        quadrangle(Vec pt1,Vec pt2,Vec pt3,Vec pt4,float r=1,float g=0,float b=0);
        void draw();
        void move(Vec dir);
        void rotate(Vec v,double angle);
    private:
        Vec p1,p2,p3,p4;
};
 
class line
{
    public:
        line(Vec pt1,Vec pt2);
        void draw();
    private:
        Vec p1,p2;
};
#endif
