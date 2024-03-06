/*!
    \file
    \brief Файл реализации класса flatsData
*/

#include "flatsData.h"

flatsData::flatsData(){
        this->houseNum = 0;
        this->flatNum = 0;
        this->roomCount = 0;
        this->flatSquare = 0;
        this->ownerName = "";
        this->countResidents = 0;
}

flatsData::flatsData(int houseNum, int flatNum, int roomCount, int flatSquare, string ownerName, int countResidents){
        this->houseNum = houseNum;
        this->flatNum = flatNum;
        this->roomCount = roomCount;
        this->flatSquare = flatSquare;
        this->ownerName = ownerName;
        this->countResidents = countResidents;
}

flatsData::flatsData(const flatsData &other){
        this->houseNum = other.houseNum;
        this->flatNum = other.flatNum;
        this->roomCount = other.roomCount;
        this->flatSquare = other.flatSquare;
        this->ownerName = other.ownerName;
        this->countResidents = other.countResidents;
}

string flatsData::getName(){
    return ownerName;
}

string flatsData::getData(){
    return ownerName+";"+std::to_string(houseNum)+";"+std::to_string(flatNum)+";"+std::to_string(roomCount)+";"+std::to_string(flatSquare)+";"+std::to_string(countResidents);
}

bool operator==(const flatsData & a, const flatsData & b){
    return a.flatSquare == b.flatSquare && a.houseNum == b.houseNum && a.flatNum == b.flatNum && a.ownerName == b.ownerName;
}

bool operator<(const flatsData & a, const flatsData & b){
    return ((a.flatSquare > b.flatSquare) || (a.flatSquare == b.flatSquare && a.houseNum < b.houseNum) || (a.flatSquare == b.flatSquare && a.houseNum == b.houseNum && a.flatNum < b.flatNum) || (a.flatSquare == b.flatSquare && a.houseNum == b.houseNum && a.flatNum == b.flatNum && a.ownerName < b.ownerName));
}

bool operator<=(const flatsData & a, const flatsData & b){
    return a < b || a == b;
}

bool operator>(const flatsData & a, const flatsData & b){
    return !(a <= b);
}

bool operator>=(const flatsData & a, const flatsData & b){
    return !(a < b);

}

