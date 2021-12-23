#include "Shapes.h"
#include<GL/glut.h>
#include<cmath>
#define PI 3.1415926535
Line::Line(Point pt1,Point pt2,Color cl)
{
    p1=pt1;p2=pt2;
    c=cl;
}
void Line ::draw()
{
    glColor3f(c.r,c.g,c.b);
    glBegin(GL_LINES); 
    glVertex2d(p1.x, p1.y); 
    glVertex2d(p2.x, p2.y);
    glEnd();
}
void Line::rotate(Point pt,double ang)
{
    p1.x=pt.x+(p1.x-pt.x)*cos(ang)-(p1.y-pt.y)*sin(ang);
    p2.x=pt.x+(p2.x-pt.x)*cos(ang)-(p2.y-pt.y)*sin(ang);
    p1.y=pt.y+(p1.x-pt.x)*sin(ang)+(p1.y-pt.y)*cos(ang);
    p2.y=pt.y+(p2.x-pt.x)*sin(ang)+(p2.y-pt.y)*cos(ang);
}
void Line ::move(double dx,double dy)
{
    p1.x+=dx;
    p2.x+=dx;
    p1.y+=dy;
    p2.y+=dy;
}
void Line::zoom(Point pt,double k)
{
    p1.x=pt.x+(p1.x-pt.x)*k;
    p1.y=pt.y+(p1.y-pt.y)*k;
    p2.x=pt.x+(p2.x-pt.x)*k;
    p2.y=pt.y+(p2.y-pt.y)*k;
}
Triangle::Triangle(Point pt1, Point pt2, Point pt3, Color cl)
{
    p1=pt1; p2=pt2; p3=pt3; 
    c = cl;
}
void Triangle::zoom(Point pt,double k)
{
    p1.x=pt.x+(p1.x-pt.x)*k;
    p1.y=pt.y+(p1.y-pt.y)*k;
    p2.x=pt.x+(p2.x-pt.x)*k;
    p2.y=pt.y+(p2.y-pt.y)*k;
    p3.x=pt.x+(p3.x-pt.x)*k;
    p3.y=pt.y+(p3.y-pt.y)*k;
}
void Triangle::rotate(Point pt,double ang)
{
    p1.x=pt.x+(p1.x-pt.x)*cos(ang)-(p1.y-pt.y)*sin(ang);
    p2.x=pt.x+(p2.x-pt.x)*cos(ang)-(p2.y-pt.y)*sin(ang);
    p1.y=pt.y+(p1.x-pt.x)*sin(ang)+(p1.y-pt.y)*cos(ang);
    p2.y=pt.y+(p2.x-pt.x)*sin(ang)+(p2.y-pt.y)*cos(ang);
    p3.x=pt.x+(p3.x-pt.x)*cos(ang)-(p3.y-pt.y)*sin(ang);
    p3.y=pt.y+(p3.x-pt.x)*sin(ang)+(p3.y-pt.y)*cos(ang);
}
void Triangle:: draw()
{
    glColor3f(c.r,c.g,c.b);
    glBegin(GL_TRIANGLE_STRIP); 
    glVertex2d(p1.x, p1.y); 
    glVertex2d(p2.x, p2.y);
    glVertex2d(p3.x, p3.y); 
    glEnd();
}

void Triangle::move(double dx,double dy)
{
    p1.x+=dx;
    p2.x+=dx;
    p3.x+=dx;
    p1.y+=dy;
    p2.y+=dy;
    p3.y+=dy;
}


Quadrangle::Quadrangle(Point pt1, Point pt2,Point pt3, Point pt4, Color cl) 
{ 
    p1=pt1; p2=pt2; p3=pt3;p4=pt4;c = cl;
} 


void Quadrangle::draw() { 
    glColor3f(c.r,c.g,c.b); 
    glBegin(GL_QUADS); 
    glVertex2d(p1.x, p1.y); 
    glVertex2d(p2.x, p2.y); 
    glVertex2d(p3.x, p3.y); 
    glVertex2d(p4.x, p4.y); 
    glEnd();
}
void Quadrangle::zoom(Point pt,double k)
{
    p1.x=pt.x+(p1.x-pt.x)*k;
    p1.y=pt.y+(p1.y-pt.y)*k;
    p2.x=pt.x+(p2.x-pt.x)*k;
    p2.y=pt.y+(p2.y-pt.y)*k;
    p3.x=pt.x+(p3.x-pt.x)*k;
    p3.y=pt.y+(p3.y-pt.y)*k;
    p4.x=pt.x+(p4.x-pt.x)*k;
    p4.y=pt.y+(p4.y-pt.y)*k;
}
void Quadrangle::rotate(Point pt,double ang)
{
    p1.x=pt.x+(p1.x-pt.x)*cos(ang)-(p1.y-pt.y)*sin(ang);
    p2.x=pt.x+(p2.x-pt.x)*cos(ang)-(p2.y-pt.y)*sin(ang);
    p1.y=pt.y+(p1.x-pt.x)*sin(ang)+(p1.y-pt.y)*cos(ang);
    p2.y=pt.y+(p2.x-pt.x)*sin(ang)+(p2.y-pt.y)*cos(ang);
    p3.x=pt.x+(p3.x-pt.x)*cos(ang)-(p3.y-pt.y)*sin(ang);
    p3.y=pt.y+(p3.x-pt.x)*sin(ang)+(p3.y-pt.y)*cos(ang);
    p4.x=pt.x+(p4.x-pt.x)*cos(ang)-(p4.y-pt.y)*sin(ang);
    p4.y=pt.y+(p4.x-pt.x)*sin(ang)+(p4.y-pt.y)*cos(ang);
}
void Quadrangle::move(double dx,double dy)
{
    p1.x+=dx;
    p2.x+=dx;
    p3.x+=dx;
    p4.x+=dx;
    p1.y+=dy;
    p2.y+=dy;
    p3.y+=dy;
    p4.y+=dy;
}

Circle:: Circle(Point pt, float radius, Color cl){
    p = pt;
    r = radius;
    c = cl;
}


void Circle:: draw(){
    glColor3f(c.r,c.g,c.b); 
    glBegin(GL_TRIANGLE_FAN);
	glVertex2d(p.x, p.y); // center of circle
    int n = 300;
	for(int i = 0; i <= n;i++) 
    { 
		glVertex2d(
		    p.x + (r * cos(i *2 * PI / n)), 
			p.y + (r * sin(i * 2 * PI / n))
		);
	}
	glEnd();
}
void Circle::zoom(Point pt,double k)
{
    Point ff;
    ff=pt;
    ff.x=ff.x*2;
    r=r*k;
}
void Circle::move(double dx,double dy)
{
    p.x+=dx;
    p.y+=dy;
}
void Circle::rotate(Point pt,double ang)
{
    p.x=pt.x+(p.x-pt.x)*cos(ang)-(p.y-pt.y)*sin(ang);
    p.y=pt.y+(p.x-pt.x)*sin(ang)+(p.y-pt.y)*cos(ang);
}
