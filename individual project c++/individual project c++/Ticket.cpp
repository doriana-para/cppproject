
#include "Ticket.h"
#include <cstdlib>
using namespace std;

Ticket::Ticket(){
    this-> name = "";
    this->id = -1;
    this->row_num = -1;
    this->col_num = -1;
    this->zoneName = "";
}

Ticket::Ticket(string name, int row_num, int col_num, string zoneName){
    this->name = name;
    this->row_num = row_num;
    this->col_num = col_num;
    this->zoneName = zoneName;
    srand(time(NULL));
    this->id = rand();
}

Ticket::Ticket(const Ticket& t) {
    this->name = t.name;
    this->row_num = t.row_num;
    this->col_num = t.col_num;
    this->zoneName = t.zoneName;
    this->id = t.id;
}

Ticket::~Ticket() {
    // No dynamic memory to free
}

void Ticket::operator=(const Ticket t) {
    this->name = t.name;
    this->id = t.id;
    this->row_num = t.row_num;
    this->col_num = t.col_num;
    this->zoneName = t.zoneName;
}

bool Ticket::operator!() {
    return (row_num == -1 && col_num == -1);
}

bool Ticket::operator<(Ticket t) {
    return this->id < t.id;
}

//These are the necessary functions for reading and writing data from a binary file
void Ticket::writeToFile(ofstream& outputFile) const {
    //This adds the ticket name to the binary file
    outputFile.write(reinterpret_cast<const char*>(&name), sizeof(name));
    outputFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
    outputFile.write(reinterpret_cast<const char*>(&row_num), sizeof(row_num));
    outputFile.write(reinterpret_cast<const char*>(&col_num), sizeof(col_num));
    outputFile.write(reinterpret_cast<const char*>(&zoneName), sizeof(zoneName));
}

    // Function to read object data from a binary file
    //
bool Ticket::readFromFile(ifstream& inputFile) {
    // This adds the name to the ticket
    if (!inputFile.read(reinterpret_cast<char*>(&name), sizeof(name)))
        return false;
    // This adds the id number to the ticket
    if (!inputFile.read(reinterpret_cast<char*>(&id), sizeof(id)))
        return false;
    // This adds the row number to the ticket
    if (!inputFile.read(reinterpret_cast<char*>(&row_num), sizeof(row_num)))
        return false;
    // This adds the col number to the ticket
    if (!inputFile.read(reinterpret_cast<char*>(&col_num), sizeof(col_num)))
        return false;
    // This adds the zone name to the ticket
    if (!inputFile.read(reinterpret_cast<char*>(&zoneName), sizeof(zoneName)))
        return false;
    
    // If all reads were successful, return true
    return true;
}


void Ticket::check(Ticket* ticket_array, int size_of_ticket_array) {
    for (int i = 0; i < size_of_ticket_array; i++) {
        if (this->id == ticket_array[i].id) {
            newId();
            i = 0;
        }
    }
}

//virtual method

 void Ticket::printID() {
    cout << this->id;
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

void Ticket::setName(string name) {
    this->name = name;
}


void operator>>(istream& input, Ticket& t) {

    cout << endl << "Create a new Ticket ";
    cout << endl << "Enter Zone Name: ";

    cout << "The row seat number is : ";
    input >> t.row_num;
    cout << "The col seat number is : ";
    input >> t.col_num;
    cout << "The zone name is : ";
    input >> t.zoneName;
}


ostream& operator<<(ostream& output, const Ticket& t) {
    cout << "--TICKET--" << endl;

    output << "Your unique ID Number: " << t.id << endl;
    output << "The name is: " << t.name << endl;
    output << "The row seat number is: " << t.row_num << endl;
    output << "The col seat number is: " << t.col_num << endl;
    output << "The zone number is: " << t.zoneName << endl;

    return output;


}


class Ticket_VIP:public Ticket{

public:
    Ticket_VIP() {
        this->name = "";
        this->id = -1;
        this->row_num = -1;
        this->col_num = -1;
        this->zoneName = "";
    }

    Ticket_VIP(string name, int row_num, int col_num, string zoneName) {
        this->name = name;
        this->row_num = row_num;
        this->col_num = col_num;
        this->zoneName = zoneName;
        srand(time(NULL));
        this->id = rand();
    }

    void printID() {
        cout << this->id;
    }

};