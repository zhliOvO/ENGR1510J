//
// Created by 马鸣谦 on 2021/12/1.
//

#ifndef PGROUP_13_PARKING_LOT_H
#define PGROUP_13_PARKING_LOT_H

class parking_lot {
public:
    void draw_lot();

    int get_type();

    int get_index();

    int get_row_size();

    bool get_is_empty();

protected:
    int type; // 0 for bicycle slot, 1 for motorcycle slot, 2 for car slot, 3 for van slot
    // smaller cars can fit in larger slots, for instance, if a car has type of 0, it can fit in a parking slot with type of 0-3
    int index;
    int row_size; //how many slots in a row
    bool is_empty; //false for full, true for empty

};

#endif //PGROUP_13_PARKING_LOT_H
