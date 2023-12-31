
#include "Location.h"
using namespace std;
Location::Location() {

    size = 0;
    this->number_seats = 1;
    this->rows = 1;
    this->time = -1;
    this->date = "";
    seatMap = new int* [1]; //first pointer gets assigned an array of size rows
    for (int i = 0; i < rows; i++) { //adding the column array to every row
        seatMap[0] = new int[1]; //each pointer in seatMap is pointing to a new array
    }

    //zone_locations = new char* [1]; //first pointer gets assigned an array of size rows
    //for (int i = 0; i < rows; i++) { //adding the column array to every row
    cout << "test1";
    //zone_locations[0] = new char[1]; //each pointer in zone_locations is pointing to a new array
//}
    this->zone = new ZoneInfo[this->number_seats];
}

Location::Location(int number_seats, int rows, int time, string date) {
    size = 0;
    this->number_seats = number_seats;
    this->rows = rows;
    this->time = time;
    this->date = date;
    this->zone = nullptr;


    seatMap = new int* [rows]; //first pointer gets assigned an array of size rows
    for (int i = 0; i < rows; i++) { //adding the column array to every row
        seatMap[i] = new int[number_seats / rows]; //each pointer in seatMap is pointing to a new array
    }


    zone_locations = new char* [rows]; //first pointer gets assigned an array of size rows
    for (int i = 0; i < rows; i++) { //adding the column array to every row
        zone_locations[i] = new char[number_seats / rows]; //each pointer in zone_locations is pointing to a new array
    }
}

Location::Location(const Location& loc) {
    this->number_seats = loc.number_seats;
    this->rows = loc.rows;
    this->time = loc.time;
    this->date = loc.date;


    this->seatMap = new int* [this->rows]; //first pointer gets assigned an array of size rows
    for (int i = 0; i < this->rows; i++) { //adding the column array to every row
        this->seatMap[i] = new int[this->rows / this->number_seats]; //each pointer in seatMap is pointing to a new array
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->number_seats / this->rows; j++) {
            this->seatMap[i][j] = loc.seatMap[i][j]; //copying the value inside loc.seatMap to this->seatMap because this points by value, not referenc
        }
    }
}

Location::~Location() {
    /* for (int i = 0; i < rows; i++) {
             delete[] seatMap[i];
         }
         delete[] seatMap;*/

    if (this->zone != nullptr) {
        delete[] this->zone;
    }
    /*for (int i = 0; i < rows; i++) {
        delete[] zone_locations[i];
    }
    delete[] zone_locations;*/
}

void Location::operator=(const Location& l) {
    this->number_seats = l.number_seats;
    this->rows = l.rows;
    this->time = l.time;
    this->date = l.date;
    this->zone = l.zone;
    this->seatMap = new int* [this->rows]; //first pointer gets assigned an array of size rows
    for (int i = 0; i < this->rows; i++) { //adding the column array to every row
        this->seatMap[i] = new int[this->rows / this->number_seats]; //each pointer in seatMap is pointing to a new array
    }
    for (int i = 0; i < this->rows; i++) { //adding the column array to every row
        for (int j = 0; j < this->number_seats / this->rows; j++) {
            this->seatMap[i][j] = l.seatMap[i][j];
        }
    }
    for (int i = 0; i < this->rows; i++) { //adding the column array to every row
        for (int j = 0; j < this->number_seats / this->rows; j++) {
            this->zone_locations[i][j] = l.zone_locations[i][j];
        }
    }
}

bool Location::operator==(const Location l) {
    if ((this->number_seats == l.number_seats) && (this->date == l.date) && (this->time == l.time)) {
        return true;
    }
    return false;
}

void Location::operator++(int x) {
    number_seats++;
}

void Location::add_ticket(Ticket t) {
    t.check(tickets, amount_of_tickets);//This checks to see if the ticket t has the same ID as any other tickets

    amount_of_tickets++;
    Ticket* copy_of_tickets = new Ticket[amount_of_tickets];
    for (int i = 0; i < amount_of_tickets; i++) {
        copy_of_tickets[i] = tickets[i];
    }

    delete[] tickets;
    tickets = copy_of_tickets;
}

Ticket Location::create_ticket(string name, string zoneName) {
    int startingRowOfZone;
    int endingRowOfZone;
    int rowSeat;
    int columnSeat;

    for (int i = 0; i < size; i++) {
        if (zone[i].getName() == zoneName) {
            startingRowOfZone = zone[i].getStart();
            endingRowOfZone = zone[i].getEnd();
        }
    }

    for (int i = startingRowOfZone; i < endingRowOfZone; i++) {
        for (int j = 0; j <= rows / number_seats; j++) {
            if (seatMap[i][j] == 0) {
                columnSeat = j;   //finding the first available seat in the zone and assign it to a person
                seatMap[i][j] = 1;//the seat is assigned
                rowSeat = i;
                goto jump;        //getting out of the 2 for loops
            }
        }
    }
jump:

    Ticket t(name, rowSeat, columnSeat, zoneName);
    return t;
}

