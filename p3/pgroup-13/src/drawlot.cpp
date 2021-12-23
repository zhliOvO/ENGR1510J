#include "figures.h"
#include "drawlot.h"
void drawlot()
{
    Vec p1(-0.9,-0.9);Vec p2(-0.9,0.8);
    static line l1(p1,p2);
    l1.draw();
    Vec p3(0.9,-0.8);Vec p4(0.9,0.8);
    static line l2(p3,p4);
    l2.draw();
    Vec p5(-0.9,0.8);Vec p6(0.9,0.8);
    static line l3(p5,p6);
    l3.draw();
    Vec p7(-0.6,-0.8);Vec p8(0.9,-0.8);
    static line l4(p7,p8);
    l4.draw();
    Vec p9(-0.4,-0.5);Vec p10(-0.4,-0.8);
    static line l5(p9,p10);
    l5.draw();
    Vec p11(-0.2,-0.5);Vec p12(-0.2,-0.8);
    static line l6(p11,p12);
    l6.draw();
    Vec p13(0,-0.5);Vec p14(0,-0.8);
    static line l7(p13,p14);
    l7.draw();
    Vec p15(0.2,-0.5);Vec p16(0.2,-0.8);
    static line l8(p15,p16);
    l8.draw();
    Vec p17(0.4,-0.5);Vec p18(0.4,-0.8);
    static line l9(p17,p18);
    l9.draw();
    Vec p19(0.6,-0.5);Vec p20(0.6,-0.8);
    static line l10(p19,p20);
    l10.draw();
    Vec pu7(-0.6,0.5);Vec pu8(-0.6,0.8);
    static line lu4(pu7,pu8);
    lu4.draw();
    Vec pu9(-0.4,0.5);Vec pu10(-0.4,0.8);
    static line lu5(pu9,pu10);
    lu5.draw();
    Vec pu11(-0.2,0.5);Vec pu12(-0.2,0.8);
    static line lu6(pu11,pu12);
    lu6.draw();
    Vec pu13(0,0.5);Vec pu14(0,0.8);
    static line lu7(pu13,pu14);
    lu7.draw();
    Vec pu15(0.2,0.5);Vec pu16(0.2,0.8);
    static line lu8(pu15,pu16);
    lu8.draw();
    Vec pu17(0.4,0.5);Vec pu18(0.4,0.8);
    static line lu9(pu17,pu18);
    lu9.draw();
    Vec pu19(0.6,0.5);Vec pu20(0.6,0.8);
    static line lu10(pu19,pu20);
    lu10.draw();
    Vec p21(-0.6,-0.9);Vec p22(-0.6,-0.5);
    static line l11(p21,p22);
    l11.draw();
    Vec a(-0.6,-0.1);Vec b(0.5,-0.1);Vec c(0.5,0.1);Vec d(-0.6,0.1);
    static quadrangle q(a,b,c,d,0,0,0);
    q.draw();
}