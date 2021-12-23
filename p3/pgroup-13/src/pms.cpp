#include <iostream>
#include "demo.h"
using namespace std;

int main() {
    cout << "Parking Management Software" << endl;
    cout << "Input 1 for demo mode, input 2 for ordinary mode where you can input information of parking lot and cars."
         << endl;
    int choice = 0;
    cin >> choice;
    if (choice == 1)
        demo();
    else
        ordinary_pms();
    return 0;

}
