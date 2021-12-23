#include "proj.h"
void shuffle(struct card *cards,int d)
{
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    srand((unsigned)time(NULL)); //initialize the random number
    for (int i=0;i<(40*d);i++)  //roughly enough to shuffle
    {
        int ran1,ran2;
        ran1=rand()%(52*d);ran2=rand()%(52*d);  // ran1 and ran2 are the two cards to be exchanged in position
        if (ran1!=ran2)
        {
            struct card temp;
            temp=cards[ran1];
            cards[ran1]=cards[ran2];
            cards[ran2]=temp;
        } 
    }
    FILE *fd;
    fd=fopen("onecard.log","w");
    fprintf(fd,"This is a log file!\n");
    fprintf(fd,"------Shuffle Result------\n");
    for (int i=0;i<52*d;i++)
    {
        fprintf(fd,"Card %d: %s %s\n",i+1,colr[cards[i].clr],numb[cards[i].num-1]);
    }
    fclose(fd);
}
