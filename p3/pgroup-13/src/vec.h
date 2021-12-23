#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "demo.h"

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION

#include <GLUT/glut.h>

#endif

#ifdef _WIN32
#include <GL/freeglut.h>
#include <windows.h>
#endif

#ifdef _WIN64
#include <GL/freeglut.h>
#include <windows.h>
#endif

#ifdef __linux__
#include <GL/freeglut.h>
#endif
class Vec 
{
    private:
        double x,y;
    public:
        Vec(double _x=0, double _y=0);
        double getX();
        double getY();
        // Overloads + operator
        // returns the sum of 2 Vec
        Vec operator+ (Vec v);
        // Overload - on 2 Vectors
        // return thier difference Vector
        Vec operator-(Vec v);
        // Overload * operator on a float k
        // return current Vector scaled by k
        Vec operator*(double k);
        // Overload * on 2 Vectors
        // return thier inner product (scaler product)
        double operator*(Vec v);
        // Overload << on an angle
        // return current vector rotated counter clockwise
        // by this angle
        Vec operator<<(double a);
        // Overload >> on an angle
        // return current vector rotated clockwise
        // by this angle
        Vec operator>>(double a);
};

#endif
