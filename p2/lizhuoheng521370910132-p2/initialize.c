#include "proj.h"
void initialize(struct card *cards,int d)
{
    for (int i=0;i<(T*d);i++)
    {
       cards[i].clr=((int)floor(i/13))%4;
       cards[i].num=i%13+1;
    }
}
