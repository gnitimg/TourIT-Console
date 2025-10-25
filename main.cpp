//Version 1.0

#include "TourPlan.h"
#include <bits/stdc++.h>
using namespace std;

vector<shared_ptr<TourPlan>> allPlans;//路线列表

// 主菜单
void showMainMenu() {
    cout << "\n=== TourIT! 旅游路线规划系统 ===" << endl;
    cout << "1. 新建路线" << endl;
    cout << "2. 查看所有路线" << endl;
    cout << "3. 编辑路线" << endl;
    cout << "4. 删除路线" << endl;
    cout << "5. 退出系统" << endl;
    cout << "请选择操作 (1-5): ";
}

// 路线编辑菜单
void showEditMenu() {
    cout << "\n--- 路线编辑菜单 ---" << endl;
    cout << "1. 添加景点" << endl;
    cout << "2. 删除景点" << endl;
    cout << "3. 查看路线详情" << endl;
    cout << "4. 返回主菜单" << endl;
    cout << "请选择操作 (1-4): ";
}

// 创建旅游景点
TouristSpot createTouristSpot() {
    string name, location, type;
    int time;
    float rating;

    cout << "\n--- 添加新景点 ---" << endl;

    cout << "请输入景点名称: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "请输入景点位置: ";
    getline(cin, location);

    cout << "请输入景点类型: ";
    getline(cin, type);

    cout << "请输入建议游览时间(分钟): ";
    cin >> time;

    cout << "请输入景点评分(0-5): ";
    cin >> rating;

    if (rating < 0) rating = 0;
    if (rating > 5) rating = 5;

    return TouristSpot(name, location, type, time, rating);
}

// 新建路线
void createNewPlan() {
    string routeName;
    cout << "请输入路线名称: ";
    cin.ignore();
    getline(cin, routeName);

    auto newPlan = make_shared<TourPlan>(routeName);
    allPlans.push_back(newPlan);
    cout << "成功创建路线: " << routeName << endl;
}

// 查看所有路线
void viewAllPlans() {
    if (allPlans.empty()) {
        cout << "当前没有任何路线！" << endl;
        return;
    }

    cout << "\n=== 所有旅游路线 ===" << endl;
    for (int i = 0; i < allPlans.size(); i++) {
        cout << i + 1 << ". ";
        allPlans[i]->showPlan(); 
    }
}

// 选择要编辑的路线
int selectPlan() {
    if (allPlans.empty()) {
        cout << "当前没有任何路线！" << endl;
        return -1;
    }

    cout << "\n=== 选择要编辑的路线 ===" << endl;
    for (int i = 0; i < allPlans.size(); i++) {
        cout << i + 1 << ". 路线 " << (i + 1) << endl;
    }

    int choice;
    cout << "请选择路线 (1-" << allPlans.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > allPlans.size()) {
        cout << "无效选择！" << endl;
        return -1;
    }

    return choice - 1;
}

// 编辑路线
void editPlan() {
    int planIndex = selectPlan();
    if (planIndex == -1) return;

    auto& currentPlan = allPlans[planIndex];
    int editChoice;

    do {
        showEditMenu();
        cin >> editChoice;

        switch (editChoice) {
        case 1: {
            // 添加景点
            TouristSpot newSpot = createTouristSpot();
            currentPlan->addSpot(newSpot);
            break;
        }

        case 2: {
            // 删除景点
            if (currentPlan->getSpotCount() == 0) 
            {
                cout << "当前路线没有景点！" << endl;
                break;
            }
            string spotName;
            cout << "请输入要删除的景点名称: ";
            cin.ignore();
            getline(cin, spotName);
            currentPlan->removeSpot(spotName);
            break;
        }

        case 3: {
            // 路线详情
            currentPlan->showPlan();
            break;
        }

        case 4:
            cout << "返回主菜单..." << endl;
            break;

        default:
            cout << "无效选择，请重新输入！" << endl;
            break;
        }

    } while (editChoice != 4);
}

// 删除路线
void deletePlan() {
    int planIndex = selectPlan();
    if (planIndex == -1) return;

    cout << "确定要删除路线吗？(y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        allPlans.erase(allPlans.begin() + planIndex);
        cout << "路线删除成功！" << endl;
    }
    else {
        cout << "取消删除。" << endl;
    }
}

int main() {
    int mainChoice;

    do {
        showMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            createNewPlan();
            break;

        case 2:
            viewAllPlans();
            break;

        case 3:
            editPlan();
            break;

        case 4:
            deletePlan();
            break;

        case 5:
            cout << "感谢使用 TourIT! 系统" << endl;
            break;

        default:
            cout << "无效选择，请重新输入！" << endl;
            break;
        }

    } while (mainChoice != 5);

    return 0;
}