
#include "Ticket.h"
#include <cstdlib>

Ticket::Ticket() : name("") {
    this->id = -1;
    this->seat_number = -1;
    this->zoneName = "";
}

Ticket::Ticket(std::string name, int seat_number, std::string zoneName) : name(name) {
    this->seat_number = seat_number;
    this->zoneName = zoneName;
    this->id = rand();
}

Ticket::Ticket(const Ticket& t) {
    this->seat_number = t.seat_number;
    this->zoneName = t.zoneName;
    this->id = t.id;
}

Ticket::~Ticket() {
    // No dynamic memory to free
}

void Ticket::operator=(const Ticket t) {
    this->id = t.id;
    this->seat_number = t.seat_number;
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

void Ticket::newId() {
    this->id = rand();
}

int Ticket::getId() {
    return this->id;
}

int Ticket::getSeatNumber() {
    return this->seat_number;
}

std::string Ticket::getZoneName() {
    return this->zoneName;
}

std::string Ticket::getName() {
    return this->name;
}

void Ticket::setId(int id) {
    this->id = id;
}

void Ticket::setSeatNumber(int seat_Number) {
    this->seat_number = seat_Number;
}

void Ticket::setZoneName(std::string zoneName) {
    this->zoneName = zoneName;
}

std::ostream& operator<<(std::ostream& output, Ticket t) {
    output << "Your unique ID Number: " << t.getId() << std::endl;
    return output;
}

void operator>>(std::istream& input, Ticket& t) {
    std::cout << std::endl << "Create a new Ticket ";
    std::cout << std::endl << "Enter Zone Name: ";
    input >> t.zoneName;
}





