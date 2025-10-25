#include "TouristSpot.h"
#include <bits/stdc++.h>
using namespace std;

TouristSpot::TouristSpot(string n, string loc, string t, int time, float r)
    : name(n), location(loc), type(t), visitTime(time), rating(r) {
}

void TouristSpot::display() const {
    cout << "景点名称: " << name << endl;
    cout << "位置: " << location << endl;
    cout << "类型: " << type << endl;
    cout << "建议游览时间: " << visitTime << " 分钟" << endl;
    cout << "评分: " << rating << "/5.0" << endl;
    cout << "------------------------" << endl;
}