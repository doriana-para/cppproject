#include "ZoneInfo.h"

ZoneInfo::ZoneInfo() {
    this->name = "";
    this->start = -1;
    this->end = -1;
}

ZoneInfo::ZoneInfo(std::string name, int start, int end) {
    this->name = name;
    this->start = start;
    this->end = end;
}

std::string ZoneInfo::getName() {
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

std::ostream& operator<<(std::ostream& output, ZoneInfo z) {
    output << "The name of the zone:" << z.name << std::endl;
    output << "The beginning row: " << z.start << std::endl;
    output << "The ending row: " << z.end;
    return output;
}

void operator>>(std::istream& input, ZoneInfo& z) {
    std::cout << std::endl << "Give a new zone start and end ";
    input >> z.start;
    input >> z.end;
}
