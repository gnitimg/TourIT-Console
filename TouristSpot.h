#ifndef TOURISTSPOT_H
#define TOURISTSPOT_H

#include <string>
using namespace std;

class TouristSpot {
private:
    string name;
    string location;
    string type;
    int visitTime;  // 分钟
    float rating;

public:
    TouristSpot(string n = "", string loc = "",
        string t = "", int time = 0, float r = 0.0);

    // 基本操作
    void display() const;
    string getName() const { return name; }
    int getVisitTime() const { return visitTime; }
    float getRating() const { return rating; }
};

#endif