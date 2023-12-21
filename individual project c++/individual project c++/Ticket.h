#pragma once
#include <iostream>
#include <string>

class Ticket {
private:
    int id;
    int seat_number;
    std::string zoneName;
    const std::string name;

public:
    Ticket();
    Ticket(std::string name, int seat_number, std::string zoneName);
    Ticket(const Ticket& t);
    ~Ticket();

    void operator=(const Ticket t);
    bool operator!();
    bool operator<(Ticket t);

    void check(Ticket* ticket_array, int size_of_ticket_array);
    void newId();

    int getId();
    int getSeatNumber();
    std::string getZoneName();
    std::string getName();

    void setId(int id);
    void setSeatNumber(int seat_Number);
    void setZoneName(std::string zoneName);

    friend std::ostream& operator<<(std::ostream& output, Ticket t);
    friend void operator>>(std::istream& input, Ticket& t);
};