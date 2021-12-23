//
// Created by 张乐岩 zhagnleyan 521370910040 on 2021/12/17.
//
/*
This part is the generation, movement of the car
*/
#include <cmath>
#include "vehicle.h"
#include "UFO.h"
#include "vec.h"
#define PI 3.1415926535
using namespace std;

UFO::UFO(Vec anc)
// anc for the central point of the car
{
    anchor = anc;
    Vec p1, p2, p3, p4;
    float r, g, b;
    Vec p;
    p = anc;
    p1 = {p.getX() - 0.08, p.getY() - 0.01};
    p2 = {p.getX() - 0.04, p.getY() - 0.01};
    p3 = {p.getX() - 0.04, p.getY()};
    p4 = {p.getX() - 0.08, p.getY()};
    r = 0.3;
    g = 0.9f;
    b = 0.2f;
    sh[0] = new quadrangle(p1, p2, p3, p4, r, g, b);

    Vec p5, p6, p7, p8;
    p5 = {p.getX() + 0.04, p.getY() - 0.01};
    p6 = {p.getX() + 0.08, p.getY() - 0.01};
    p7 = {p.getX() + 0.08, p.getY()};
    p8 = {p.getX() + 0.04, p.getY()};
    r = 0.4;
    g = 0.1f;
    b = 0.7f;
    sh[1] = new quadrangle(p5, p6, p7, p8, r, g, b);

    Vec p9;
    p9 = {p.getX(), p.getY()};
    r = 0.7;
    g = 0.4f;
    b = 0.8f;
    sh[2] = new halfcircle(p9, 0.08, r, g, b);

    Vec p10, p11;
    p10 = {p.getX() - 0.048, p.getY() + 0.064};
    p11 = {p.getX() - 0.060, p.getY() + 0.080};
    r = 1;
    g = 0.5f;
    b = 0.4f;
    sh[3] = new uline(p10, p11, r, g, b);

    Vec p12, p13;
    p12 = {p.getX() + 0.048, p.getY() + 0.064};
    p13 = {p.getX() + 0.060, p.getY() + 0.080};
    r = 0.66;
    g = 0.4f;
    b = 0.7f;
    sh[4] = new uline(p12, p13, r, g, b);
}
// constructor of the car
UFO::~UFO()
{
    for (int i = 0; i < 5; i++)
        delete sh[i];
}
// destructor of the car
void UFO::draw()
{
    for (int i = 0; i < 5; i++)
        sh[i]->draw();
}
// the drawing of the car(consists of four figures)
void UFO::move(Vec dir)
{
    for (int i = 0; i < 5; i++)
        sh[i]->move(dir);
    anchor = anchor + dir;
    // cout<<anchor.getX()<<"   "<<anchor.getY()<<endl;
    //*pos=anchor;
}
// the movement of the car(move the four figures together)
void UFO::rotate(Vec v, double angle)
{
    for (int i = 0; i < 5; i++)
        sh[i]->rotate(v, angle);
    anchor = ((anchor - v) >> angle) + v;
    ang += angle;
}
//
void UFO ::autorotation()
{
    int static flag = 0;
    int static autoangle = 0;
    if (autoangle >= -0.5 && flag == 0)
    {
        for (int i = 0; i < 5; i++)
            sh[i]->rotate(anchor, -0.05);

        autoangle -= 0.05;
    }
    else if (autoangle <= 0.5)
    {
        flag = 1;
        for (int i = 0; i < 5; i++)
            sh[i]->rotate(anchor, +0.05);

        autoangle += 0.05;
    }
    else
        flag = 0;
}
// the rotation of the car(rotate the four figures together)

halfcircle::halfcircle(Vec pot, double rad, float re, float gr, float bl)
{
    pt = pot;
    radius = rad;
    r = re;
    g = gr;
    b = bl;
}
//
void halfcircle::draw()
{
    const int n = 300;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < (n / 2); i++)
    {
        Vec temp;
        temp = {pt.getX() + radius * cos(2 * PI * i / n - spinangle), pt.getY() + radius * sin(2 * PI * i / n - spinangle)};
        glVertex2f(temp.getX(), temp.getY());
    }
    glEnd();
}
//
void halfcircle::rotate(Vec v, double angle)
{
    pt = ((pt - v) >> angle) + v;
    spinangle += angle;
}
//
void halfcircle::move(Vec dir)
{
    pt = pt + dir;
}
//
uline::uline(Vec pt1, Vec pt2, float re, float gr, float bl)
{
    p1 = pt1;
    p2 = pt2;
    r = re;
    g = gr;
    b = bl;
}
//
void uline ::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_LINES);
    glVertex2d(p1.getX(), p1.getY());
    glVertex2d(p2.getX(), p2.getY());
    glEnd();
}
//
void uline::rotate(Vec v, double angle)
{
    p1 = ((p1 - v) >> angle) + v;
    p2 = ((p2 - v) >> angle) + v;
}
//
void uline ::move(Vec dir)
{
    p1 = p1 + dir;
    p2 = p2 + dir;
}