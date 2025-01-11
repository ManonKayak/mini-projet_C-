//
// Created by 33783 on 09/01/2025.
//

#include <iostream>
#include "functions.h"
using namespace std;

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


