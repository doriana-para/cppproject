#include<iostream>
#include"Location.cpp"

using namespace std;

int main() {
	int number_seats, rows, time;
	string date;
	cout << "Enter the number of seats: " << endl;
	cin >> number_seats;
	cout << "Enter the number of rows: " << endl;
	cin >> rows;
	cout << "Enter the time of the event:" << endl;
	cin >> time;
	cout << "Enter the date of the event: " << endl;
	cin >> date;
	int start_zone, end_zone;
	string name_zone;
	Location Taylor(number_seats, rows, time, date);
	cout << "Please enter the start of the zone: ";
	cin >> start_zone;
	cout << "Please enter the end of the zone: ";
	cin >> end_zone;
	cout << "Please enter the name of the zone: ";
	cin >> name_zone;
	Taylor.add_zone(start_zone, end_zone, name_zone);
	//cout << Taylor.getZone()[0].getName();

		
	
}