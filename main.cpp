#include <iostream>
#include "functions.h"
using namespace std;


int main() {
    bool run = true;
    // have to open txt file!!!!!!!!!!!!!!!!!!!!!!
    FILE bank_file;

    while(run) {
        cout << "***Account Information System***" << endl;
        cout << "Select option below" << endl;
        cout << "1-->Add record to file" << endl;
        cout << "2-->Show record from file" << endl;
        cout << "3-->Search record from file" << endl;
        cout << "4-->Update record" << endl;
        cout << "5-->Delete record" << endl;
        cout << "6-->Quit" << endl;

        int choice;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                Record new_record = Record();
                add_record(new_record, bank_file);
                break;
            }
            case 2: {
                display_records(get_all_records(bank_file));
                break;
            }
            case 3: {
                search_record(get_all_records(bank_file));
                break;
            }
            case 4: {
                update_record(search_record(get_all_records(bank_file)), bank_file);
                break;
            }
            case 5: {
                delete_record(search_record(get_all_records(bank_file)), bank_file);
                break;
            }
            case 6: {
                cout << "Goodbye !" << endl;
                run = false;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}
