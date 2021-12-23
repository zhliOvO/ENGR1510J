//
// Created by 马鸣谦 on 2021/12/10.
//

#ifndef PGROUP_13_DEMO_H
#define PGROUP_13_DEMO_H

extern void demo();

extern void ordinary_pms();

typedef struct _lot {
    bool is_empty; // true for an empty slot, false for an occupied slot
    int size; //3 for van, 2 for car, 1 for motorbike, 0 for bicycle
} lot;
#endif //PGROUP_13_DEMO_H
