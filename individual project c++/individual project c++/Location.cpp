#include<iostream>
#include"ZoneInfo.cpp"
using namespace std;

class Location {
private:
	int **seatMap; // it holds the postition of the seat 
	int number_seats;
	int rows;
	int time;
	string date;
	ZoneInfo *zone;
	int size;                //number of zones
	ZoneInfo* copy_of_zone; // used for holding a copy of the zone
	
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
		delete[]seatMap;
	}

//function that adds the zones 
	void add_zone(int start_zone, int end_zone, string zone_name){
	
		size++;                             //we increase the number of zones by 1
		copy_of_zone = new ZoneInfo[size]; //we initialize copy_of_zone to the new amount of zones
		for (int i = 0; i < size; i++) {   //copies by value zone to copy_of_zone
			copy_of_zone[i] = zone[i];
		}
		delete[]zone;                     //delete the current zone
		zone = copy_of_zone;              //reinitialize zone with a greater size
//WE NEED TO MAKE AN ASSIGN OPERATOR FOR ZONE INFO, HUSTON WE HAVE A PROBLEM!
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
	string date() {

		return this->date;
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
};