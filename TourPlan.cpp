#include "TourPlan.h"
#include <iostream>
#include <algorithm>
using namespace std;

TourPlan::TourPlan(string name)
    : routeName(name), totalTime(0) {
}

bool TourPlan::addSpot(const TouristSpot& spot) {
    auto it = find_if(spots.begin(), spots.end(),
        [&](const TouristSpot& s) {
            return s.getName() == spot.getName();
        });

    if (it != spots.end()) {
        cout << "景点 " << spot.getName() << " 已存在！" << endl;
        return false;
    }

    spots.push_back(spot);
    calculateTotalTime();
    cout << "成功添加景点：" << spot.getName() << endl;
    return true;
}

bool TourPlan::removeSpot(const string& spotName) {
    auto it = find_if(spots.begin(), spots.end(),
        [&](const TouristSpot& s) {
            return s.getName() == spotName;
        });

    if (it == spots.end()) {
        cout << "景点 " << spotName << " 不存在！" << endl;
        return false;
    }

    spots.erase(it);
    calculateTotalTime();
    cout << "成功删除景点：" << spotName << endl;
    return true;
}

void TourPlan::calculateTotalTime() {
    totalTime = 0;
    for (const auto& spot : spots) {
        totalTime += spot.getVisitTime();
    }
}

void TourPlan::showPlan() const {
    cout << "========================" << endl;
    cout << "旅游路线: " << routeName << endl;
    cout << "包含景点数量: " << spots.size() << " 个" << endl;
    cout << "总游览时间: " << totalTime << " 分钟" << endl;
    cout << "------------------------" << endl;

    for (const auto& spot : spots) {
        spot.display();
    }
    cout << "========================" << endl;
}