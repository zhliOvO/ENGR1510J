#include "proj.h"
int main(int argc, char *argv[])
{
    int d=2,n=4,r=1,c=5;
    int ch;
	//char* filename;
	struct card cards[T*10],present;
	struct deck *stock;
	struct deck *used;
	struct player pl[10];
	stock=malloc(4*sizeof(int));
	used=malloc(4*sizeof(int));
	//allocate the memory for the decks
	printf("########################\n");
	printf("#                      #\n");
	printf("# Welcome to One Card! #\n");
	printf("#                      #\n");
	printf("########################\n\n");
	char *colr[]={"Spades","Hearts","Diamonds","Clubs"};
    char *numb[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
	char* const short_options="hn::c::d::r::a::l";
	struct option long_options[] = 
		{
            {"help",no_argument,NULL,'h'},
            {"player-number",optional_argument,NULL,'n'},
            {"initial-cards",optional_argument,NULL,'c' },
            {"decks",optional_argument, NULL, 'd'},
            {"rounds", optional_argument, NULL,'r'},
			{"auto", no_argument, NULL,'a'},
			{"log",optional_argument,NULL,'l'},
            {0,0,0,0 }
        };
    while ((ch = getopt_long(argc,argv,short_options,long_options,NULL))!=-1) 
    {
		switch (ch)
		{
			case 'n':
			   n=(optarg==NULL?4:atoi(optarg));
			   printf("The number of players: %d\n",n);
			   break;
			case 'c':
			   c=(optarg==NULL?5:atoi(optarg));
			   printf("The cards (c cards per player): %d\n",c);
			   break;
			case 'd':
			   d=(optarg==NULL?2:atoi(optarg));
			   printf("Use d decks 52 cards each (d>=2): %d\n",d);
			   break;
			case 'r':
			   r=(optarg==NULL?1:atoi(optarg));
			   printf("Play r rounds (r>=1): %d\n",r);
			   break;
			case 'h':
			   help();
			   break;
			case 'l':
			   //filename=(optarg==NULL?"onecard.log":optarg);
			   break;
			case 'a':
			   demomode(d,n,c,r);
			   return 0;
			   break;
			default:
			   printf("Other option: %c\n",ch);
			   break;
		}
	}
	initialize(cards,d);
	shuffle(cards,d);
	for (int i=0;i<(T*d);i++)
	{
		stock->cds[i].num=cards[i].num;
		stock->cds[i].clr=cards[i].clr;
	}
	stock->num=T*d-1;
	//put the cards into the stock
	
	distribute(pl,stock,c,n);
	printf("\n");
	/*
	for (int i=0;i<n;i++)
	{
		printf("Player %d:",i+1);
		for(int current=0;current<pl[i].num;current++)
		   printf("%s  %s ,",colr[pl[i].cds[current].clr],numb[pl[i].cds[current].num-1]);
		printf("\n");
	}
	*/
	present.clr=stock->cds[stock->num].clr;
    present.num=stock->cds[stock->num].num;
	used->num=1;
	used->cds[used->num].clr=stock->cds[stock->num].clr;
    used->cds[used->num].num=stock->cds[stock->num].num;
	stock->num--;
	int current; // current stands for the current player
	int dir=1; //dir stands for the direction and control the skip
	int plus=0; //plus stands for the number of cards to draw
	int rd=0;//the round number
	current=-1;
	printf("\n --- Game start --- \n");
    while (r>0) //The main loop (Every round)
	{
		rd++;
		dir=1;
		int ifattack=0;
		while (1>0) //The second loop (Every player)
		{
			int flag=0;
			current=current+dir;
			if (dir==2) dir=1;
			if (dir==-2) dir=-1;
			if (current>=n) current-=n;
			if (current<0) current+=n;
			//decide the next player
			printf("\nThe present card is:  %s  %s \n\n",colr[present.clr],numb[present.num-1]);
			printcard(present.clr,present.num-1);
			printf("Player %d ! It's your turn!\n",current+1);
			if (ifattack==1)
			 	printf("You are under attack! Plus %d!\n",plus);
			//printf("%d\n",pl[current].num);
		    for(int k=0;k<pl[current].num;k++)
		   		printf("Card %d:%s  %s\n",k+1,colr[pl[current].cds[k].clr],numb[pl[current].cds[k].num-1]);
			printcards(pl,current);
			int x;
			printf("Play a card (enter 0 if you can't play a card): ");
			while (flag==0)
			{
				if(scanf("%d",&x)){};
				x=x-1;
				if (x==-1)
				{
					if (plus>0)
					{
						for (int k=0;k<plus;k++)
						{
							if (stock->num==0)
							{
								printf("\nStock pile exhasuted...Shuffling...\n");
								initialize(cards,d);
								shuffle(cards,d);
								stock->num=T*d-1;
								for (int i=0;i<(T*d);i++)
								{
									stock->cds[i]=cards[i];
									//fprintf(fd,"Card %d : %s  %s\n",i+1,numb[stock->cds[i].num-1],colr[stock->cds[i].clr]);
								}
							}
					   		drawcard(pl,stock,current);
							//printf(" Card Drawn: %s %s\n",colr[pl[current].cds[pl[current].num].clr],numb[pl[current].cds[pl[current].num].num-1]);
						}
					}
					else
					{
						if (stock->num==0)
						{
							printf("\nStock pile exhasuted...Shuffling...\n");
							initialize(cards,d);
							shuffle(cards,d);
							for (int i=0;i<(T*d);i++)
							{
								stock->cds[i]=cards[i];
								//fprintf(fd,"Card %d : %s  %s\n",i+1,numb[stock->cds[i].num-1],colr[stock->cds[i].clr]);
							}
							stock->num=T*d-1;
						}
						drawcard(pl,stock,current);
						//printf(" Card Drawn: %s %s\n",colr[pl[current].cds[pl[current].num].clr],numb[pl[current].cds[pl[current].num].num-1]);
					}
					plus=0;ifattack=0;
					break;
				}
				if (checkcard(pl,present.clr,present.num,x,current,ifattack)==1 && x<pl[current].num)
				{
					printf("Player %d played card %d !\n",current+1,x+1);
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
							printf("Reverse !\n");
						    break; 
						 case 10:
						    dir=2;
							printf("Skip !\n");
						    break;
   					}
					present.clr=pl[current].cds[x].clr;
                    present.num=pl[current].cds[x].num;
					usecard(used,pl,current,x);
					flag=1;
					break;
				}
				else 
				{
					printf("Invalid! Please try again (enter 0 if you can't play a card): ");
				}
			}
			clearscreen();
			if (pl[current].num==0)
			{
					printf("-----Round %d stat-----\n",rd);
					for (int i=0;i<n;i++)
					{
						pl[i].score-=pl[i].num;
						printf("Player %d : %d Total score: %d \n",i+1,-pl[i].num,pl[i].score);
					}
					printf("\nPlayer %d wins this round! \n", current+1);
					printf("NEXT ROUND\n");
					r--;
					break;
			}
		}
		initialize(cards,d);
		shuffle(cards,d);
		for (int i=0;i<(T*d);i++)
		{
			stock->cds[i]=cards[i];
			//fprintf(fd,"Card %d : %s  %s\n",i+1,numb[stock->cds[i].num-1],colr[stock->cds[i].clr]);
		}
		stock->num=T*d-1;
		//put the cards into the stock
		distribute(pl,stock,c,n);
		present.clr=stock->cds[stock->num].clr;
    	present.num=stock->cds[stock->num].num;
		used->num=1;
		used->cds[used->num].clr=stock->cds[stock->num].clr;
    	used->cds[used->num].num=stock->cds[stock->num].num;
		stock->num--;
	}
	free(stock);
	free(used);
    return 0;
}
