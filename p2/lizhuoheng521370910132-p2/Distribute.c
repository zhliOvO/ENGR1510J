#include "proj.h"
void distribute(struct player *pl,struct deck *stock,int c,int n)
{
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<c;j++)
		{
		    pl[i].cds[j].clr=stock->cds[stock->num].clr;
			pl[i].cds[j].num=stock->cds[stock->num].num;
			//printf("%d ",pl[i].cds[j].clr);
			stock->num--;
		}
		pl[i].num=c;
	}
}
