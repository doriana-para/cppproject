#include "ZoneInfo.h"
using namespace std;

ZoneInfo::ZoneInfo() {
    this->name = "";
    this->start = -1;
    this->end = -1;
}

ZoneInfo::ZoneInfo(string name, int start, int end) {
    this->name = name;
    this->start = start;
    this->end = end;
}

string ZoneInfo::getName() {
    return this->name;
}

int ZoneInfo::getStart() {
    return this->start;
}

int ZoneInfo::getEnd() {
    return this->end;
}

void ZoneInfo::setName(std::string name) {
    this->name = name;
}

void ZoneInfo::setStart(int start) {
    this->start = start;
}

void ZoneInfo::setEnd(int end) {
    this->end = end;
}

void ZoneInfo::operator=(const ZoneInfo z) {
    this->name = z.name;
    this->start = z.start;
    this->end = z.end;
}

void ZoneInfo::operator+(int move_zone) {
    this->start += move_zone;
    this->end += move_zone;
}

void ZoneInfo::operator-(int move_zone) {
    this->start -= move_zone;
    this->end -= move_zone;
}

ostream& operator<<(ostream& output, ZoneInfo z) {
    output << "The name of the zone:" << z.name << endl;
    output << "The beginning row: " << z.start << endl;
    output << "The ending row: " << z.end<<endl;
    return output;
}

void operator>>(istream& input, ZoneInfo& z) {
    cout << endl << "Give a new zone start and end ";
    input >> z.start;
    input >> z.end;
}
