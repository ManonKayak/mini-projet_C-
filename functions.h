//
// Created by 33783 on 09/01/2025.
//

#ifndef MINI_PROJET_C__FUNCTIONS_H
#define MINI_PROJET_C__FUNCTIONS_H

#include <iostream>
using namespace std;

class Record{
private:
    int account_number, phone_number, balance;
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

    int getBalance() const {
        return balance;
    }

    void setBalance(int balance) {
        Record::balance = balance;
    }

    const string &getFirstname() const {
        return firstname;
    }

    void setFirstname(const string &firstname) {
        Record::firstname = firstname;
    }

    const string &getLastname() const {
        return lastname;
    }

    void setLastname(const string &lastname) {
        Record::lastname = lastname;
    }
};

// get all the records in the file
Record* get_all_records(FILE file);
// add record at the end of file
void add_record(Record record, FILE file);
// read file and display all the records
void display_records(Record* records);
// ask what we xant to change in the record, change it and save it at its old place in file
void update_record(Record record, FILE file);
// remove record from records array and save file
void delete_record(Record record, FILE file);
// display number of records, ask an account number and display record associated with it
Record search_record(Record* record);
// save records in file
void save_record(Record* records, FILE file);

#endif //MINI_PROJET_C__FUNCTIONS_H