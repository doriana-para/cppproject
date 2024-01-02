#include <iostream>
#include <fstream>
#include "Location.h"

#include <iostream>
#include <string>
using namespace std;



int main() {
    //new loc with parameters
    //Location loc1(100, 8, 12, "23/01/2024");
    //cout << "Loc1 details" << endl << loc1 << endl;

    //assign = op to make a copy of location

    //Location loc2 = loc1;
    //cout << "Loc2 details" << endl << loc2 << endl;


    //print out bool if (loc1=loc2) return false, true
    //bool isEqual = (loc1 == loc2);
    //cout << "Check if loc1 and loc2 are equal" << endl << isEqual;

    //new ticket with param
    //Ticket newTicket("John", 20, 30, "vip");
    //cout << "Ticket details" << endl << newTicket << endl;

    //change no of seats inside the ticket


    //add this ticket to location
    //add_ticket(Ticket newTicket);


    //make a zone without param
   /* ZoneInfo newZone();
    ZoneInfo::ZoneInfo() {
        this->name = "zone A";
        this->start = 1;
        this->end = 30;
    }*/
    //set the name, the starting row, ending row to whatever

    //cout on zone

    //add zone to location

    //find the zone you just made function

    //update zone

    //cout location

    //reading from file

    
    cout << "Welcome! Would you like to use a text file (type 'f') or user input (type 'i')" << endl;
    string userI;
    cin >> userI;

    Location l1(10, 5, 1, "04/23/2023");
    ZoneInfo* zone_array = l1.getZone();
    ofstream outputBinaryFile("Ticket_data.bin", ios::out | ios::binary);



    if (userI == "f") {
        string event_info;
        //read from text file
        ifstream inputFile("readMe.txt", ifstream::in);
      //write in binary file
       

        if (!inputFile.is_open()) {
            cout << endl << "The readMe.txt is missing";
        }
        
        else {

            cout << endl << "The readMe.txt is available" << endl;
        }
        //In order to run all the code, we need to make location first
        inputFile >> event_info;
        if (event_info == "LOCATION") {
            inputFile >> event_info;
            int size = stoi(event_info);
            inputFile >> event_info;
            int rows = stoi(event_info);
            inputFile >> event_info;
            int time = stoi(event_info);

            inputFile >> event_info;
            l1.setNumber_seats(size);
            l1.setRows(rows);
            l1.setTime(time);
            l1.setDate(event_info);
            cout << l1;
        }
        else {
            cout << "Sorry, we can not continue until you have LOCATION as the first command" << endl;

        }
        

        while (!inputFile.eof()) {
            string event_info = " ";
            inputFile >> event_info;
            

            if (event_info == "ZONE") {
                //This helps to make a new zone
                inputFile >> event_info;
                string name = event_info;
                inputFile >> event_info;
                int start_row = stoi(event_info);
                inputFile >> event_info;
                int end_row = stoi(event_info);

                l1.add_zone(start_row, end_row, name);
                cout << l1.getZone()[0];
            }
        }
    }
    else if (userI == "i") {
        cout << "The first step is to make a location, so please input the number of seats for this location: " << endl;


        cin >> userI;
        l1.setNumber_seats(stoi(userI));
        cout << "Please enter the number of rows in the location: " << endl;
        cin >> userI;
        l1.setRows(stoi(userI));
        cout << "Please enter the time of the event: " << endl;
        cin >> userI;
        l1.setTime(stoi(userI));
        cout << "Please enter the date (day/month/year): " << endl;
        cin >> userI;
        l1.setDate(userI);

        cout << l1;

        while (userI != "q") { //q if for quit

            cout << "What would you like to do? (new zone('z'), new ticket ('t') or quit ('q'))" << endl;
            //
            cin >> userI;
            if (userI == "q") {
                //Save the ticket info here

                break;
            }

            int start_zone;
            int end_zone;
            string zone_name;

            //This if statement makes a new zone
            if (userI == "z") {
                //delete[] zone_array;
                //zone_array = l1.getZone();
                //the zone start and end doesnt intersect with any other current zones





                for (int i = 0; i <= l1.getSize(); i++) {

                    //first do while
                    do {
                        cout << "Please enter a valid starting row: " << endl;
                        cin >> start_zone;
                    } while (start_zone > l1.getRows() && (start_zone >= zone_array[i].getStart() && start_zone <= zone_array[i].getEnd()));


                    //second do while
                    do {
                        cout << "Please enter a valid ending row: " << endl;
                        cin >> end_zone;

                    } while (end_zone > l1.getRows() && (end_zone >= zone_array[i].getStart() && end_zone <= zone_array[i].getEnd()));
                    //NEED TO FIX THIS _____________________________________________________
                    cout << "Please enter the zone name: " << endl;
                    cin >> zone_name;
                    //____________________________________________

                }
                l1.add_zone(start_zone, end_zone, zone_name);
            }
            if (userI == "t") {
                //delete[] zone_array;
                //zone_array = l1.getZone();

                cout << "Please enter the name for the ticket: " << endl;
                string ticket_name;
                cin >> ticket_name;
                cout << "Please enter a valid zone the ticket will be in." << endl;
                cout << "These are the current zones: ";
                for (int i = 0; i < l1.getSize(); i++) {
                    //cout << zone_array[i].getName() << ", ";
                } cout << endl;

                string ticket_zone;
                cin >> ticket_zone;

                Ticket t = l1.create_ticket(ticket_name, ticket_zone);

                if (outputBinaryFile.is_open()) {
                    cout << "test";
                    string nm = t.getName();
                    const int length = nm.length(); 
                    char* char_array = new char[length + 1]; 
                    strcpy(char_array, nm.c_str()); 
                    //string nm = t.getName();

                    outputBinaryFile.write((char*)&(char_array), sizeof(char));
                }
                cout << "test1";
            }
        }
    }
    

    return 0;
}

