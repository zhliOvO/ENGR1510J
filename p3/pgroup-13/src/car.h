#ifndef __CAR_H__
#define __CAR_H__
#include "figures.h"
class car
{
    public:
        car(Vec anchor);
        ~car();
        Vec getAnchor() 
            {return anchor;}
        void setAnchor(Vec a) 
            {anchor = a;}
        double getAngle()
            {return ang;}
        void draw();
        void move(Vec dir);
        void rotate(Vec v,double angle);
        void zoom(double k);
        void rot90();
    private:
        Vec anchor;
        double ang;
        shape *sh[4];
};
#endif
