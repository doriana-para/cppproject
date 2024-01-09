#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Ticket {
private:

    protected:
    int id;
    int row_num;
    int col_num;
    string zoneName;
    string name;
    int seat_number;

public:
    Ticket();
    Ticket(string name, int row_num, int col_num, string zoneName);
    Ticket(const Ticket& t);
    ~Ticket();

    void operator=(const Ticket t);
    bool operator!();
    bool operator<(Ticket t);

    void writeToFile(ofstream& outputFile) const;
    bool readFromFile(ifstream& inputFile);

    void check(Ticket* ticket_array, int size_of_ticket_array);
    virtual void printID();
    void newId();
    void writing_bin();

    int getId();
    int getRowNumber();
    int getColNumber();
    string getZoneName();
    string getName();

    void setId(int id);
    void setRowNumber(int row_num);
    void setColNumber(int col_num);
    void setZoneName(string zoneName);
    void setName(string);

    friend void operator>>(istream& input, Ticket& t);
    friend ostream& operator<<(ostream& output, const Ticket& t);

};