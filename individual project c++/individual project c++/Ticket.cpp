#include<iostream>



using namespace std;



//class ticket will hold all the details for the ticket

class Ticket {

private:
    int id; // the unique ticket id
    int seat_number; // this seat number for the ticket
    string zoneName; // the name of the zone the ticket location is in
    const string name; // the name of the ticket holder


public:

    //default constructor

    Ticket() : name("") {
        this->id = -1;
        this->seat_number = -1;
        this->zoneName = "";
    }
    //constructor with parameters
    Ticket(string name, int seat_number, string zoneName) : name(name) {
        this->seat_number = seat_number;
        this->zoneName = zoneName;
        this->id = rand();
    }

    Ticket(const Ticket& t) {
        this->seat_number = t.seat_number;
        this->zoneName = t.zoneName;
        this->id = t.id;
    }

    ~Ticket() {
    //there is no pointer
    }

    //equals operator
    void operator=(const Ticket t) {
        this->id = t.id;
        this->seat_number = t.seat_number;
        this->zoneName = t.zoneName;
    }

    //This checks to see if the seat_number has been set
    bool operator!() {
        if (seat_number == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator<(Ticket t) {
        if (this->id < t.id) {
            return true;
        }
        else {
            return false;
        }
    }


    void check(Ticket* ticket_array, int size_of_ticket_array) {

        for (int i = 0; i < size_of_ticket_array; i++) {
            if (this->id == ticket_array[i].id) {
                newId(); // this sets the current ticket id to a new id
                i = 0; // This resets the for loop if the same ID is found
                //This is done to make sure another copy isnt made
            }
        }

    }

    void newId() {
        this->id = rand();// this gives us a random number between 0 and the max_int value
    }


    //THese are our getters
    int getId() {
        return this->id;
    }
    int getSeatNumber() {
        return this->seat_number;
    }

    string getZoneName() {
        return this->zoneName;
    }
    string getName() {
        return this->name;
    }

    //These are our setters
    void setId(int id) {
        this->id = id;
    }

    void setSeatNumber(int seat_Number) {
        this->seat_number = seat_number;
    }

    void setZoneName(string zoneName) {
        this->zoneName = zoneName;
    }


    friend ostream& operator<<(ostream& output, Ticket t) {

        output << "Your unique ID Number: " << t.getId() << endl;
        return output;
    }

    friend void operator>>(istream& input, Ticket& t) {
        cout << endl << "Create a new Ticket ";
        cout << endl << "Enter Zone Name: ";
        input >> t.zoneName;
    }
  

};




