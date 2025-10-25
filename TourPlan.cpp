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
        cout << "���� " << spot.getName() << " �Ѵ��ڣ�" << endl;
        return false;
    }

    spots.push_back(spot);
    calculateTotalTime();
    cout << "�ɹ���Ӿ��㣺" << spot.getName() << endl;
    return true;
}

bool TourPlan::removeSpot(const string& spotName) {
    auto it = find_if(spots.begin(), spots.end(),
        [&](const TouristSpot& s) {
            return s.getName() == spotName;
        });

    if (it == spots.end()) {
        cout << "���� " << spotName << " �����ڣ�" << endl;
        return false;
    }

    spots.erase(it);
    calculateTotalTime();
    cout << "�ɹ�ɾ�����㣺" << spotName << endl;
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
    cout << "����·��: " << routeName << endl;
    cout << "������������: " << spots.size() << " ��" << endl;
    cout << "������ʱ��: " << totalTime << " ����" << endl;
    cout << "------------------------" << endl;

    for (const auto& spot : spots) {
        spot.display();
    }
    cout << "========================" << endl;
}