//
// Created by 马鸣谦 on 2021/12/10.
//
#include "demo.h"
#include "vehicle.h"



using namespace std;

void demo() {
    srand((unsigned int) time(nullptr));
/*
 * here are some settings for the demo mode in pms:
 * each parking slot is designed to fit in vehicle of different sizes
 * So we apply an array of a structure of single parking slot that record the size of the slot as well as whether it is already parked.
 * instructions are for programming in progress, and it should also be included in the README file and wiki.
 * we will randomize the number of floors, the number of slots in each slot and the type of cars can fit in each slot
 *
 * More settings for the demo mode:
 * We have possibly 1-20 cars in total, each of them should have a random arrival and departure time. Cars get into and out of the parking lot in order
 * We set the initial time as 0(in second, but should be displayed as hours to simulate a parking process
 * By Mingqian Ma
 */
    int floor_num = rand() % 4 + 2; //possibly 2-5 floors
    int total_size = 0;
    int size_each_floor[11];
    for (int i = 0; i < floor_num; i++) {
        size_each_floor[i] = (rand() % 4 + 4) * 2; //possibly 8-14 slots
        total_size += size_each_floor[i];
    }
    lot slots[10001];
    for (int i = 0; i < total_size; i++) {
        slots[i].is_empty = 1;
        slots[i].size = rand() % 4;
    }
    int num_of_cars = rand() % 20 + 1; //there are possibly 1-20 cars in total
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