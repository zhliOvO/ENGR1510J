#include "assignment.h"
#include <time.h>
#include <string.h>
#define JOJ
typedef struct _card
{
    char* suit;
    int rank;
}card;
void initiate(card* stock);
void draw(card* stock);
void shuffle(card* stock,card* new);
void sort(card* stock,card* new);
// ex. 5 function: disptach work to other functions for exercise 5
void ex5(){
    card* stock=malloc(52*sizeof(card));
    card* new=malloc(52*sizeof(card));
    srand((int)time(NULL));
    getchar();
    initiate(stock);
    draw(stock);
    shuffle(stock,new);
    getchar();
    draw(stock);
    getchar();
    sort(stock,new);
    draw(new);
    free(stock);
    free(new);
}
void draw(card* stock){
    for(int i=0;i<52;i++){
        switch((stock+i)->rank){
            case 11:
                printf("%s %s\n",(stock+i)->suit,"Jack");                    
                break;
            case 12:
                printf("%s %s\n",(stock+i)->suit,"Queen");
                break;
            case 13:                    
                printf("%s %s\n",(stock+i)->suit,"King");
                break;
            case 14:
                printf("%s %s\n",(stock+i)->suit,"Ace");
                break;
            default:                    
                printf("%s %d\n",(stock+i)->suit,(stock+i)->rank);
                break;
            }
    }
}
void initiate(card* stock){
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            switch(i){
                case 0:
                    (stock+j)->suit="Spades";
                    (stock+j)->rank=j+2;
                    break;
                case 1:
                    (stock+13+j)->suit="Hearts";
                    (stock+13+j)->rank=j+2;
                    break;
                case 2:
                    (stock+26+j)->suit="Diamonds";
                    (stock+26+j)->rank=j+2;
                    break;
                case 3:
                    (stock+39+j)->suit="Clubs";
                    (stock+39+j)->rank=j+2;
                    break;
            }
        }
    }
}
void shuffle(card* stock,card* new){
    card temp;
    for(int i=0;i<52;i++){
        int random=rand()%(52-i);// not consider those cards which have been se lected
        (new+i)->rank=(stock+random)->rank;
        (new+i)->suit=(stock+random)->suit;
        temp.rank=(stock+random)->rank;temp.suit=(stock+random)->suit;// let the selected card move to the final
        (stock+random)->suit=(stock+51-i)->suit;(stock+random)->rank=(stock+51-i)->rank;
        (stock+51-i)->rank=temp.rank;(stock+51-i)->suit=temp.suit;
    }
    stock=new;
}
void sort(card* stock,card* new){
    int sui,ran;//suit rank
    for(int i=0;i<52;i++){
        if(strcmp((stock+i)->suit,"Spades")==0) {sui=0;}
        else if(strcmp((stock+i)->suit,"Hearts")==0) {sui=1;}
        else if(strcmp((stock+i)->suit,"Diamonds")==0) {sui=2;}
        else if(strcmp((stock+i)->suit,"Clubs")==0) {sui=3;}
        ran=(stock+i)->rank;
        (new+sui*13+ran-2)->rank=(stock+i)->rank;
        (new+sui*13+ran-2)->suit=(stock+i)->suit;
    }
    stock=new;
}
#ifdef JOJ
int main(){
    ex5();
    return 0;
}
#endif
