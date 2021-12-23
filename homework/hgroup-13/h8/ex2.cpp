#include "homework.h"
#include <GL/glut.h>
#include <GL/gl.h>
typedef struct _point{
    double x,y; 
} point;
void glDraw();
void TimeStep(int n){
    glutTimerFunc((unsigned int)n,TimeStep,n);glutPostRedisplay();
}
class trapezium{
    public:
    trapezium(point pt1={0,0},point pt2={1,0},point pt3={1,1},point pt4={0,1});
    ~trapezium();
    void draw();
    protected:
        point p1,p2,p3,p4;
        float r,g,b;
};
class parallelogram : public trapezium{
    public:
    parallelogram(point pt1={0,0},point pt2={1,0},point pt3={1,1},point pt4={0,1});
    ~parallelogram();
};
class rectangle :public parallelogram{
    public:
    rectangle(point pt1={0,0},point pt2={1,0},point pt3={1,1},point pt4={0,1});
    ~rectangle();
};
class triangle{
    public:
    triangle(point pt1={0,0},point pt2={1,1},point pt3={1,0});
    ~triangle();
    void draw();
    private:
    point p1,p2,p3;
    float r,g,b;
};
void ex2(){
    //Write code for exercise 2

}
trapezium::trapezium(point pt1,point pt2,point pt3,point pt4){
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}
trapezium::~trapezium(){}
parallelogram::parallelogram(point pt1,point pt2,point pt3,point pt4){
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}
parallelogram::~parallelogram(){}
rectangle::rectangle(point pt1,point pt2,point pt3,point pt4){
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}
rectangle::~rectangle(){}

void trapezium::draw(){
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);
    glVertex2d(p3.x,p3.y);glVertex2d(p4.x,p4.y);glEnd();
}
triangle::triangle(point pt1,point pt2,point pt3){
    p1=pt1;p2=pt2;p3=pt3;
    r=(float)rand()/(float)RAND_MAX;
    g=(float)rand()/(float)RAND_MAX;
    b=(float)rand()/(float)RAND_MAX;
}
triangle::~triangle(){}
void triangle::draw(){
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);
    glVertex2d(p3.x,p3.y);glEnd();
}
void glDraw(){
    trapezium a;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    a.draw();glutSwapBuffers();glFlush();
}
#ifdef JOJ
int main(int argc,char* argv[]){
    ex2();
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
