//
// Created by navin on 02-11-2021.
//

#ifndef RESTAURANT_MANAGEMENT_SYSTEM_ADMIN_H
#define RESTAURANT_MANAGEMENT_SYSTEM_ADMIN_H

#include <string>
#include <utility>
#include "hotels.h"

using namespace std;

class Admin {
public:
    string uname{};
    string mobile{};
    string email{};
    string password{};
    int age{};

    Admin *next{};
};

Admin *admin = nullptr;

int validate();


//pass key require to signup as a admin
string passkey = "Hotel_Admin_246";

string temp_name;
string temp_mobile, temp_email;
string temp_password1, temp_password2;
int temp_age;

void show_admin() {
    Admin *temp = admin;
    if (temp == nullptr) {
        cout << "\nNo admin assigned yet!!\n";
        return;
    }
    cout << "\nName\tAge\tEmail\t\t\tMobile\n";
    while (temp != nullptr) {
        cout << temp->uname << "\t" << temp->age << "\t" << temp->email << "\t\t" << temp->mobile << endl;
        temp = temp->next;
    }
}

void add_as_admin(string name, string mobile, const string &email, const string &password, int age) {
    Admin *temp = admin;
    while (temp != nullptr) {
        if (temp->email == email && temp->password == password) {
            cout << "\n\nAccount Already Existed. Please Login !!\n\n";
            return;
        }
        temp = temp->next;
    }
    auto *new_admin = new Admin();
    new_admin->uname = std::move(name);
    new_admin->mobile = std::move(mobile);
    new_admin->email = email;
    new_admin->password = password;
    new_admin->age = age;
    new_admin->next = nullptr;
    temp = admin;
    if (temp == nullptr) {
        admin = new_admin;
    } else {
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new_admin;
    }
    cout << "\n\n\nAccount Successfully Created!!\n\n";
}

void admin_menu() {
    cout << "\t\t\t\t\t\t\t1) Display Hotels " << endl;
    cout << "\t\t\t\t\t\t\t2) Display food item of all hotel " << endl;
    cout << "\t\t\t\t\t\t\t3) Add new a hotel " << endl;
    cout << "\t\t\t\t\t\t\t4) Add new food items to a hotel " << endl;
    cout << "\t\t\t\t\t\t\t5) Search a hotel " << endl;
    cout << "\t\t\t\t\t\t\t6) Search a food in a hotel " << endl;
    cout << "\t\t\t\t\t\t\t7) Delete food items from a hotel " << endl;
    cout << "\t\t\t\t\t\t\t8) Delete a hotel " << endl;
    cout << "\t\t\t\t\t\t\t9) Go Back ! \n" << endl;
    cout << "\t\t\t\t\t\t\t10) View all admin " << endl;
    cout << "\t\t\t\t\t\t\t   Enter Your Choice ---> " << endl;
}

void signup() {
    string pass;
    cout << "\nEnter your pass key to signup as a admin:\t";
    cin >> pass;
    if (pass == passkey) {
        cout << "\nEnter Your name\t";
        cin >> temp_name;
        cout << "\nEnter Your Age\t";
        cin >> temp_age;
        cout << "\nEnter Your Email\t";
        cin >> temp_email;
        cout << "\nEnter Password\t";
        cin >> temp_password1;
        cout << "\nConfirm Password\t";
        cin >> temp_password2;
        cout << "\nEnter Your Mobile Number\t";
        cin >> temp_mobile;

// Function Call to validate the user creation
        int x = validate();
        if (x == 1)
            add_as_admin(temp_name, temp_mobile, temp_email, temp_password1, temp_age);
    } else {
        cout << "\nInvalid passkey!\n";
    }
}


int validate() {

    int flag = 1;
    int success;
    // Validate the name
    for (int i = 0; i < temp_name.length(); i++) {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
              || (temp_name[i] >= 'A' && temp_name[i] <= 'Z'))) {
            cout << "\nPlease Enter the valid Name\n";
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        int count = 0;
        // Validate the Email ID
        for (int i = 0; i < temp_email.length(); i++) {
            if (temp_email[i] == '@'
                || temp_email[i] == '.')
                count++;
        }
        if (count >= 2 && temp_email.length() >= 5) {
            // Validating the Password and Check whether it matches with Conform Password
            if (temp_password1 == temp_password2) {
                if (temp_password1.length() >= 8 && temp_password1.length() <= 12) {
                    int caps = 0;
                    int small = 0;
                    int numbers = 0;
                    int special = 0;

                    for (int i = 0; i < temp_password1.length(); i++) {
                        if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z')
                            caps++;
                        else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z')
                            small++;
                        else if (temp_password1[i] >= '0' && temp_password1[i] <= '9')
                            numbers++;
                        else if (temp_password1[i] == '@' || temp_password1[i] == '&'

                                 || temp_password1[i] == '#' || temp_password1[i] == '*')
                            special++;
                    }
                    if (caps >= 1 && small >= 1
                        && numbers >= 1 && special >= 1) {
                        // Validating the Input age
                        if ((temp_age != 0) && (temp_age >= 0)) {
                            // Validating the Input mobile
                            // number
                            if (temp_mobile.length() == 10) {
                                for (int i = 0; i < 10; i++) {
                                    if (temp_mobile[i] >= '0' && temp_mobile[i] <= '9') {
                                        // Success is assigned with value 1, Once every inputs are correct.
                                        success = 1;
                                    } else {
                                        cout << "\n\nPlease Enter Valid Mobile Number\n\n";
                                        return 0;
                                    }
                                }
                                if (success == 1)
                                    return 1;
                            } else {
                                cout << "\n\nPlease Enter the 10 digit mobile number\n\n";
                                return 0;
                            }

                        } else {
                            cout << "\n\nPlease Enter the valid age\n\n";
                            return 0;
                        }
                    } else {
                        cout << "\n\nPlease Enter the strong password, Your ";
                        cout << "password must contain atleast one uppercase, ";
                        cout << "Lowercase, Number and special character\n\n";
                        cout << "";
                        return 0;
                    }
                } else {
                    cout << "\nYour Password is very short\nLength must between 8 to 12\n\n";
                    return 0;
                }
            } else {
                cout << "\nPassword Mismatch\n\n";
                return 0;
            }

        } else {
            cout << "\nPlease Enter Valid E-Mail\n\n";
            return 0;
        }
    }
    return 0;
}


