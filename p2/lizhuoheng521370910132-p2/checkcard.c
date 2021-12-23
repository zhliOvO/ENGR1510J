#include "proj.h"
int  checkcard(struct player *pl,int clr,int num,int x,int j,int fl)
{
    if ((num==1 || num==2) && fl==1)
    {
            if ((pl[j].cds[x].num==1 || pl[j].cds[x].num==2 || pl[j].cds[x].num==6 ) || (pl[j].cds[x].clr==clr && (pl[j].cds[x].num==10 || pl[j].cds[x].num==11)))
                return 1;
            else return 0;
    }
    if (fl==1)
    {
        if (pl[j].cds[x].num==6)
            return 1;
        else return 0;
    }
    if (pl[j].cds[x].clr==clr || pl[j].cds[x].num==num)
      return 1;
    else return 0;
}
