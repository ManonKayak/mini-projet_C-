//
// Created by 33783 on 09/01/2025.
//

#include <sstream>
#include "functions.h"
using namespace std;
const string file_path = "bank_records.txt";

// get all the records in the file
vector<Record> get_all_records(){
    cout << "int get all";
    vector<Record> records;
    ifstream bank_file;
    bank_file.open(file_path);

    string line;
    while(getline(bank_file, line)){
        //does the same thing as split = split(line, " ") in other languages
        vector<string> split;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ' ')) {
            split.push_back(token);
        }
        cout << "the line:" << line;
        if(split.size() == 5) {
            Record new_record = Record(stoi(split.at(0)), split.at(1), split.at(2), stoi(split.at(3)), stof(split.at(4)));
            records.emplace_back(new_record);
        }
    }

    bank_file.close();

    return records;
}

// add record at the end of file
void add_record(){
    cout << "in add";
    vector<Record> records = get_all_records();

    Record record = Record();
    //records->at(records->size())= record;
    // to test
    records.emplace_back(record);

    save_record(records);
}

// read file and display all the records
void display_records(){
    cout << "in display";
    vector<Record> records = get_all_records();

    for(Record record : records) {
        display_record(record);
    }
}

// display one record
void display_record(Record record){
    cout << "Account number:" << record.getAccountNumber() << endl;
    cout << "Phone number:" << record.getPhoneNumber() << endl;
    cout << "Balance:" << record.getBalance() << endl;
    cout << "First name:" << record.getFirstname() << endl;
    cout << "Last name:" << record.getLastname() << endl;
    cout << "\n";
}

// ask what the user want to change in the record, change it and save it at its old place in file
void update_record(){
    vector<Record> records = get_all_records();

    int index = search_record(records);
    if(index != -1) {
        Record record_to_change = records.at(index);

        cout << "Select the information you want to change:" << endl;
        cout << "1 - Account number" << endl;
        cout << "2 - Phone number" << endl;
        cout << "3 - Balance" << endl;
        cout << "4 - First name" << endl;
        cout << "5 - Last name\n" << endl;


        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the new account number:" << endl;
                int account_nb;
                cin >> account_nb;
                record_to_change.setAccountNumber(account_nb);
                break;
            case 2:
                cout << "Enter the new phone number:" << endl;
                int phone_number;
                cin >> phone_number;
                record_to_change.setPhoneNumber(phone_number);
                break;
            case 3:
                cout << "Enter the new balance:" << endl;
                float balance;
                cin >> balance;
                record_to_change.setBalance(balance);
                break;
            case 4: {
                cout << "Enter the first name:" << endl;
                string first_name;
                cin >> first_name;
                record_to_change.setFirstname(first_name);
                break;
            }
            case 5: {
                cout << "Enter the last name:" << endl;
                string last_name;
                cin >> last_name;
                record_to_change.setLastname(last_name);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        records.at(index) = record_to_change;

        save_record(records);
    }
}

// remove record from records file
void delete_record(){
    vector<Record> records = get_all_records();

    int index = search_record(records);
    if(index != -1) records.erase(records.begin() + index);

    save_record(records);
}

// display number of records, ask an account number and display record associated with it
int search_record(vector<Record> records){
    cout << "Enter account number:";
    int account_nb;
    cin >> account_nb;

    for(int i = 0; i < records.size(); i++){
        if(records.at(i).getAccountNumber() == account_nb) return i;
    }

    cout << "This account doesn't exist!" << endl;
    return -1;
}

// save records in file
void save_record(vector<Record> records){
    ofstream bank_file;
    bank_file.open(file_path);

    for(Record record : records) {
        bank_file << record.getAccountNumber() << " ";
        bank_file << record.getFirstname() << " ";
        bank_file << record.getLastname() << " ";
        bank_file << record.getPhoneNumber() << " ";
        bank_file << record.getBalance() << "\n";
    }

    bank_file.close();
}


