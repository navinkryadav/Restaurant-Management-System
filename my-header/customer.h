//
// Created by navin on 05-11-2021.
//

#ifndef RESTAURANT_MANAGEMENT_SYSTEM_CUSTOMER_H
#define RESTAURANT_MANAGEMENT_SYSTEM_CUSTOMER_H
#include <string>
#include "hotels.h"

using namespace std;

void customer_menu() {
    cout<<"\n\t\t\t\t\t   ----------------------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t\t    CUSTOMER SECTION"<<endl;
    cout<<"\t\t\t\t\t   ----------------------------------------------"<<endl;
    cout<<"\n\t\t\t\t\t\t\t1. Display all available foods"<<endl;
    cout<<"\t\t\t\t\t\t\t2. Display all hotels"<<endl;
    cout<<"\t\t\t\t\t\t\t3. Order food"<<endl;
    cout<<"\t\t\t\t\t\t\t4. Back To Main Menu \n"<<endl;
    cout<<"\t\t\t\t\t\t\t   Enter Your Choice --->"<<endl;
}

void customer(){
    int choice;
    customer_menu();
    cin>>choice;
    switch (choice) {
        case 1: {
            display_all_food();
            customer();
            break;
        }
        case 2: {
            display_hotels();
            customer();
            break;
        }
        case 3: {
            food_order();
            break;
        }
        case 4: return;
        default:{
            cout<<"\nEnter a valid choice\n";
            break;
        }

    }
}

#endif //RESTAURANT_MANAGEMENT_SYSTEM_CUSTOMER_H
