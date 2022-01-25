#include<iostream>
#include "my-header/admin.h"
#include "my-header/customer.h"

using namespace std;



void main_menu() {
    cout
            << "\n                                 **************************************************************************"
            << endl;
    cout << "                                                     WELCOME TO RESTAURANT MANAGEMENT SYSTEM" << endl;
    cout
            << "                                 **************************************************************************\n\n"
            << endl;
    cout << "\t\t\t\t\t\t\t1. ADMIN SECTION--> " << endl;
    cout << "\t\t\t\t\t\t\t2. CUSTOMER SECTION--> " << endl;
    cout << "\t\t\t\t\t\t\t3. Exit--> \n" << endl;
    cout << "\t\t\t\t\t\t\tEnter Your Choice --->" << endl;
}


int main() {
    int choice;
    hotel_initialize();
    while (true) {
        main_menu();
        cin >> choice;
        switch (choice) {
            case 1: {
                while (true) {
                    int sub_choice;
                    cout<<"\n\t\t\t\t\t   ----------------------------------------------"<<endl;
                    cout<<"\t\t\t\t\t\t\t    ADMIN SECTION"<<endl;
                    cout<<"\t\t\t\t\t   ----------------------------------------------"<<endl;
                    cout << "1)SIGNUP\n2)LOGIN\n3)EXIT\n\n";
                    cout << "Enter your choice\t";
                    cin >> sub_choice;
                    switch (sub_choice) {
                        case 1: {
                            signup();
                            break;
                        }
                        case 2: {
                            login();
                            break;
                        }
                        case 3: {
                            // exit(1);
                            return 0;
                        }
                        default: {
                            printf("\nPlease Enter the valid choice\n");
                            break;
                        }
                    }
                }
            }
            case 2: {
                customer();
                break;
            }
            case 3: {
                cout<<"\nExiting.. Thank You visit again!\n";
                return 0;
            }
            default: {
                printf("\nPlease Enter the valid choice\n");
                break;
            }
        }

    }
}