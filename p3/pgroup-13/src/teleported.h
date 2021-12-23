#ifndef __TELEPORTED_H__
#define __TELEPORTED_H__
#include "vec.h"
class telequadrangle
{
    public :
        telequadrangle(Vec pt1,Vec pt2,Vec pt3,Vec pt4,float rt,float gt,float bt);
        ~telequadrangle(){};
        void draw();
        void paint();
    private:
        Vec p1,p2,p3,p4;
        float r,g,b;
};

#endif
