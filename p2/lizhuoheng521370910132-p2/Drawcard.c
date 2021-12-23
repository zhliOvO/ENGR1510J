#include "proj.h"
void drawcard(struct player *pl,struct deck *stock,int p)
{
    
	pl[p].cds[pl[p].num].clr=stock->cds[stock->num].clr;
	pl[p].cds[pl[p].num].num=stock->cds[stock->num].num;
	pl[p].num++;
	//printf("\n Card Drawn: %d %d\n",stock->cds[stock->num].clr,stock->cds[stock->num].num);
	//printf(" Card Drawn: %d %d\n",pl[p].cds[pl[p].num].clr,pl[p].cds[pl[p].num].num);
	//stock->cds[stock->num].clr=0;
	//stock->cds[stock->num].num=0;
	stock->num--;
}
