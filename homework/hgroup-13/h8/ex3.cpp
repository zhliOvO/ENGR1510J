#include "homework.h"
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
#include <ctime>
static const double PI=3.1415;
void glDraw();
void TimeStep(int n){
    glutTimerFunc((unsigned int)n,TimeStep,n);glutPostRedisplay();
}
typedef struct _point{
    double x,y;
} point;
class shape{
public:
    virtual void draw()=0;
    virtual ~shape()=0;
    void paint();
protected:
    float r,g,b;
};
class quads:public shape{
public:
    quads(point pt1,point pt2,point pt3,point pt4);
    void draw();
private:
    point p1,p2,p3,p4;
};
class circle:public shape{
public:
    circle(point origin,double radius);
    void draw();
private:
    point o;double r;
};
class car{
public:
    car(point o);
    ~car();
    point* getpoint();
    void draw();
    void move(point* origin);
private:
    shape* sh[4];
    point origin;
    double height,width;
};
void ex3(){
    //Write code for exercise 3
}
shape::~shape(){}
void shape::paint(){
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}
quads::quads(point pt1,point pt2,point pt3,point pt4){
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
    paint();
}
void quads::draw(){
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);
    glVertex2d(p3.x,p3.y);glVertex2d(p4.x,p4.y);glEnd();
}
circle::circle(point origin,double radius){
    o=origin;r=radius;
    paint();
}
void circle::draw(){
    point pt[100];
    for(int i=0;i<100;i++){
        double angle=(double)i/(double)50*PI;
        pt[i].x=o.x+r*cos(angle);pt[i].y=o.y+r*sin(angle);
    }
    glColor3f((GLfloat)r,g,b);
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++){
        glVertex2d(pt[i].x,pt[i].y);
    }
    glEnd();
}
car::car(point o){
    origin=o;height=0.35;width=0.6;
    point p1,p2,p3,p4;
    p1=origin;p2={origin.x+0.6,0};p3={origin.x+0.6,-0.15};p4={origin.x,-0.15};
    sh[0]=new quads(p1,p2,p3,p4);
    p2={origin.x+0.03,0.13};p3={origin.x+0.4,0.13};p4={origin.x+0.45,0};
    sh[1]=new quads(p1,p2,p3,p4);
    p1={origin.x+0.15,-0.15};p2={origin.x+0.45,-0.15};
    sh[2]=new circle(p1,0.05);
    sh[3]=new circle(p2,0.05);
}
car::~car(){
    for(int i=0;i<4;i++){delete sh[i];}
}
void car::draw(){
    for(int i=0;i<4;i++){
        sh[i]->draw();
    }
}
point* car::getpoint(){
    return &origin;
}
void car::move(point* origin){
    int static flag=0;
    if(origin->x<=0.5 && flag==0){origin->x+=0.01;}
    else if(origin->x>=-0.5){flag=1;origin->x-=0.01;}
    else flag=0;
}
void glDraw(){
    static point o={-0.5,0};
    car a(o);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    a.draw();a.move(&o);
    glutSwapBuffers();glFlush();
}
#ifdef JOJ
int main(int argc,char* argv[]){
    srand((unsigned int)time(NULL));
    ex3();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("a");
    glClearColor(1.0,1.0,1.0,0.0);glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);glutTimerFunc(25,TimeStep,25);
    glutMainLoop();
    return 0;
}
#endif
