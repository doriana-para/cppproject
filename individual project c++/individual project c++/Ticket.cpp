
#include "Ticket.h"
#include <cstdlib>
using namespace std;

Ticket::Ticket() : name("") {
    this->id = -1;
    this->row_num = -1;
    this->col_num = -1;
    this->zoneName = "";
}

Ticket::Ticket(string name, int row_num, int col_num, string zoneName) : name(name) {
    this->row_num = row_num;
    this->col_num = col_num;
    this->zoneName = zoneName;
    srand(time(NULL));
    this->id = rand();
}

Ticket::Ticket(const Ticket& t) {
    this->row_num = t.row_num;
    this->col_num = t.col_num;
    this->zoneName = t.zoneName;
    this->id = t.id;
}

Ticket::~Ticket() {
    // No dynamic memory to free
}

void Ticket::operator=(const Ticket t) {
    this->id = t.id;
    this->row_num = t.row_num;
    this->col_num = t.col_num;
    this->zoneName = t.zoneName;
}

bool Ticket::operator!() {
    return seat_number == -1;
}

bool Ticket::operator<(Ticket t) {
    return this->id < t.id;
}

void Ticket::check(Ticket* ticket_array, int size_of_ticket_array) {
    for (int i = 0; i < size_of_ticket_array; i++) {
        if (this->id == ticket_array[i].id) {
            newId();
            i = 0;
        }
    }
}



int Ticket::getId() {
    return this->id;
}


int Ticket::getRowNumber() {
    return this->row_num;
}

int Ticket::getColNumber()
{
    return this->col_num;
}
string Ticket::getZoneName() {
    return this->zoneName;
}

string Ticket::getName() {
    return this->name;
}



void Ticket::newId() {
    this->id = rand();
}

void Ticket::setId(int id) {
    this->id = id;
}


void Ticket::setRowNumber(int row) {
    this->row_num = row;
}

void Ticket::setColNumber(int col) {
    this->col_num = col;
}

void Ticket::setZoneName(string zoneName) {
    this->zoneName = zoneName;
}


void operator>>(istream& input, Ticket& t) {
    
    cout << endl << "Create a new Ticket ";
    cout << endl << "Enter Zone Name: ";

    cout << "The seat number is : ";
    input >> t.seat_number;
    cout << "The zone name is : ";
    input >> t.zoneName;
}
   

    ostream& operator<<(ostream& output, const Ticket& t) {

        output << "Your unique ID Number: " << t.id << endl;
        output << "The name is: " << t.name << endl;
        output << "The seat number is: " << t.seat_number << endl;
        output << "The zone number is: " << t.zoneName << endl;

        return output;

    
}





