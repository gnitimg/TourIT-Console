#include "TouristSpot.h"
#include <bits/stdc++.h>
using namespace std;

TouristSpot::TouristSpot(string n, string loc, string t, int time, float r)
    : name(n), location(loc), type(t), visitTime(time), rating(r) {
}

void TouristSpot::display() const {
    cout << "��������: " << name << endl;
    cout << "λ��: " << location << endl;
    cout << "����: " << type << endl;
    cout << "��������ʱ��: " << visitTime << " ����" << endl;
    cout << "����: " << rating << "/5.0" << endl;
    cout << "------------------------" << endl;
}