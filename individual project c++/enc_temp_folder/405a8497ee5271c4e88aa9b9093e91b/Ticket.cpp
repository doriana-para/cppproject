#include<iostream>
#include"Location.cpp"
using namespace std;

//class ticket will hold all the details for the ticket
class Ticket {

private:
	int id;
	int seat_number;
	ZoneInfo *zone;

public:
	//default constructor
	Ticket() {
		this->id = -1;
		this->seat_number = -1;
		this->zone ;
	}

	//constructor with parameters
	Ticket(int seat_number, ZoneInfo *zone) {
		this->seat_number = seat_number;
		this->zone = zone;
		srand(time(NULL));
		this->id = rand()%100000 ;

	}




};