#ifndef USET_H
#define USET_H 
#define INITSETSIZE 64
// Initial memory allocated for the set 
#define CHAR 1 
#define INT sizeof(int) 
#define DOUBLE sizeof(double)
/* elem: list of elments; card: cardinal of the set; type: data type (CHAR INT or DOUBLE) */ 
typedef struct universalSet { 
    void *elem; 
    int card; 
    int type; 
} uset;
/* Initialize an empty set of given type and allocate the initial memory: INITSETSIZE*type */ 
void newSet(uset **set, int type); 
void deletSet(uset **set); // Free the memory allocated by newSet 
/* add elem to the set: check whether it is already in the set; resize memory if card = allocated memory; new memory = previous+64 e.g. before: mem=128, card=128, after: men=192, card=129 */
void addElem(void *elem, uset *set);
/* remove elem from the set; do nothing if the set does not contain this elem; resize memory if "too much memory" is used; new = previous-64 e.g. before: mem=192, card=129, after: card=128, mem=128 */
void remElem(void *elem, uset *set);

//helper functions
/* check whether a given object is in the set
    if it is in set return the position +1
    else return 0
*/
int inSet(void *elem, uset *set);
/* use one int command to 
    1.extend set if set is full
    -1. shorten set if set is much unused*/
void* resizeSet(uset *set); 

#endif
