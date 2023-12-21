#pragma once
#include <iostream>
#include <string>

class ZoneInfo {
private:
    std::string name;
    int start;
    int end;

public:
    ZoneInfo();
    ZoneInfo(std::string name, int start, int end);

    std::string getName();
    int getStart();
    int getEnd();

    void setName(std::string name);
    void setStart(int start);
    void setEnd(int end);

    void operator=(const ZoneInfo z);
    void operator+(int move_zone);
    void operator-(int move_zone);

    friend std::ostream& operator<<(std::ostream& output, ZoneInfo z);
    friend void operator>>(std::istream& input, ZoneInfo& z);
};