void Location::add_zone(int start_zone, int end_zone, string zone_name) {
    if (zone == nullptr) {
        zone = new ZoneInfo[size + 1];
    }
    ZoneInfo* copy_of_zone = new ZoneInfo[size + 1]; //we initialize copy_of_zone to the new amount of zones

    for (int i = 0; i < size; i++) {  //copies by value zone to copy_of_zone
        copy_of_zone[i] = zone[i];
    }
    copy_of_zone[size].setName(zone_name);
    copy_of_zone[size].setStart(start_zone);
    copy_of_zone[size].setEnd(end_zone);

    delete[]zone;                     //delete the current zone
    zone = copy_of_zone;             //reinitialize zone with a greater size

    size++;   //we increase the number of zones by 1
    update_zone();
}

int Location::find_zone(string zoneName) {
    for (int i = 0; i < size; i++) {
        if (zone[i].getName() == zoneName) {
            return zone[i].getStart();
        }
    }
    return -1;
}

void Location::update_zone() {  //add the current zones to the bidimensional array
    int row_lenght;
    char index = 'A';
    row_lenght = number_seats / rows; //the number of seats in a row
    for (int i = 0; i < size; i++) {  //loop through the zone array
        for (int j = zone[i].getStart(); j < zone[i].getEnd(); j++) { //loop through the rows
            for (int k = 0; k < row_lenght; k++) { //loop through the seats in each row
                zone_locations[j][k] = index;
            }
            index++;
        }
    }
}

int** Location::getseatMap() {
    int** newMap = new int* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        newMap[i] = new int[number_seats / rows];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->number_seats / this->rows; j++) {
            newMap[i][j] = seatMap[i][j];
        }
    }
    return newMap;
}

int Location::getNumber_seats() {
    if (this->number_seats != -1) {
        return this->number_seats;
    }
    else {
        return -1;
    }
}

int Location::getRows() {
    return this->rows;
}

int Location::getTime() {
    return this->time;
}

string Location::getDate() {
    return this->date;
}

ZoneInfo* Location::getZone() {
    return this->zone;
}

int Location::getSize() {
    return this->size;
}

void Location::setseatMap(int** seatMap) {
    this->seatMap = seatMap;
}

void Location::setNumber_seats(int number_seats) {
    this->number_seats = number_seats;

    //This if statement and for loop are to change the size of the seatMap and the Zone_locations
    //We do this because if we change the size of the rows then we need to make the seatMap
    //the same size
    if (rows != -1) {
        for (int i = 0; i < rows; i++) {
            delete[] seatMap[i];
        }
        delete[] seatMap;

        seatMap = new int* [rows]; //first pointer gets assigned an array of size rows
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            seatMap[i] = new int[rows / number_seats]; //each pointer in seatMap is pointing to a new array
        }

        for (int i = 0; i < rows; i++) {
            delete[] zone_locations[i];
        }
        delete[] zone_locations;

        zone_locations = new char* [rows]; //first pointer gets assigned an array of size rows
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            zone_locations[i] = new char[rows / number_seats]; //each pointer in zone_locations is pointing to a new array
        }
    }
}

void Location::setRows(int rows) {
    int old = this->rows;
    this->rows = rows;


    //This if statement and for loop are to change the size of the seatMap and the Zone_locations
    //We do this because if we change the size of the rows then we need to make the seatMap
    //the same size
    if (number_seats != -1) {
        for (int i = 0; i < old; i++) {
            delete[] seatMap[i];
        }
        delete[] seatMap;

        seatMap = new int* [rows]; //first pointer gets assigned an array of size rows
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            seatMap[i] = new int[rows / number_seats]; //each pointer in seatMap is pointing to a new array
        }

        for (int i = 0; i < old; i++) {
            delete[] zone_locations[i];
        }
        delete[] zone_locations;

        zone_locations = new char* [rows]; //first pointer gets assigned an array of size rows
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            zone_locations[i] = new char[rows / number_seats]; //each pointer in zone_locations is pointing to a new array
        }
    }
}

void Location::setTime(int time) {
    this->time = time;
}

void Location::setDate(string date) {
    this->date = date;
}

void Location::setZone(ZoneInfo* zone) {
    this->zone = zone;
}

void operator>>(istream& input, Location& l) {
    cout << endl << "Give new location info ";
    cout << "Number of seats: ";
    input >> l.number_seats;
    cout << "Number of rows: ";
    input >> l.rows;
    cout << "New Time";
    input >> l.time;
    cout << "New date: ";
    input >> l.date;
}

ostream& operator<<(ostream& os, const Location& l) {
    os << "The Number of Seats: " << l.number_seats << endl;
    os << "The number of rows: " << l.rows << endl;
    os << "The time of the event: " << l.time << endl;
    os << "The date of the event: " << l.date<<endl;
    return os;
}
