#include <stdio.h>
#include <cmath>
#include "spacecraft.h"
#define PI 3.1415926535
using namespace std;

// slot: 0.2*0.3

class triangle : public shape
{
    public:
        triangle(Vec pt1, Vec pt2, Vec pt3, float red, float green, float blue);
        void draw();
        void move(Vec dir);
        void rotate(Vec v, double angle);
    private:
        Vec p1, p2, p3;
};

triangle::triangle(Vec pt1, Vec pt2, Vec pt3, float red, float green, float blue)
{
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
    r = red;
    g = green;
    b = blue;
}

void triangle::draw()
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2d(p1.getX(), p1.getY());
    glVertex2d(p2.getX(), p2.getY());
    glVertex2d(p3.getX(), p3.getY());
    glEnd();
}

void triangle::move(Vec dir)
{
    p1 = p1 + dir;
    p2 = p2 + dir;
    p3 = p3 + dir;
}

void triangle::rotate(Vec v, double angle)
{
    p1 = ( (p1 - v) >> angle ) + v;
    p2 = ( (p2 - v) >> angle ) + v;
    p3 = ( (p3 - v) >> angle ) + v;
}

rocket::rocket(Vec anc, double width, double height)
{
    float r, g, b;
    Vec p;
    anchor=anc;
    /* initialization */

    p = anc;
    w = width;
    h = height;

    /* Top */

    Vec p1(p.getX() - 0.3*w, p.getY() + 0.3333*h);
    Vec p2(p.getX(), p.getY() + 0.5*h);
    Vec p3(p.getX() + 0.3*w, p.getY() + 0.3333*h);
    srand((unsigned)time(NULL));
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[0] = new triangle(p1, p2, p3, r, g, b);

    /* Body */

    Vec p4(p.getX() + 0.3*w, p.getY() - 0.3333*h);
    Vec p5(p.getX() - 0.3*w, p.getY() - 0.3333*h);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[1] = new quadrangle(p1, p3, p4, p5, r, g, b);

    /* Tail */

    Vec p6(p.getX() - 0.3*w, p.getY());
    Vec p7(p.getX() - 0.5*w, p.getY() - 0.3333*h);
    Vec p8(p.getX() + 0.3*w, p.getY());
    Vec p9(p.getX() + 0.5*w, p.getY() - 0.3333*h);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[2] = new triangle(p5, p6, p7, r, g, b);
    sh[3] = new triangle(p4, p8, p9, r, g, b);

    Vec p10(p.getX() - 0.4*w, p.getY() - 0.5*h);
    Vec p11(p.getX() + 0.4*w, p.getY() - 0.5*h);
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
    sh[4] = new quadrangle(p4, p5, p10, p11, r, g, b);
    
    ang=0;
    /* Windows */
}

rocket::~rocket()
{
    int i;
    
    for (i = 0; i < 5; i++)
    {
        delete sh[i];
    }
}

void rocket::draw()
{
    int i;

    for (i = 0; i < 5; i++)
    {
        sh[i]->draw();
    }
}

void rocket::move(Vec dir)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        sh[i]->move(dir);
    }

    anchor = anchor + dir;

}

void rocket::rotate(Vec v, double angle)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        sh[i]->rotate(v, angle);
    }

    anchor = ( (anchor - v) >> angle ) + v;
    ang += angle;
}

void rocket::zoom(double *width, double *height)
{
    int static flag = 0;
    
    if(h >= 0.1 && flag == 0)
    {
        zoomout(width, height);
    }
    else if (h <= 0.31)
    {
        flag = 1;
        zoomin(width, height);
    }
    else
    {
        flag = 0;
    }
}

void rocket::zoomin(double *width, double *height)
{
    h *= 1.05;
    *height = h;
    w *= 1.05;
    *width = w;
}

void rocket::zoomout(double *width, double *height)
{
    h /= 1.05;
    *height = h;
    w /= 1.05;
    *width = w;
}