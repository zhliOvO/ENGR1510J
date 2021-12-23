#include "proj.h"
void printcards(struct player *pl,int j)
{
    int n;
    n=pl[j].num;
    char *co[]={"S","H","D","C"};
    char *nu[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for (int i=0;i<n;i++)
    {
        printf("   --------");
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        if (pl[j].cds[i].num==9)
        printf("   |%s    |",nu[pl[j].cds[i].num-1]);
        else
        printf("   |%s     |",nu[pl[j].cds[i].num-1]);
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("   |      |");
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("   |  %s   |",co[pl[j].cds[i].clr]);
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("   |      |");
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        if (pl[j].cds[i].num==9)
        printf("   |    %s|",nu[pl[j].cds[i].num-1]);
        else
        printf("   |     %s|",nu[pl[j].cds[i].num-1]);
    }
    printf("\n");
    for (int i=0;i<n;i++)
    {
        printf("   --------");
    }
    printf("\n");
}
