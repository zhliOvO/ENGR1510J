#ifndef SHAPES_H
#define SHAPES_H
typedef struct _point
{
    double x, y;
} Point;

typedef struct _color
{
    float r, g, b;
} Color;

//abstract
class Shape
{
    public:
        void virtual draw() = 0;
        virtual ~Shape(){};
        virtual void move(double dx,double dy)=0;
        virtual void zoom(Point pt,double k)=0;
        virtual void rotate(Point pt,double ang)=0;
};

class Line : public Shape
{
    public:
        Line(Point pt1,Point pt2,Color cl);
        void draw();
        void move(double dx,double dy);
        void zoom(Point pt,double k);
        void rotate(Point pt,double ang);
    private:
        Point p1,p2;
        Color c;
};
class Triangle : public Shape
{
    public:
        Triangle(Point pt1, Point pt2, Point pt3, Color cl);
        void draw();
        void move(double dx,double dy);
        void zoom(Point pt,double k);
        void rotate(Point pt,double ang);
    private:
        Point p1, p2, p3;
        Color c;
};

class Quadrangle : public Shape
{
    public:
        Quadrangle(Point pt1, Point pt2,Point pt3,Point pt4,Color cl);
        void draw();
        void move(double dx,double dy);
        void zoom(Point pt,double k);
        void rotate(Point pt,double ang);
    protected:
        Point p1,p2,p3,p4;
        Color c;
};


//circle
class Circle : public Shape
{
    public:
        Circle(Point pt, float radius, Color cl);
        void draw();
        void move(double dx,double dy);
        void zoom(Point pt,double k);
        void rotate(Point pt,double ang);
    private:
        Point p;
        float r;
        Color c;
};
#endif


