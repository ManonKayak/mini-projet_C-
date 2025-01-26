#include <iostream>
#include "functions.h"
using namespace std;


int main() {
    bool run = true;

    while(run) {
        cout << "***Account Information System***" << endl;
        cout << "Select option below" << endl;
        cout << "1-->Add record to file" << endl;
        cout << "2-->Show record from file" << endl;
        cout << "3-->Search record from file" << endl;
        cout << "4-->Update record" << endl;
        cout << "5-->Delete record" << endl;
        cout << "6-->Quit" << endl;
        cout << "\n";

        int choice;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                add_record();
                break;
            }
            case 2: {
                display_records();
                break;
            }
            case 3: {
                vector<Record> records = get_all_records();
                int index = search_record(records);
                display_record(records.at(index));
                break;
            }
            case 4: {
                update_record();
                break;
            }
            case 5: {
                delete_record();
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