void login() {
    if (admin == nullptr) {
        cout << "\nSorry!! currently there is no admin assign yet kindly signup first\n";
    } else {
        Admin *temp = admin;
        cout << "\n\nLOGIN\n\n";
        cout << "\nEnter Your Email:\t";
        cin >> temp_email;
        cout << "Enter Your Password:\t";
        cin >> temp_password1;
        int choice;
        int flag = 1;
        while (temp != nullptr) {
            // Check whether the input email is already existed or not
            if (temp->email == temp_email) {
                flag = 0;
                // Check whether the password is matched with the email or not
                if (temp->password == temp_password1) {
                    cout << "\n\nWelcome! " << temp->uname;
                    cout << "\nYour are successfully logged in\n\n";
                    admin_menu:
                    admin_menu();
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            display_hotels();
                            goto admin_menu;
                        }
                        case 2: {
                            display_all_food();
                            goto admin_menu;
                        }
                        case 3: {
                            string hotel_name;
                            cout << "\nEnter hotel name: \t";
                            cin >> hotel_name;
                            add_hotel(hotel_name);
                            goto admin_menu;
                        }
                        case 4: {
                            string hotel_name;
                            string food_name;
                            float price;
                            int serial_no;
                            cout << "\nEnter hotel name:\t";
                            cin >> hotel_name;
                            cout << "Enter serial number of the food:\t";
                            cin >> serial_no;
                            cout << "Enter Food name:\t";
                            cin >> food_name;
                            cout << "Enter price:\t";
                            cin >> price;
                            add_food_item(hotel_name, serial_no, food_name, price);
                            goto admin_menu;
                        }
                        case 5: {
                            string hotel_name;
                            cout << "\nEnter hotel name to be searched:\t";
                            cin >> hotel_name;
                            Hotels *result = search_hotels(hotel_name);
                            if (result == nullptr)
                                cout << "\nNot found\n";
                            else
                                display_foods(result);
                            goto admin_menu;
                        }
                        case 6: {
                            string hotel_name;
                            int serial_no;
                            cout << "\nEnter hotel name:\t";
                            cin >> hotel_name;
                            Hotels *result = search_hotels(hotel_name);
                            if (result == nullptr)
                                cout << "\nHotel not found\n";
                            else {
                                cout << "Enter serial number of food:";
                                cin >> serial_no;
                                auto *fd = search_foods(result, serial_no);
                                if (fd == nullptr)
                                    cout << "\nFood not found\n";
                                else {
                                    cout << "\nSerial No: " << fd->serial_no << " Food item: " << fd->food_name
                                         << " Price RS. " << fd->price << endl;
                                }
                            }
                            goto admin_menu;
                        }
                        case 7: {
                            string hotel_name;
                            int serial_no;
                            cout << "\nEnter hotel name: ";
                            cin >> hotel_name;
                            cout << "Enter serial no of the food: ";
                            cin >> serial_no;
                            delete_food(hotel_name, serial_no);
                            goto admin_menu;
                        }
                        case 8: {
                            string hotel_name;
                            cout << "Enter hotel name to be deleted: ";
                            cin >> hotel_name;
                            delete_hotel(hotel_name);
                            goto admin_menu;
                        }
                        case 9: {
                            break;
                        }
                        case 10: {
                            show_admin();
                            break;
                        }
                        default: {
                            cout << "Please Enter the valid choice\n\n";
                            goto admin_menu;
                        }
                    }
                    break;
                } else {
                    cout << "\n\nInvalid Password! ";
                    cout << "Please Enter the correct password\n\n";
//                main();
                    break;
                }
            }
            temp = temp->next;
        }
        if (flag == 1)
            cout << "\n\nAccount doesn't exist, Please signup!!\n\n";
    }
}

void hotel_initialize() {
    add_food_item("Paradise", 1, "Hot and Sour Soup", 100);
    add_food_item("Paradise", 2, "Manchow Soup", 200);
    add_food_item("Paradise", 3, "Manchurian Noodles", 150);

    add_food_item("Plaza", 1, "Fried Rice", 180);
    add_food_item("Plaza", 2, "Hakka Noodles", 80);
    add_food_item("Plaza", 3, "Chicken Fried Rice", 190);

    add_food_item("Royal", 1, "Hakka Noodles", 80);
    add_food_item("Royal", 2, "Chicken Curry", 120);
    add_food_item("Royal", 3, "Mutton Curry", 160);

    add_as_admin("navin", "9334853044", "navin@gmail.com", "navin@RMS21", 18);

}


#endif //RESTAURANT_MANAGEMENT_SYSTEM_ADMIN_H
