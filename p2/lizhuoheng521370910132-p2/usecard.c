#include "proj.h"
void usecard(struct deck *used,struct player *pl,int j,int x)
{
    used->num++;
	used->cds[used->num].clr=pl[j].cds[x].clr;
	used->cds[used->num].num=pl[j].cds[x].num;
    if (x==pl[j].num)
    {
        pl[j].cds[x].clr=0;
        pl[j].cds[x].num=0;
    }
    else
    for (int i=x;i<=pl[j].num-1;i++)
    {
        pl[j].cds[i].clr=pl[j].cds[i+1].clr;
        pl[j].cds[i].num=pl[j].cds[i+1].num;
    }
    //printf("Present card %d: %d %d",x,pl[j].cds[x].clr,pl[j].cds[x].num);
    pl[j].num--;
}
