//
// Created by 33783 on 09/01/2025.
//

#ifndef MINI_PROJET_C__FUNCTIONS_H
#define MINI_PROJET_C__FUNCTIONS_H

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Record{
private:
    int account_number, phone_number;
    float balance;
    string firstname, lastname;

public:
    Record(){
        cout << "Enter account number:" << endl;
        cin >> Record::account_number;
        cout << "Enter first name:" << endl;
        cin >> Record::firstname;
        cout << "Enter last name:" << endl;
        cin >> Record::lastname;
        cout << "Enter phone number:" << endl;
        cin >> Record::phone_number;
        cout << "Enter balance:" << endl;
        cin >> Record::balance;

    }

    Record(int account_number, string firstname, string lastname, int phone_number, float balance){
        Record::account_number = account_number;
        Record::firstname = firstname;
        Record::lastname = lastname;
        Record::phone_number = phone_number;
        Record::balance = balance;

    }

    int getAccountNumber() const {
        return account_number;
    }

    void setAccountNumber(int accountNumber) {
        account_number = accountNumber;
    }

    int getPhoneNumber() const {
        return phone_number;
    }

    void setPhoneNumber(int phoneNumber) {
        phone_number = phoneNumber;
    }

    float getBalance() const {
        return balance;
    }

    void setBalance(float balance) {
        Record::balance = balance;
    }

    string &getFirstname(){
        return firstname;
    }

    void setFirstname(string firstname) {
        Record::firstname = firstname;
    }

    string &getLastname(){
        return lastname;
    }

    void setLastname(string lastname) {
        Record::lastname = lastname;
    }
};

// get all the records in the file
vector<Record> get_all_records();
// add record at the end of file
void add_record();
// read file and display all the records
void display_records();
// display one record
void display_record(Record record);
// ask what we xant to change in the record, change it and save it at its old place in file
void update_record();
// remove record from records array and save file
void delete_record();
// display number of records, ask an account number and display record associated with it
int search_record(vector<Record> records);
// save records in file
void save_record(vector<Record> records);

#endif //MINI_PROJET_C__FUNCTIONS_H