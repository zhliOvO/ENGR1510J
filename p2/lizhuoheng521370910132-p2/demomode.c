#include "proj.h"
void demomode(int d,int n,int c,int r)
{
	struct card cards[T*10],present;
	struct deck *stock;
	struct deck *used;
	struct player pl[10];
	stock=malloc(3*sizeof(int));
	used=malloc(3*sizeof(int));
    char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
	//FILE *fd;
	//fd=fopen("onecard.txt","w");
    initialize(cards,d);
	shuffle(cards,d);
	//fprintf(fd,"This is a log file containing the details of the game\n");
	for (int i=0;i<(T*d);i++)
	{
		stock->cds[i]=cards[i];
		//fprintf(fd,"Card %d : %s  %s\n",i+1,numb[stock->cds[i].num-1],colr[stock->cds[i].clr]);
	}
	stock->num=T*d-1;
	//put the cards into the stock
	distribute(pl,stock,c,n);
	printf("\n");
	for (int i=0;i<n;i++)
	{
		printf("Player %d:",i+1);
		for(int j=0;j<pl[i].num;j++)
		   printf("%s  %s ,",colr[pl[i].cds[j].clr],numb[pl[i].cds[j].num-1]);
		printf("\n");
	}
	present.clr=stock->cds[stock->num].clr;
    present.num=stock->cds[stock->num].num;
	used->num=1;
	used->cds[used->num].clr=stock->cds[stock->num].clr;
    used->cds[used->num].num=stock->cds[stock->num].num;
	stock->num--;
	int current; // current stands for the present player
	int dir=1; //dir stands for the direction and control the skip
	int plus=0; //plus stands for the number of cards to draw
	current=-1;
	printf("\n --- Game start --- \n");
    while (r>0) //The main loop (Every round)
	{
		//dir=1;
		int	ifattack=0;
		while (1>0) //The second loop (Every player)
		{
			current=current+dir;
			//printf("%d %d\n",current,dir);
			if (dir==2) dir=1;
			if (dir==-2) dir=-1;
			if (current>=n) current-=n;
			if (current<0) current+=n;
			//decide the next player
			printf("\nThe present card is:  %s  %s\n",colr[present.clr],numb[present.num-1]);
			printf("Player %d ! It's your turn!\n",current+1);
			//printf("%d\n",pl[current].num);
		    for(int k=0;k<pl[current].num;k++)
		   		printf("Card %d:%s  %s\n",k+1,colr[pl[current].cds[k].clr],numb[pl[current].cds[k].num-1]);
			int x;
            int flag=0;
            for (int i=0;i<pl[current].num;i++)
                if (checkcard(pl,present.clr,present.num,i,current,ifattack)==1)
                {
                    x=i;flag=1;
                    break;
                }
			if (flag==1)
			{
					printf("Player %d played card %d !\n",current+1,x+1);
					//fprintf(fd,"Player %d played card %s %s !\n",current+1,colr[pl[current].cds[x].clr],numb[pl[current].cds[x].num-1]);
					switch (pl[current].cds[x].num)
    				{
   					     case 1:
							plus+=2;ifattack=1;
							printf("Plus %d !\n",plus);
   					        break;
    				     case 2:
						    plus+=3;ifattack=1;
							printf("Plus %d !\n",plus);
    				        break;
    				     case 6:
						    plus=0;ifattack=0;
							printf("Defend !\n");
     				        break;
					     case 11:
						    dir=-dir;
							//printf("%d %d\n",current,dir);
							printf("Reverse !\n");
						    break; 
						 case 10:
						    dir=2*dir;
							//printf("%d %d\n",current,dir);
							printf("Skip !\n");
						    break;
   					}
					present.clr=pl[current].cds[x].clr;
                    present.num=pl[current].cds[x].num;
					usecard(used,pl,current,x);
					if (pl[current].num==0)
					{
						printf("------This round ends!------\n");
						for (int i=0;i<n;i++)
						{
							pl[i].score-=pl[i].num;
							printf("Player %d : %d Total score: %d \n",i+1,-pl[i].num,pl[i].score);
						}
					    printf("\nPlayer %d wins this round! \n", current+1);
						r--;
					}
					flag=1;
					break;
			}
            else
            {
                if (plus>0)
					for (int k=0;k<plus;k++)
					{
					    drawcard(pl,stock,current);
						//printf(" Card Drawn: %d %d\n",pl[current].cds[pl[current].num].clr,pl[current].cds[pl[current].num].num);
					}
					else
					{
						drawcard(pl,stock,current);
						//printf(" Card Drawn: %d %d\n",pl[current].cds[pl[current].num].clr,pl[current].cds[pl[current].num].num);
					}
					plus=0;ifattack=0;
            }
        }
		//cls;
	}
	//fclose(fd);
}
