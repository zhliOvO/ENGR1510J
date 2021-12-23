#include "proj.h"
void printcard(int a,int b)
{
    char *co[]={"S","H","D","C"};
    char *nu[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    if (b!=8)
    {
    printf("--------\n");
    printf("|%s     |\n",nu[b]);
    printf("|      |\n");
    printf("|  %s   |\n",co[a]);
    printf("|      |\n");
    printf("|     %s|\n",nu[b]);
    printf("--------\n");
    }
    else
    {
    printf("--------\n");
    printf("|%s    |\n",nu[b]);
    printf("|      |\n");
    printf("|  %s   |\n",co[a]);
    printf("|      |\n");
    printf("|    %s|\n",nu[b]);
    printf("--------\n");
    }
}
