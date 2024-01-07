
#include<iostream>
#include"Ticket.cpp"

class Ticket_VIP:public Ticket{

public:
    Ticket_VIP() {
        this->name = "";
        this->id = -1;
        this->row_num = -1;
        this->col_num = -1;
        this->zoneName = "";
    }

    Ticket_VIP(string name, int row_num, int col_num, string zoneName) {
        this->name = name;
        this->row_num = row_num;
        this->col_num = col_num;
        this->zoneName = zoneName;
        srand(time(NULL));
        this->id = rand();
    }

    void printID() {
        cout << this->id;
    }

};