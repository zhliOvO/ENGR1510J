//
// Created by 马鸣谦 on 2021/12/11.
//

#include "demo.h"
#include "vehicle.h"

void ordinary_pms() {
    srand((unsigned int) time(nullptr));
    int num_of_cars, floor_num;
    cout << "Please input number of cars to park: ";
    cin >> num_of_cars;
    cout << endl;
    cout << "Please input number of floors of parking lot: ";
    cin >> floor_num;
    cout << endl << "Size of each floor and type of each slot will be randomized automatically." << endl;
    int total_size = 0;
    int size_each_floor[11];
    for (int i = 0; i < floor_num; i++) {
        size_each_floor[i] = (rand() % 4 + 4) * 2; //possibly 8-14 slots
        cout << "Size of floor " << i + 1 << " is " << size_each_floor[i] << endl;
        total_size += size_each_floor[i];
    }
    cout<<endl;
    lot slots[10001];
    for (int i = 0; i < total_size; i++) {
        slots[i].is_empty = 1;
        slots[i].size = rand() % 4;//size of each slot will not be displayed in the program for clarity
    }
    vehicle *veh[10001];
    for (int i = 0; i < num_of_cars; i++) {
        int tmp = rand() % 4;
        switch (tmp) {
            case 0:
                veh[i] = new bicycle;
                break;
            case 1:
                veh[i] = new motorbike;
                break;
            case 2:
                veh[i] = new car;
                break;
            case 3:
                veh[i] = new van;
                break;
        } //initialize all the vehicles
        veh[i]->set_type(tmp);
        if (i != 0) {
            veh[i]->set_arrival_time(veh[i - 1]->get_arrival_time() + rand() % 10);
            sleep(veh[i]->get_arrival_time() - veh[i - 1]->get_arrival_time());
        } else
            veh[i]->set_arrival_time(0);
        int empty_slot = -1;
        for (int j = 0; j < total_size; j++) {
            if (slots[j].size == veh[i]->get_type_vehicle() && slots[j].is_empty == 1) {
                slots[j].is_empty = 0;
                empty_slot = j;
                break;
            }
        } //find the best fit slot to park a vehicle
        if (empty_slot == -1) {
            for (int j = 0; j < total_size; j++) {
                if (slots[j].size >= veh[i]->get_type_vehicle() && slots[j].is_empty == 1) {
                    slots[j].is_empty = 0;
                    empty_slot = j;
                    break;
                }
            }
        }
        cout << "Car " << i + 1 << ": " << endl;
        //if there is no best fit slot, we try to find a larger slot so that a vehicle can fit in
        veh[i]->print_arrival_ticket(empty_slot,
                                     size_each_floor); //print the result, if empty_slot=-1, the vehicle cannot park
        if (empty_slot != -1)
            veh[i]->print_departure_ticket();
        cout << endl;
    }
    cout << "All the cars have parked!" << endl;
}