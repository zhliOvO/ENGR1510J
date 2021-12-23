#ifndef __UFO_H__
#define __UFO_H__
#include "figures.h"
class UFO
{
    public:
        UFO(Vec anchor);
        ~UFO();
        Vec getAnchor() 
            {return anchor;}
        void setAnchor(Vec a) 
            {anchor = a;}
        double getAngle()
            {return ang;}
        void draw();
        void move(Vec dir);
        void rotate(Vec v,double angle);
        void autorotation();
        void zoom(double k);
    private:
        Vec anchor;
        double ang;
        double autoangle;
        shape *sh[5];
};

class halfcircle : public shape
{
    public :
        halfcircle(Vec pot,double radius=0.1,float r=1,float g=0,float b=0);
        void draw();
        void move(Vec dir);
        void rotate(Vec v,double angle);
    private: 
        Vec pt;
        double radius;
        double spinangle;
};

class uline : public shape
{
    public:
        uline(Vec pt1,Vec pt2,float re,float gr,float bl);
        void draw();
        void move(Vec dir);
        void zoom(Vec pt,double k);
        void rotate(Vec pt,double angle);
    private:
        Vec p1,p2;
};
#endif
