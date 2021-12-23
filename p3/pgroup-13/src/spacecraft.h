#ifndef __SPACECRAFT_H__
#define __SPACECRAFT_H__
#include "figures.h"

class rocket
{
    public:
        rocket(Vec anc, double width, double height);
        ~rocket();
        Vec getAnchor()
        {
            return anchor;
        }
        void setAnchor(Vec a)
        {
            anchor = a;
        }
        double getAngle()
        {
            return ang;
        }
        void draw();
        void move(Vec dir);
        void rotate(Vec v, double angle);
        void zoom(double *width, double *height);
    private:
        double w, h;
        Vec anchor;
        double ang;
        shape *sh[5];
        void zoomin(double *width, double *height);
        void zoomout(double *width, double *height);
};

#endif