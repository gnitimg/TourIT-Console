#ifndef TOURPLAN_H
#define TOURPLAN_H

#include "TouristSpot.h"
#include <vector>
using namespace std;

class TourPlan {
private:
    string routeName;
    vector<TouristSpot> spots;
    int totalTime;

public:
    TourPlan(string name);
    string getRouteName() const { return routeName; }
    bool addSpot(const TouristSpot& spot);
    bool removeSpot(const string& spotName);
    void calculateTotalTime();
    void showPlan() const;

    // 新增：获取景点数量
    int getSpotCount() const { return spots.size(); }
};

#endif