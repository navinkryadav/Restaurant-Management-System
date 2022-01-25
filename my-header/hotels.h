//
// Created by navin on 02-11-2021.
//

#ifndef RESTAURANT_MANAGEMENT_SYSTEM_HOTELS_H
#define RESTAURANT_MANAGEMENT_SYSTEM_HOTELS_H

#include <string>
#include <utility>

using namespace std;

class Hotels {
public:
    string hotel_name;

    class Foods {
    public:
        int serial_no{};
        string food_name;
        float price{};
        Foods *next{};
    } *food_item = nullptr;

    Hotels *next{};
};

Hotels *head = nullptr;

void cart(float total);

Hotels *search_hotels(const string &hotel_name) {
    Hotels *temp = head;
    while (temp != nullptr) {
        if (temp->hotel_name == hotel_name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}


void add_hotel(const string &hotel_name) {
    if (head == nullptr) {
        auto *new_hotel = new Hotels();
        new_hotel->hotel_name = hotel_name;
        new_hotel->next = nullptr;
        head = new_hotel;
        cout << "\nHotel " << hotel_name << " added successfully!! \n";
        return;
    }
    Hotels *result = search_hotels(hotel_name);
    if (result != nullptr) {
        cout << "\nHotel " << hotel_name << " already there!! \n";
        return;
    } else {
        auto *new_hotel = new Hotels();
        new_hotel->hotel_name = hotel_name;
        new_hotel->next = nullptr;
        Hotels *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new_hotel;
        cout << "\nHotel " << hotel_name << " added successfully!! \n";
    }
}


Hotels::Foods *search_foods(Hotels *hotel, int serial_no) {
    if (hotel == nullptr) {
        cout << "\nThere is no food available\n";
        return nullptr;
    }

    Hotels::Foods *temp = hotel->food_item;

    if (temp == nullptr) {
        cout << "\nNo food available yet!!\n";
        return nullptr;
    }

    while (temp != nullptr) {
        if (temp->serial_no == serial_no)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}


void display_hotels() {
    Hotels *temp = head;
    cout << "\n------------------Available Hotels----------------\n";
    while (temp != nullptr) {
        cout << temp->hotel_name << endl;
        temp = temp->next;
    }
}


void display_foods(Hotels *hotel) {
    Hotels *temp = hotel;
    Hotels::Foods *fd;

    if (head == nullptr) {
        cout << "\nSorry! currently we don't any hotel to show the foods\n";
        return;
    }
    cout << "\n-------------------Available Foods in " << hotel->hotel_name << ":-------------------\n";
    fd = temp->food_item;
    while (fd != nullptr) {
        cout << fd->serial_no << ") " << fd->food_name << " RS." << fd->price << endl;
        fd = fd->next;
    }

}

void display_all_food() {
    Hotels *temp = head;
    while (temp != nullptr) {
        display_foods(temp);
        temp = temp->next;
    }
}

Hotels *add_food_item(const string &hotel_name, int serial_no, string food_name, float price) {

    auto *fd = new Hotels::Foods();
    fd->serial_no = serial_no;
    fd->food_name = move(food_name);
    fd->price = price;
    fd->next = nullptr;

    if (head == nullptr) {
        auto *new_hotel = new Hotels();
        new_hotel->hotel_name = hotel_name;
        new_hotel->food_item = fd;
        head = new_hotel;
        return head;
    } else {
        Hotels *result = search_hotels(hotel_name);

        if (result == nullptr) {

            auto *new_hotel = new Hotels();
            new_hotel->hotel_name = hotel_name;
            new_hotel->food_item = fd;

            Hotels *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new_hotel;

        } else {
            Hotels::Foods *fd1 = result->food_item;
            while (fd1->next != nullptr)
                fd1 = fd1->next;
            fd1->next = fd;

        }
        return result;
    }

}


void food_order() {

    int quantity;
    int food_choice;
    float total = 0;
    Hotels *temp;
    Hotels::Foods *fd;
    string hotel_choice;

    if (head == nullptr) {
        cout << "\nSorry!! there are no hotels available at this moment try after some time\n";
        return;
    }

    display_hotels();

    cout << "\nPlease Enter the hotel name:\n";

    cin >> hotel_choice;

    temp = search_hotels(hotel_choice);


    if (temp == nullptr) {
        cout << "Please Enter the ";

        cout << "valid choice\n\n";

        food_order();
        return;
    } else {
        int confirm;
        while (true) {
            if (temp->food_item == nullptr) {
                cout << "\nThere is no food available at this moment"
                        " on this hotel please a select different hotel\n";
                food_order();
                return;
            }
            food_section:
            display_foods(temp);
            cout << "\nEnter your choice:\n";
            cin >> food_choice;
            fd = search_foods(temp, food_choice);
            if (fd == nullptr) {
                cout << "\nNo such food available\nEnter a valid food name\n";
            } else {
                cout << "\nPlease Enter the Count of " << fd->food_name << "\t";
                cin >> quantity;
                total += (float) quantity * fd->price;
                confirm:
                cout << "\nDo you wish to order anything else (y=1/n=0):\t";
                cin >> confirm;
                if (confirm == 1)
                    goto food_section;
                else if (confirm == 0) {
                    cart(total);
                    break;
                } else {
                    cout << "\nEnter valid input";
                    goto confirm;
                }

            }
        }
    }

}


void cart(float total) {
    int choice;

    cout << "\n\n\n\n--------------Cart";

    cout << "----------------";

    cout << "\nYour Total Order ";

    cout << "Amount is \n" << total;

    cout << "\n\nDo You wish to ";

    cout << "order (y=1/n=0):";

    cin >> choice;

    if (choice == 1) {

        cout << "\n\nThank You for your ";

        cout << "order!! Your Food is on ";

        cout << "the way. Welcome again!!\n\n";

        // exit(1);

        return;

    } else if (choice == 0) {

        int confirm;

        cout << "Do You want to exit -1";

        cout << "or Go back -0";

        cin >> confirm;

        if (confirm == 1) {

            cout << "\n\nOops! Your order is ";

            cout << "cancelled!! Exiting.. ";

            cout << "Thank You visit again!\n";

             exit(1);

        } else {

            cout << "\n\nThank You\n\n";

        }

    } else {

        cout << "\n\nPlease Enter the ";

        cout << "correct choice\n\n";

        cart(total);

    }
}

Hotels *delete_hotel(const string &hotel_name) {
    Hotels *temp = head;
    if (temp == nullptr) {
        cout << "\nSorry!! there is no hotel available yet\n";
        return nullptr;
    }
    if (temp->hotel_name == hotel_name) {
        if (temp->next == nullptr)
            head = nullptr;
        else {
            head = head->next;
        }
        cout << "\nHotel " << hotel_name << " deleted successfully!!\n";
        return temp;
    }
    Hotels *result = search_hotels(hotel_name);
    if (result == nullptr) {
        cout << "\nNo such hotel available\n";
        return nullptr;
    }
    temp = head;
    while (temp->next != result)
        temp = temp->next;
    temp->next = result->next;
    cout << "\nHotel " << hotel_name << " deleted successfully!!\n";
    return temp;
}


Hotels *delete_food(const string &hotel_name, int serial_no) {

    if (head == nullptr) {
        cout << "\nSorry!! there is no hotel available yet\n";
        return nullptr;
    }

    Hotels *result = search_hotels(hotel_name);
    if (result == nullptr) {
        cout << "\nNo such hotel available\n";
        return nullptr;
    }
    if (result->food_item == nullptr) {
        cout << "\nNo food added in this hotel yet!!\n";
        return nullptr;
    }
    if (result->food_item->serial_no == serial_no) {
        if (result->food_item->next == nullptr)
            result->food_item = nullptr;
        else {
            result->food_item = result->food_item->next;
        }
        cout << "\nFood item : " << result->food_item->food_name << " Rs: " << result->food_item->price;
        cout << " deleted successfully!! from hotel: " << hotel_name;
        return result;
    }
    Hotels::Foods *fd = search_foods(result, serial_no);
    if (fd == nullptr) {
        cout << "\nNo food available at: " << serial_no << " serial number\n";
        return nullptr;
    }
    Hotels::Foods *pre = result->food_item;
    while (pre->next != fd)
        pre = pre->next;
    pre->next = fd->next;

    cout << "\nFood item : " << fd->food_name << " Rs: " << result->food_item->price;
    cout << " deleted successfully!! from hotel: " << hotel_name;
    return result;
}

#endif //RESTAURANT_MANAGEMENT_SYSTEM_HOTELS_H
