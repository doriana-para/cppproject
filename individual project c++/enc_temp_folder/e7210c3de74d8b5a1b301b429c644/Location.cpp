#include<iostream>
#include"ZoneInfo.cpp"
//#include"Ticket.cpp"
using namespace std;

class Location {
private:
	int **seatMap; // it holds the postition of the seat 
	int number_seats;
	int rows;
	int time;
	string date;
	ZoneInfo *zone;
	int size=0;                //number of zones
	char** zone_locations;  //stores the location of the zones
	
	
public:
 //default constructor
	Location() {
		this->number_seats = -1;
		this->rows = -1;
		this->time = -1;
		this->date = "";
		this->zone = new ZoneInfo[number_seats];
	}

//constructor with parameters
	Location(int number_seats, int rows, int time, string date) {
		
		this->number_seats = number_seats; 
		this->rows = rows;
		this->time = time;
		this->date = date;
		this->zone = new ZoneInfo[0];
		seatMap = new int* [rows]; //first pointer gets assigned an array of size rows
		for (int i = 0; i < rows; i++) { //adding the column array to every row
			seatMap[i] = new int[rows / number_seats]; //each pointer in seatMap is pointing to a new array
		}
		zone_locations = new char* [rows]; //first pointer gets assigned an array of size rows
		for (int i = 0; i < rows; i++) { //adding the column array to every row
			zone_locations[i] = new char[rows / number_seats]; //each pointer in zone_locations is pointing to a new array
		}
	}

//copy constructor
	Location(const Location& loc)
	{   
		this->number_seats = loc.number_seats;
		this->rows = loc.rows;
		this->time = loc.time;
		this->date = loc.date;

		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < number_seats / rows; j++)
			{
				this->seatMap[i][j] = loc.seatMap[i][j]; //copying the value inside loc.seatMap to this->seatMap because this points by value, not reference

			}
		}
	}

//destructor
	~Location(){
		
		for (int i = 0; i < rows; i++) {
			delete[] seatMap[i];
		}
		delete[] seatMap;
		delete[] zone;

		for (int i = 0; i < rows; i++) {
			delete[] zone_locations[i];
		}
		delete[] zone_locations;

	}

//function that adds the zones 
	void add_zone(int start_zone, int end_zone, string zone_name){
		
		size++;   //we increase the number of zones by 1
		
		
		ZoneInfo* copy_of_zone = new ZoneInfo[size+1]; //we initialize copy_of_zone to the new amount of zones
		for (int i = 0; i < size; i++) {  //copies by value zone to copy_of_zone
			copy_of_zone[i] = zone[i];
		}
		
		delete[]zone;                     //delete the current zone
		
		zone = copy_of_zone;             //reinitialize zone with a greater size
		zone[size - 1].setName(zone_name);
		zone[size - 1].setStart(start_zone);
		zone[size - 1].setEnd(end_zone);
		cout << "h";
		update_zone();
		
	}

	 //dynamically allocated vector of characters

	void update_zone() {                   //add the current zones to the bidimensional array
		int row_lenght;
		char index = 'A';
		row_lenght = number_seats / rows; //the number of seats in a row
		for (int i = 0; i < size; i++) {  //loop through the zone array
			for (int j = zone[i].getStart(); j < zone[i].getEnd(); j++) { //loop through the rows

				for (int k = 0; k < row_lenght; k++) //loop through the seats in each row
				{
					zone_locations[j][k] = index;
				}
				index++;
			}
		}
	}

	//getter
	int **getseatMap() {
		return this->seatMap;
	}

	int getNumber_seats() {
		return this->number_seats;
	}

	int getRows() {
		return this->rows;
	}

	int getTime() {
		return this->time;
	}
	string getDate() {

		return this->date;
	}

	ZoneInfo* getZone() {
		return this->zone;
	}
//setter
void setseatMap(int ** seatMap) {
	this->seatMap = seatMap;
}

void setNumber_seats(int number_seats){
	this->number_seats = number_seats;
}


void setRows(int rows) {
	this->rows = rows;
}

void setTime(int time)
{
	this->time = time;

}

void setDate(string date) {
	this->date = date;
}

void setZone(ZoneInfo * zone) {
	this->zone = zone;
}
};