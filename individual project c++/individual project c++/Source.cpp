#include <iostream>
#include <fstream>
#include "Location.h"

#include <iostream>
#include <string>
using namespace std;


int main() {
    //new loc with parameters
    Location loc1(100, 8, 12, "23/01/2024");
    cout << "Loc1 details" << endl << loc1 << endl;

    //assign = op to make a copy of location

    Location loc2 = loc1;
    cout << "Loc2 details" << endl << loc2 << endl;


    //print out bool if (loc1=loc2) return false, true
    //bool isEqual = (loc1 == loc2);
    //cout << "Check if loc1 and loc2 are equal" << endl << isEqual;

    //new ticket with param
    Ticket newTicket("John", 20, 30, "vip");
    cout <<"Ticket details"<<endl<< newTicket<<endl;

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

    


    cout << "Welcome, would you like to use a text file (type 'f') or user input (type 'i')" << endl;
    string input;
    cin >> input;

    if(input == "f"){
        string event_info;

        ifstream inputFile("readMe.txt", ifstream::in);
        if (!inputFile.is_open()) {
            cout << endl << "The readMe.txt is missing";
        }
        else {
            cout << endl << "The readMe.txt is available" << endl;
        }
        //In order to run all the code we MUST make location first
        inputFile >> event_info;
        if(event_info=="LOCATION"){  
            inputFile >> event_info;
            int size = stoi(event_info);
            inputFile >> event_info;
            int rows = stoi(event_info);
            inputFile >> event_info;
            int time = stoi(event_info);

            inputFile >> event_info;
            Location l1(size, rows, time, event_info);
            cout << l1;
        }else{
            Location l1;
            cout << "Sorry, we can not continue until you have LOCATION as the first command" << endl;
            
        }

        while (!inputFile.eof()) {
            string event_info = " ";
            inputFile >> event_info;
            cout << event_info << endl;
            
            if (event_info=="ZONE") { 

                //We have a function inside of loction to make zones
                //USE void Location::add_zone(int start_zone, int end_zone, string zone_name)

                
                inputFile >> event_info;
                string name =event_info;
                inputFile >> event_info;
                int start_row = stoi(event_info);
                inputFile >> event_info;
                int end_row = stoi(event_info);
            
                l1.add_zone(start_row, end_row, name);
                cout << l1.getZone()[0];
            }
        }
    }else if(input == "i"){
        while (input != "q") { //q if for quit

            string event_info = " ";
            cin >> input;
            cout << input << endl;
            
            if (input == "LOCATION"){
                cin >> input;
                int size = stoi(input);
                cin >> input;
                int rows = stoi(input);
                cin >> input;
                int time = stoi(input);
                cin >> input;

                Location l1(size, rows, time, input);
                cout << l1;
            }
            
            else if (input=="ZONE") {
                cin >> input;
                string name = input;
                cin >> input;
                int start_row = stoi( input);
                cin >> input;
                int end_row =stoi( input);
            
                ZoneInfo z1(name, start_row, end_row);
                cout << z1;
            }
        }
    }

    
        //Ticket
    return 0;

}
