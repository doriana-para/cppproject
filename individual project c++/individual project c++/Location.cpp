#include<iostream>
#include"ZoneInfo.cpp"
#include"Ticket.cpp"

using namespace std;


class Location {

private:
    int** seatMap; // it holds the postition of the seat
    int number_seats;
    int rows;
    int time;
    string date;
    ZoneInfo* zone;
    int size;               //number of zones
    char** zone_locations;      //stores the location of the zones
    Ticket* tickets;           //make an array that stores ticket id numbers, create a f inside of location.cpp
    int amount_of_tickets;

    //this checks if any of the tickets id match, if they match, set the newest ticket id to a new id

    //setters ad getters for id inside ticket.cpp

    //variab that stores size of ticket array



public:

    //default constructor

    Location() {
        size = 0;
        this->number_seats = 0;

        this->rows = -1;

        this->time = -1;

        this->date = "";

        this->zone = new ZoneInfo[number_seats];
    }



    //constructor with parameters

    Location(int number_seats, int rows, int time, string date) {
        size = 0;
        this->number_seats = number_seats;

        this->rows = rows;

        this->time = time;

        this->date = date;

        this->zone = nullptr;

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

    ~Location() {



       /* for (int i = 0; i < rows; i++) {

            delete[] seatMap[i];

        }

        delete[] seatMap;*/

        delete[] zone;



        /*for (int i = 0; i < rows; i++) {

            delete[] zone_locations[i];

        }

        delete[] zone_locations;*/

    }

    void operator=(const Location& l) {
        this->number_seats = l.number_seats;
        this->rows = l.rows;
        this->time = l.time;
        this->date = l.date;
        this->zone = l.zone;
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            for (int j = 0; j < number_seats / rows; j++) {
                seatMap[i][j] = l.seatMap[i][j];
            }
        }
        for (int i = 0; i < rows; i++) { //adding the column array to every row
            for (int j = 0; j < number_seats / rows; j++) {
                zone_locations[i][j] = l.zone_locations[i][j];
            }
        }
    }

    bool operator==(const Location l) {
        if ((this->number_seats == l.number_seats) && (this->date == l.date) && (this->time == l.time)) {
            return true;
        }
        return false;
    }

    void operator++(int x) {
        number_seats++;
    }

    void add_ticket(Ticket t) {
        t.check(tickets, amount_of_tickets);//This checks to see if the ticket t has the same ID as any other tickets

        amount_of_tickets++;
        Ticket* copy_of_tickets = new Ticket[amount_of_tickets];
        for (int i = 0; i < amount_of_tickets; i++) {
            copy_of_tickets[i] = tickets[i];
        }
        delete[] tickets;
        tickets = copy_of_tickets;
    }



    //function that adds the zones

    void add_zone(int start_zone, int end_zone, string zone_name) {
       
        if (zone == nullptr) {
            zone = new ZoneInfo[size + 1];
        }
        ZoneInfo* copy_of_zone = new ZoneInfo[size+1]; //we initialize copy_of_zone to the new amount of zones

        for (int i = 0; i < size; i++) {  //copies by value zone to copy_of_zone

            copy_of_zone[i] = zone[i];

        }

        copy_of_zone[size - 1].setName(zone_name);

        copy_of_zone[size - 1].setStart(start_zone);

        copy_of_zone[size - 1].setEnd(end_zone);
        

        delete[]zone;                     //delete the current zone
        zone = copy_of_zone;             //reinitialize zone with a greater size

        size++;   //we increase the number of zones by 1
        update_zone();


    }

    int find_zone(string zoneName) {
        for (int i = 0; i < size; i++) {
            if (zone[i].getName() == zoneName) {
                return zone[i].getStart();
            }
        }
        return -1;
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

    int** getseatMap() {

        return this->seatMap;

    }



    int getNumber_seats() {
        if (this->number_seats != -1) {
            return this->number_seats;
        }
        else {
            return -1;
        }


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

    void setseatMap(int** seatMap) {

        this->seatMap = seatMap;

    }



    void setNumber_seats(int number_seats) {
        this->number_seats = number_seats;
    }

    void setRows(int rows) {
        this->rows = rows;
    }



    void setTime(int time) {
        this->time = time;
    }



    void setDate(string date) {
        this->date = date;
    }



    void setZone(ZoneInfo* zone) {
        this->zone = zone;
    }

    friend ostream& operator<<(ostream& output, Location l) {

        output << "The Number of Seats:" << l.number_seats << endl;
        output << "The time of the event: " << l.time << endl;
        output << "The date of the event: " << l.date;
        return output;

    }
    friend void operator>>(istream& input, Location& l) {

        cout << endl << "Give new location info ";
        cout << "Number of seats: ";
        input >> l.number_seats;
        cout << "New date: ";
        input >> l.date;
        cout << "New Time";
        input >> l.time;
    }

    

};



