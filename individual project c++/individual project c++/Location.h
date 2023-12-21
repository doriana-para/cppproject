#pragma once
#include <iostream>
#include "ZoneInfo.h"
#include "Ticket.h"
using namespace std;

class Location {
private:
    int** seatMap;
    int number_seats;
    int rows;
    int time;
    string date;
    ZoneInfo* zone;
    int size;
    char** zone_locations;
    Ticket* tickets;
    int amount_of_tickets;

public:
    Location();
    Location(int number_seats, int rows, int time, string date);
    Location(const Location& loc);
    ~Location();

    void operator=(const Location& l);
    bool operator==(const Location l);
    void operator++(int x);

    void add_ticket(Ticket t);
    void add_zone(int start_zone, int end_zone, string zone_name);
    int find_zone(string zoneName);
    void update_zone();

    int** getseatMap();
    int getNumber_seats();
    int getRows();
    int getTime();
    string getDate();
    ZoneInfo* getZone();

    void setseatMap(int** seatMap);
    void setNumber_seats(int number_seats);
    void setRows(int rows);
    void setTime(int time);
    void setDate(string date);
    void setZone(ZoneInfo* zone);

    friend void operator>>(istream& input, Location& l);
    friend ostream& operator<<(ostream& os, const Location& l);
};