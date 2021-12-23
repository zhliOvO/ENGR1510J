#ifndef PROJ_H
#define PROJ_H
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<getopt.h>
#define T 52
#ifdef _WIN32
#define cls system("cls")
#endif
#ifdef _WIN64
#define cls system("cls")
#endif
#ifdef __linux__
#define cls system("reset")
#endif
#ifdef __APPLE__
#define cls system("reset")
#endif
typedef char *string;
struct card
{
	int clr; //suit
	int num; //number
};
struct deck
{
	int num; 
	struct card cds[500];
};
typedef struct player
{
    struct player * prev;
    int num; //number of cards in his hand
	int score;//total score of a player
	struct card cds[T];  //the detail of his cards
    struct player * next;
}player;
void initialize(struct card *cards,int d);
void shuffle(struct card *cards,int d);
void distribute(struct player *pl,struct deck *stock,int c,int n);
void drawcard(struct player *pl,struct deck *stock,int p);
void playcard(struct player *pl,struct deck *used,int p,int x);
void usecard(struct deck *used,struct player *pl,int j,int x);
int  checkcard(struct player *pl,int clr,int num,int x,int j,int fl);
void demomode(int d,int n,int c,int r);
void printcard(int a,int b);
void printcards(struct player *pl,int j);
void help();
void clearscreen();
#endif
