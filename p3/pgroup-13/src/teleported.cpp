#include "teleported.h"
#include <ctime>
#include <cstdlib>

telequadrangle::telequadrangle(Vec pt1, Vec pt2, Vec pt3, Vec pt4, float rt, float gt, float bt)
{
    p1=pt1;
    p2=pt2;
    p3=pt3;
    p4=pt4;
    r=rt;
    g=gt;
    b=bt;
    
}
void telequadrangle::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2d(p1.getX(), p1.getY());
    glVertex2d(p2.getX(), p2.getY());
    glVertex2d(p3.getX(), p3.getY());
    glVertex2d(p4.getX(), p4.getY());
    glEnd();
}

void telequadrangle::paint()
{
    srand((unsigned)time(NULL));
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
}