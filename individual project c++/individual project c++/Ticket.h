#pragma once
#include <iostream>
#include <string>
using namespace std;
class Ticket {
private:
    int id;
    int row_num;
    int col_num;
    string zoneName;
    const string name;
    int seat_number;

public:
    Ticket();
    Ticket(string name, int row_num, int col_num, string zoneName);
    Ticket(const Ticket& t);
    ~Ticket();

    void operator=(const Ticket t);
    bool operator!();
    bool operator<(Ticket t);

    void check(Ticket* ticket_array, int size_of_ticket_array);
    void newId();

    int getId();
    int getRowNumber();
    int getColNumber();
    string getZoneName();
    string getName();

    void setId(int id);
    void setRowNumber(int row_num);
    void setColNumber(int col_num);
    void setZoneName(string zoneName);

    friend void operator>>(istream& input, Ticket& t);
    friend ostream& operator<<(ostream& output, const Ticket& t);
 
};