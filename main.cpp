//Version 1.0

#include "TourPlan.h"
#include <bits/stdc++.h>
using namespace std;

vector<shared_ptr<TourPlan>> allPlans;//·���б�

// ���˵�
void showMainMenu() {
    cout << "\n=== TourIT! ����·�߹滮ϵͳ ===" << endl;
    cout << "1. �½�·��" << endl;
    cout << "2. �鿴����·��" << endl;
    cout << "3. �༭·��" << endl;
    cout << "4. ɾ��·��" << endl;
    cout << "5. �˳�ϵͳ" << endl;
    cout << "��ѡ����� (1-5): ";
}

// ·�߱༭�˵�
void showEditMenu() {
    cout << "\n--- ·�߱༭�˵� ---" << endl;
    cout << "1. ��Ӿ���" << endl;
    cout << "2. ɾ������" << endl;
    cout << "3. �鿴·������" << endl;
    cout << "4. �������˵�" << endl;
    cout << "��ѡ����� (1-4): ";
}

// �������ξ���
TouristSpot createTouristSpot() {
    string name, location, type;
    int time;
    float rating;

    cout << "\n--- ����¾��� ---" << endl;

    cout << "�����뾰������: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "�����뾰��λ��: ";
    getline(cin, location);

    cout << "�����뾰������: ";
    getline(cin, type);

    cout << "�����뽨������ʱ��(����): ";
    cin >> time;

    cout << "�����뾰������(0-5): ";
    cin >> rating;

    if (rating < 0) rating = 0;
    if (rating > 5) rating = 5;

    return TouristSpot(name, location, type, time, rating);
}

// �½�·��
void createNewPlan() {
    string routeName;
    cout << "������·������: ";
    cin.ignore();
    getline(cin, routeName);

    auto newPlan = make_shared<TourPlan>(routeName);
    allPlans.push_back(newPlan);
    cout << "�ɹ�����·��: " << routeName << endl;
}

// �鿴����·��
void viewAllPlans() {
    if (allPlans.empty()) {
        cout << "��ǰû���κ�·�ߣ�" << endl;
        return;
    }

    cout << "\n=== ��������·�� ===" << endl;
    for (int i = 0; i < allPlans.size(); i++) {
        cout << i + 1 << ". ";
        allPlans[i]->showPlan(); 
    }
}

// ѡ��Ҫ�༭��·��
int selectPlan() {
    if (allPlans.empty()) {
        cout << "��ǰû���κ�·�ߣ�" << endl;
        return -1;
    }

    cout << "\n=== ѡ��Ҫ�༭��·�� ===" << endl;
    for (int i = 0; i < allPlans.size(); i++) {
        cout << i + 1 << ". ·�� " << (i + 1) << endl;
    }

    int choice;
    cout << "��ѡ��·�� (1-" << allPlans.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > allPlans.size()) {
        cout << "��Чѡ��" << endl;
        return -1;
    }

    return choice - 1;
}

// �༭·��
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
            // ��Ӿ���
            TouristSpot newSpot = createTouristSpot();
            currentPlan->addSpot(newSpot);
            break;
        }

        case 2: {
            // ɾ������
            if (currentPlan->getSpotCount() == 0) 
            {
                cout << "��ǰ·��û�о��㣡" << endl;
                break;
            }
            string spotName;
            cout << "������Ҫɾ���ľ�������: ";
            cin.ignore();
            getline(cin, spotName);
            currentPlan->removeSpot(spotName);
            break;
        }

        case 3: {
            // ·������
            currentPlan->showPlan();
            break;
        }

        case 4:
            cout << "�������˵�..." << endl;
            break;

        default:
            cout << "��Чѡ�����������룡" << endl;
            break;
        }

    } while (editChoice != 4);
}

// ɾ��·��
void deletePlan() {
    int planIndex = selectPlan();
    if (planIndex == -1) return;

    cout << "ȷ��Ҫɾ��·����(y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        allPlans.erase(allPlans.begin() + planIndex);
        cout << "·��ɾ���ɹ���" << endl;
    }
    else {
        cout << "ȡ��ɾ����" << endl;
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
            cout << "��лʹ�� TourIT! ϵͳ" << endl;
            break;

        default:
            cout << "��Чѡ�����������룡" << endl;
            break;
        }

    } while (mainChoice != 5);

    return 0;
}