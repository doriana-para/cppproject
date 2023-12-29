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

    


    cout << "Welcome! Would you like to use a text file (type 'f') or user input (type 'i')" << endl;
    string input;
    cin >> input;

    Location l1;
    ZoneInfo * zone_array = l1.getZone();

    if(input == "f"){
        string event_info;

        ifstream inputFile("readMe.txt", ifstream::in);
        if (!inputFile.is_open()) {
            cout << endl << "The readMe.txt is missing";
        }
        else {
            cout << endl << "The readMe.txt is available" << endl;
        }
        //In order to run all the code, we need to make location first
        inputFile >> event_info;
        if(event_info=="LOCATION"){  
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
        }else{
            cout << "Sorry, we can not continue until you have LOCATION as the first command" << endl;
            
        }

        while (!inputFile.eof()) {
            string event_info = " ";
            inputFile >> event_info;
            cout << event_info << endl;
            
            if (event_info=="ZONE") { 
                //This helps to make a new zone
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
        cout << "The first step is to make a location, so please input the number of seats for this location: " << endl;
        
         
        cin >> input;
        l1.setNumber_seats(stoi(input));
        cout << "Please enter the number of rows in the location: " << endl;
        cin >> input;
        l1.setRows(stoi(input));
        cout << "Please enter the time of the event: " << endl;
        cin >> input;
        l1.setTime(stoi(input));
        cout << "Please enter the date (day/month/year): " << endl;
        cin >> input;
        l1.setDate(input);
        
        cout << l1;
        
        while (input != "q") { //q if for quit

            cout << "What would you like to do?" << endl;
            //new zone("z"), new ticket ('t') or quit ('q')
            cin >> input;
            if(input == "q"){
                //Save the ticket info here

                break;
            }
            //THis if statemnet makes a new zone
            if (input == "z") {
                delete[] zone_array;
                zone_array = l1.getZone();
                //the zone start and end doesnt intersect with any other current zones 
                
                int start_zone;                    
                int end_zone;
                string zone_name;

                
                
                for(int i = 0; i < l1.getSize(); i++){
                    
                    //first do while
                    do {
                        cout << "Please enter a valid start zone: " << endl;
                        cin >> start_zone; 
                    } while (start_zone > l1.getRows() && (start_zone >= zone_array[i].getStart() && start_zone <= zone_array[i].getEnd()) );
                    
                    
                    //second do while
                    do {
                        cout << "Please enter a valid end zone: " << endl;
                        cin >> end_zone;
                        
                    } while (end_zone > l1.getRows() && (end_zone >= zone_array[i].getStart() && end_zone <= zone_array[i].getEnd()) );
                    do{
                        cout << "Please enter the zone name: " << endl;
                        cin >> zone_name;
                    }while(zone_name == zone_array[i].getName());
                }
                l1.add_zone(start_zone, end_zone, zone_name);
            }
            if(input == "t"){
                delete[] zone_array;
                zone_array = l1.getZone();
                
                cout << "Please enter the name for the ticket: " << endl;
                string ticket_name;
                cin >> ticket_name;
                cout << "Please enter a valid zone the ticket will be in." << endl;
                cout << "These are the current zones: ";
                for(int i = 0; i < l1.getSize(); i++){
                    cout << zone_array[i].getName() << ", ";
                } cout << endl;

                string ticket_zone;
                cin >> ticket_zone;
            }
        }
    }



    
    
        //Ticket
    return 0;

}
