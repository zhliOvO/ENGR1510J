#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <unistd.h>
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
using namespace std;


class vehicle {
public:


    int calculate_price();

    int get_type_vehicle();

    int get_x();

    int get_y();

    int get_arrival_time();

//    double get_theta();

    void print_arrival_ticket(int empty_pos, int size_each_floor[]);

    void print_departure_ticket();

    void set_type(int t);

//    void set_x(int x1);
//    void set_y(int y1);
    void set_arrival_time(int a_time);
//    void set_theta(double th);
//    void set_empty_pos(int em);
protected:
    int type; //3 for van, 2 for car, 1 for motorbike, 0 for bicycle
    int x, y; //current position of the car (to be determined)
    int arrival_time; //arrival time of a car into the lot
    static const int perprice = 1;
//    double theta; //angle between horizontal and current orientation
//    int empty_pos;
    constexpr static const char type_name[5][10] = {"bicycle", "motorbike", "car", "van"};
};

class car : public vehicle {

};

class bicycle : public vehicle {
};


class motorbike : public vehicle {

};

class van : public vehicle {

};

#endif
