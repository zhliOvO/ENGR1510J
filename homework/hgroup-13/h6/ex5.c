#include "universal_set.h"
#include <stdio.h>
#include <stdlib.h>

void ex5(){}
//implement operations for universal set

//init
void newSet(uset **set, int type){
    (**set).type = type;
    (**set).card = 0;
     (**set).elem = malloc((size_t)((INITSETSIZE)*type));
    if((**set).elem==NULL) exit(-1);
}

//delete set: release memory allocated
void deletSet(uset **set){
    free((**set).elem);
}

/* check whether a given object is in the set*/
int inSet(void *elem, uset *set){
    for(int i = 0; i < set->card; i++){
        switch(set->type){
            case INT:  if(((int* )set->elem)[i] == *(int* )elem) return i+1; break;
            case DOUBLE: if(((double* )set->elem)[i] == *(double* )elem) return i+1; break;
            case CHAR: if(((char* )set->elem)[i] == *(char* )elem) return i+1; break;
            default: break;
        }
    }
    return 0;
}


/* add an element to the set:
    check whether the element is in the set
    check whether need to extend the set
    add element*/
void addElem(void* elem, uset *set){
    if(!inSet(elem,set)){
        set->card++;
        //resize if necessary
        int c = (((*set).card)/INITSETSIZE+1)*INITSETSIZE;
        (set)->elem = realloc((set)->elem,(size_t)((c)*(set)->type));
    
        switch(set->type){
            case INT: ((int* )set->elem)[set->card-1] = *(int* )elem; break;
            case DOUBLE: ((double* )set->elem)[set->card-1] = *(double* )elem; break;
            case CHAR: ((char* )set->elem)[set->card-1] = *(char* )elem; break;
            default: break;
        }
    }
}

//remove element if it is in set 
void remElem(void *elem, uset *set){
    int i = inSet(elem,set);
    if(i){
        i--;//get the position
        set->card--;
        for(int j = i; j < set->card; j++){
            switch(set->type){
                case INT: ((int* )set->elem)[j] = ((int* )set->elem)[j+1]; break;
                case DOUBLE: ((double* )set->elem)[j] = ((double* )set->elem)[j+1]; break;
                case CHAR: ((char* )set->elem)[j] = ((char* )set->elem)[j+1]; break;
                default: break;
            }
        }
    }
    //resize if necessary
    int c = (((*set).card)/INITSETSIZE+1)*INITSETSIZE;
    (set)->elem = realloc((set)->elem,(size_t)((c)*(set)->type));
    
}




