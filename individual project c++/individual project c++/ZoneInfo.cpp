#include<iostream>

using namespace std;


//it holds the name and location of each of the zones   

class ZoneInfo {

private:

    string name;

    int start;// it stores the beginning seat number for the zone by rows

    int end;// it stores the final seat number for the zone by rows

public:

    //default constructor

    ZoneInfo() {
        this->name = "";
        this->start = -1;
        this->end = -1;

    }



    //constructor with parameters

    ZoneInfo(string name, int start, int end) {
        this->name = name;
        this->start = start;
        this->end = end;

    }

    //getter

    string getName() {

        return this->name;

    }

    int  getStart() {

        return this->start;

    }



    int getEnd()

    {

        return this->end;

    }

    //setter
    void setName(string name) {
        this->name = name;
    }

    void setStart(int start) {

        this->start = start;

    }

    void setEnd(int end) {

        this->end = end;

    }



    //equal operator

    void operator= (const ZoneInfo z) {

        //this->name = z.name;

        this->start = z.start;

        this->end = z.end;



    }

    //+ operator

    void operator+(int move_zone) {

        this->start += move_zone;

        this->end += move_zone;

    }

    //- operator

    void operator-(int move_zone) {

        this->start -= move_zone;

        this->end -= move_zone;

    }

    // <<operator
    // >>operator

    friend ostream& operator<<(ostream& output, ZoneInfo z) {
        output << "The name of the zone:" << z.name << endl;

    output << "The beginning row: " << z.start << endl;

    output << "The ending row: " << z.end;

    return output;

    }

    friend void operator>>(istream& input, ZoneInfo& z){
        cout << endl << "Give a new zone start and end ";
        input >> z.start;
        input >> z.end;
    }

   
    
};




