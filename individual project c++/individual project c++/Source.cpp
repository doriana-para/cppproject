#include <iostream>
#include <fstream>
#include "Location.h"

#include <iostream>
#include <string>
using namespace std;



int main() {

    //Adding an interface

    cout << "Welcome! Would you like to use a text file (type 'f') or user input (type 'i')" << endl;
    string userI;
    cin >> userI;

    Location l1(10, 5, 1, "04/23/2023");
    ZoneInfo* zone_array = NULL;
    ofstream outputBinaryFile("Ticket_data.bin", ios::out | ios::binary);

    //Read from text file

    if (userI == "f") {
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

                //Create a new zone

                inputFile >> event_info;
                string name = event_info;
                inputFile >> event_info;
                int start_row = stoi(event_info);
                inputFile >> event_info;
                int end_row = stoi(event_info);

                l1.add_zone(start_row, end_row, name);
                
            }

            if(event_info == "TICKET"){
                //Make a ticket from file info
                //Then add the ticket name to the binary file
                inputFile >> event_info;
                string name=event_info;
                inputFile >> event_info;
                string zoneName = event_info;
                
                Ticket t1 = l1.create_ticket(name, zoneName);


                if (outputBinaryFile.is_open()) {
                    outputBinaryFile.write((char*)&(t1), sizeof(Ticket));

                    
                }
            }
        }
        for (int i = 0; i < l1.getSize(); i++) {
            cout << l1.getZone()[i];
        }
        for (int i = 0; i < l1.getAmount_of_Tickets(); i++) {
            cout << l1.getTickets()[i];
        }
        outputBinaryFile.close();

    }else if (userI == "i") {
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
                bool alreadyAssigned=false;
                int i = 0;
                if(zone_array != NULL){
                    delete[] zone_array;
                }
                zone_array = l1.getZone();
                //the zone start and end doesnt intersect with any other current zones

                //first do while
                do{
                     alreadyAssigned = false;
                    cout << "Please enter a valid starting row: " << endl;
                    cin >> start_zone;
                    for(int j = 0; j < l1.getSize(); j++){
                        if(start_zone == zone_array[j].getStart() || start_zone == zone_array[j].getEnd()){
                            alreadyAssigned = true;
                            cout << "The zone row number you entered is already occupied by an existing zone" << endl;
                        }
                    }
                }while(start_zone > l1.getRows() || alreadyAssigned);
                

                    //second do while
                do{
                     alreadyAssigned = false;
                    cout << "Please enter a valid ending row: " << endl;
                    cin >> end_zone;
                    for(int j = 0; j < l1.getSize(); j++){
                        if(end_zone == zone_array[j].getStart() || start_zone == zone_array[j].getEnd()){
                            alreadyAssigned = true;
                            cout << "The zone row number you entered is already occupied by an existing zone" << endl;
                        }
                    }
                }while(end_zone > l1.getRows() || alreadyAssigned);
                
                do{
                    alreadyAssigned = false;
                    cout << "Please enter a valid name to your zone: " << endl;
                    cin >> zone_name;
                    for(int j = 0; j < l1.getSize(); j++){
                        if(zone_name == zone_array[j].getName()){
                            alreadyAssigned = true;
                            cout << "The zone name you entered is taken" << endl;
                        }
                    }
                }while(alreadyAssigned);

                l1.add_zone(start_zone, end_zone, zone_name);
            }
            if (userI == "t") {
                if(zone_array != NULL){
                    delete[] zone_array;
                }
                zone_array = l1.getZone();

                cout << "Please enter the name for the ticket: " << endl;
                string ticket_name;
                cin >> ticket_name;
                cout << "Please enter a valid zone the ticket will be in." << endl;
                cout << "These are the current zones: ";
                for (int i = 0; i < l1.getSize(); i++) {
                    cout << zone_array[i].getName() << ", ";
                } cout << endl;

                string ticket_zone;
                cin >> ticket_zone;

                Ticket t = l1.create_ticket(ticket_name, ticket_zone);

                if (outputBinaryFile.is_open()) {
                    outputBinaryFile.write((char*)&(t), sizeof(Ticket));
                }
            }
        }
        outputBinaryFile.close();          
    }
    

    return 0;
}

