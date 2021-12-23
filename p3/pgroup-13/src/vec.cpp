//
// Created by 李卓恒 lizhuoheng 521370910132 on 2021/12/10.
//
/*
This part is the functions of the class Vec
Some overloading of the basic operators
*/
#include "vec.h"
using namespace std;

Vec::Vec(double _x,double _y)
{
    x=_x;
    y=_y;
}

double Vec::getX()
{
    return x;
}

double Vec::getY()
{
    return y;
}

Vec Vec::operator+(Vec v)
{
    return Vec(x + v.getX(), y + v.getY());
}
// Overloads + operator
// returns the sum of 2 Vec
Vec Vec::operator-(Vec v)
{
    return Vec(x - v.getX(), y - v.getY());
}
// Overload - on 2 Vectors
// return thier difference Vector
Vec Vec::operator*(double k)
{
    return Vec(x*k,y*k);
}
// Overload * operator on a float k
// return current Vector scaled by k
double Vec::operator*(Vec v)
{
    return x * v.getX() + y * v.getY();
}
// Overload * on 2 Vectors
// return thier inner product (scaler product)
Vec Vec::operator<<(double a)
{
    return Vec(x*cos(a)-y*sin(a),y*cos(a)+x*sin(a));
}
// Overload << on an angle
// return current vector rotated counter clockwise
// by this angle
Vec Vec::operator>>(double a)
{
    return Vec(x*cos(a)+y*sin(a),y*cos(a)-x*sin(a));
}
// Overload >> on an angle
// return current vector rotated clockwise
// by this 
