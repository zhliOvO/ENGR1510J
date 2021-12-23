//
// Created by 马鸣谦 on 2021/11/28.
//
#include "vehicle.h"

using namespace std;

int vehicle::get_x() {
    return x;
}

int vehicle::get_y() {
    return y;
}

int vehicle::get_arrival_time() {
    return arrival_time;
}

int vehicle::get_type_vehicle() {
    return type;
}

void vehicle::set_type(int t) {
    type = t;
}
/*
double vehicle::get_theta() {
    return theta;
}
 */

/*
void vehicle::find_slot(parking_lot *current_lot) {
    parking_lot *tmp = current_lot;
    while (tmp != NULL) {
        if (!tmp->get_is_empty() && tmp->get_type() == type) {
            empty_pos = tmp->get_index();
        }
        tmp++;
    }
    tmp = current_lot;
    while (tmp != NULL) {
        if (!tmp->get_is_empty() && tmp->get_type() > type) {
            empty_pos = tmp->get_index();
        }
        tmp++;
    }
    empty_pos = -1;
}
*/
// slots and finding slots may be defined in another way, so it is undetermined how to implement the final version of finding available slots
int vehicle::calculate_price() {
    time_t leave_time = time(NULL);
    int parking_time = leave_time - arrival_time;
    return parking_time * perprice;
}

void vehicle::print_departure_ticket() {
    int leave_time = arrival_time + rand() % 20 + 10;
    int parking_time = leave_time - arrival_time;
    cout << "Time spent in the parking lot:" << parking_time << endl;
    cout << "Type of vehicle:" << type << endl;
    cout << "Price:" << parking_time * perprice << endl;
}

void vehicle::print_arrival_ticket(int empty_pos, int size_each_floor[]) {
    cout << "Time of arrival:" << arrival_time << endl;
    cout << "Type of vehicle:" << type_name[type] << endl;

    if (empty_pos != -1) {
        int tmp1 = 0;
        int i = 0;
        while (tmp1 <= empty_pos) {
            tmp1 += size_each_floor[i];
            i++;
        }
        cout << "Where to find an empty slot:" << " Floor " << i << " Slot Number: " << empty_pos << endl;
    } else
        cout << "Can't find an empty slot" << endl;
}

void vehicle::set_arrival_time(int a_time) {
    arrival_time = a_time;
}

