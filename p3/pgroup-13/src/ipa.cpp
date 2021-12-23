#include "car.h"
#include "drawlot.h"
#include "UFO.h"
#include "spacecraft.h"
#include "teleported.h"
using namespace std;
#define PI 3.1415926535
void TimeStep(int n) 
{
    glutTimerFunc(n, TimeStep, n);
    glutPostRedisplay();
}
//the OpenGL timer function
void glDraw() 
{
    Vec r1(-0.9,-0.9),r2(-0.6,-0.9),r3(-0.6,-0.6),r4(-0.9,-0.6);
    static quadrangle blank(r1,r2,r3,r4,0,0,0);
    bool static parked1=false,parked2=false,parked3=false,parked4=false,parked5=false,parked6=false;
    double static w1=0.2,h1=0.3;
    Vec static initpos(-0.75,-0.75);
    Vec up(0,0.01),down(0,-0.01),right(0.01,0),left(-0.01,0);
    static car c1(initpos);
    static car c2(initpos);
    static rocket rock1(initpos,w1,h1);
    static rocket rock2(initpos,w1,h1);
    static UFO ufo1(initpos);
    static UFO ufo2(initpos);
    Vec p1(-0.18,-0.78);
    Vec p2(-0.18,-0.52);
    Vec p3(-0.02,-0.52);
    Vec p4(-0.02,-0.78);
    static telequadrangle t1(p1,p2,p3,p4,0,0,0);
    Vec p5(-0.38,0.78);
    Vec p6(-0.38,0.52);
    Vec p7(-0.22,0.52);
    Vec p8(-0.22,0.78);
    static telequadrangle t2(p5,p6,p7,p8,0,0,0);
    Vec p9(0.38,0.78);
    Vec p10(0.38,0.52);
    Vec p11(0.22,0.52);
    Vec p12(0.22,0.78);
    static telequadrangle t3(p9,p10,p11,p12,0,0,0);

    if (!parked1){
        static int f1=0,f2=0,f3=0;
    if (c1.getAnchor().getY()<=-0.5 && f1==0)
    {
        c1.move(up);
    }
    else 
    {
        f1=1;
    }
    if (f1==1)
    {
        if (c1.getAngle()<0 && f3==0)
        {
            Vec turn1(-0.6,-0.5);
            c1.rotate(turn1,0.03);
        }
        else 
        {
        f3=1;
        if (c1.getAnchor().getX()<-0.2 && f2==0)
        {
            c1.move(right);
        }
        else
        {
            f2=1;
        }
        if (f2==1)
        {
            Vec back1(-0.2,-0.65);
            if (c1.getAngle()>-1.57)
                c1.rotate(back1,-0.03);
            else
                parked1=true;
        }
        }
    }
    }
    else if (!parked3){

        static int f7=0,f8=0,f9=0;
            if (ufo1.getAnchor().getY()<=-0.4 && f7==0)
    {
        ufo1.move(up);
    }
    else 
    {
        f7=1;
    }
    if (f7==1)
    {
        if (ufo1.getAngle()<0 && f9==0)
        {
            Vec turn1(-0.6,-0.4);
            ufo1.rotate(turn1,0.03);
        }
        else 
        {
        f9=1;
        if (ufo1.getAnchor().getX()<-0.05 && f8==0)
        {
            ufo1.move(right);
        }
        else
        {
            f8=1;
        }
        if (f8==1)
        {
            Vec back1(-0.05,-0.65);
            if (ufo1.getAngle()>-1.57)
                ufo1.rotate(back1,-0.03);
            else
                parked3=true;
        }
        }
    }
    }

    else if (!parked4){

        static int f10=0,f11=0,f12=0;
            if (rock1.getAnchor().getY()<=-0.5 && f10==0)
    {
        rock1.move(up);
    }
    else 
    {
        f10=1;
    }
    if (f10==1)
    {
        if (rock1.getAngle()<1.57 && f12==0)
        {
            Vec turn1(-0.6,-0.5);
            rock1.rotate(turn1,0.03);
        }
        else 
        {
        f12=1;
        if (rock1.getAnchor().getX()<0.8 && f11==0)
        {
            rock1.move(right);
        }
        else
        {
            f11=1;

        }
        if (f11==1)
        {
            Vec back1(0.8,-0.65);
            if (rock1.getAngle()>0)
                rock1.rotate(back1,-0.03);
            else
                parked4=true;
        }
        }
    }
    }
     else if (!parked2){

        static int f4=0,f5=0,f6=0;
            if (c2.getAnchor().getY()<=-0.5 && f4==0)
    {
        c2.move(up);
    }
    else 
    {
        f4=1;
    }
    if (f4==1)
    {
        if (c2.getAngle()<0 && f6==0)
        {
            Vec turn1(-0.6,-0.5);
            c2.rotate(turn1,0.03);
        }
        else 
        {
        f6=1;
        if (c2.getAnchor().getX()<0.4 && f5==0)
        {
            c2.move(right);
        }
        else
        {
            f5=1;
        }
        if (f5==1)
        {
            Vec back1(0.4,-0.65);
            if (c2.getAngle()>-1.57)
                c2.rotate(back1,-0.03);
            else
                parked2=true;
        }
        }
    }
    }
    else if (!parked5)
    {
        static int f13=0,f14=0,f15=0,f16=0;
        if (ufo2.getAnchor().getY()<=-0.4 && f13==0)
        {
            ufo2.move(up);
        }
    else 
    {
        f13=1;
    }
    if (f13==1)
    {
        if (ufo2.getAngle()<0 && f15==0)
        {
            Vec turn1(-0.6,-0.4);
            ufo2.rotate(turn1,0.03);
        }
        else 
        {
        f15=1;
        if (ufo2.getAnchor().getX()<0.3 && f14==0)
        {
            ufo2.move(right);
        }
        else
        {
            f14=1;

        }
        if (f14==1)
        {
            Vec turn2(0.3,0);
            if (ufo2.getAngle()>-3.14 && f16==0)
                ufo2.rotate(turn2,-0.03);
            else
                f16=1;
            if (f16==1)
            {
                Vec back1(0.25,0.65);
                if (ufo2.getAngle()>-4.71)
                    ufo2.rotate(back1,-0.03);
                else
                    parked5=true;
            }
        }
        }
    }
    }
    else if (!parked6)
    {
        static int f17=0,f18=0,f19=0,f20=0,f21=0;
        if (rock2.getAnchor().getY()<=-0.5 && f17==0)
        {
            rock2.move(up);
        }
    else 
    {
        f17=1;
    }
    if (f17==1)
    {
        if (rock2.getAngle()<1.57 && f19==0)
        {
            Vec turn1(-0.6,-0.5);
            rock2.rotate(turn1,0.03);
        }
        else 
        {
        f19=1;
        if (rock2.getAnchor().getX()<0.3 && f18==0)
        {
            rock2.move(right);
        }
        else
        {
            f18=1;

        }
        if (f18==1)
        {
            Vec turn2(0.3,0);
            if (rock2.getAngle()>-1.57 && f20==0)
                rock2.rotate(turn2,-0.03);
            else
                f20=1;
            if (f20==1)
            {
                if (rock2.getAnchor().getX()>-0.2 && f21==0)
                    rock2.move(left);
                else
                    f21=1;
                if (f21==1)
                {
                Vec back1(-0.2,0.65);
                if (rock2.getAngle()>-3.14)
                    rock2.rotate(back1,-0.03);
                else
                {
                        parked6=true;
                        return;
                }
                }
            }
        }
        }
    }
    }
    t1.paint();t2.paint();t3.paint(); 
    rock1.zoom(&w1,&h1);rock2.zoom(&w1,&h1);
    ufo1.autorotation();ufo2.autorotation();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    c1.draw();c2.draw();
    rock1.draw();rock2.draw();
    ufo1.draw();ufo2.draw();
    blank.draw();t1.draw();t2.draw();t3.draw();
    //u.draw();
    drawlot();
    glutSwapBuffers(); glFlush();
}
//the main loop of drawing
int main (int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Project 3");
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw); 
    glutTimerFunc(25, TimeStep, 25);
    glutMainLoop();
    return 0;
}
