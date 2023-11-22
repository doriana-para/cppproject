#include<iostream>
using namespace std;

//it holds the name and location of each of the zones    
class ZoneInfo {
private:
	string name;
	int start;// it stores the beginning seat number for the zone
	int end;// it stores the final seat number for the zone

public:
	//default constructor
	ZoneInfo() {
		this->name = "";
		this->start = -1;
		this->end   = -1; 
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



};