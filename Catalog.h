#include "UserManage.h"
#pragma once
void UserManage::seeCatalog() {
    if (itemList.getSize() == 0) {
        cout << "�� ������ ������ ������� ������� ����" << endl;
        return;
    }
    int selectButton = 0;
    char select;
    while (true) {
        system("cls");
        cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
        else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        cout << setw(20) << "�������� ������, ������� ������ �������� � �������" << endl;
        cout << YELLOW << setw(20) << "���������" << setw(20) << "�����" << setw(12) << "����������" << setw(11) << "����, BYN"
            << setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
        for (int i = 0; i < itemList.getSize(); ++i) {
            cout << itemList[i] << endl;
        }
        cout << endl << BLUE1 << "1. ������������� ������" << WHITE << endl;
        cout << BLUE1 << "2. ������������� ������" << WHITE << endl;

        select = _getch();
        switch (select) {
        case 49:
            sorting();
            break;
        case 50:
            filtering();
            break;
        }
            if (select == 27) {
                break;
            }
    }
    if (select == 27) return;

    while (true) {
        system("cls");
        cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
        else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        cout << setw(20) << "�������� ������, ������� ������ �������� � �������" << endl;
        cout << YELLOW << setw(20) << "���������" << setw(20) << "�����" << setw(12) << "����������" << setw(11) << "����, BYN"
            << setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
        for (int i = 0; i < itemList.getSize(); ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
            }
            cout << (selectButton == i ? " > " : "   ") << itemList[i] << endl;
            if (selectButton == i) {
                cout << WHITEf; // ����� ���������
            }
        }

        char key = _getch();
        if (key == -32) {
            key = _getch();
            switch (key) {
            case 72:  // ������� �����
                selectButton = (selectButton + itemList.getSize() - 1) % itemList.getSize();
                break;
            case 80:  // ������� ����
                selectButton = (selectButton + 1) % itemList.getSize();
                break;
            }
        }
        else if (key == 13) {  // Enter
            system("cls");
            /*addItemToCart(itemList[selectButton]);*/
            system("pause>nul");
        }
        else if (key == 27) {
            break;
        }
    }
}

void UserManage::sorting() {
    int selectButton = 0;
    while (true) {
        system("cls");
        cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
        else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        cout << setw(20) << "" << "�������� ��� ����������" << endl;
        for (int i = 0; i < 3; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. �� ���������� ����" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. �� ���������� ����" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. �� ��������" << endl;
                break;
            }
            if (selectButton == i) {
                cout << WHITEf; // ����� ���������
            }
        }

        char key = _getch();
        if (key == -32) {
            key = _getch();
            switch (key) {
            case 72:  // ������� �����
                selectButton = (selectButton + 2) % 3;
                break;
            case 80:  // ������� ����
                selectButton = (selectButton + 1) % 3;
                break;
            }
        }
        else if (key == 13) {  // Enter
            system("cls");
            cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
            cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
            if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
            else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
            if (selectButton == 0) {
                cout << YELLOW << setw(20)<<left<<"��������" << setw(20) << "��������" << setw(12) << "����������" << BLUE1 << setw(11) << "����, BYN"
                    <<YELLOW<< setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
                sortByPriceUp();

                for (int i = 0; i < itemList.getSize(); i++) {
                    cout << itemList[i] << endl;
                }
            }
            else if (selectButton == 1) {
                cout << YELLOW << setw(20) << left << "��������" << setw(20) << "��������" << setw(12) << "����������" << BLUE1 << setw(11) << "����, BYN"
                    << YELLOW << setw(10) << "�� ������" << setw(15) << "�����" << WHITE << endl;
                sortByPriceDown();
                for (int i = 0; i < itemList.getSize(); i++) {
                    cout << itemList[i] << endl;
                }
            }
            else if (selectButton == 2) {
                cout << BLUE1 << setw(20)<< left <<"��������" << YELLOW << setw(20) << "��������" << setw(12) << "����������" << setw(11) << "����, BYN"
                    <<setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
                sortByTitle();
                for (int i = 0; i < itemList.getSize(); i++) {
                    cout << itemList[i] << endl;
                }
            }
            system("pause>nul");
        }
        else if (key == 27) {
            break;
        }
    }
}

void UserManage::sortByPriceUp() {
    for (int i = 0; i < itemList.getSize(); i++) {
        for (int j = i + 1; j < itemList.getSize(); j++) {
            if (stoi(itemList[i].getPrice()) >stoi(itemList[j].getPrice())) {
                Item temp = itemList[i];
                itemList[i] = itemList[j];
                itemList[j] = temp;
            }
        }
    }
}

void UserManage::sortByPriceDown() {
    for (int i = 0; i < itemList.getSize(); i++) {
        for (int j = i + 1; j < itemList.getSize(); j++) {
            if (stoi(itemList[i].getPrice()) < stoi(itemList[j].getPrice())) {
                Item temp = itemList[i];
                itemList[i] = itemList[j];
                itemList[j] = temp;
            }
        }
    }
}

void UserManage::sortByTitle() {
    for (int i = 0; i < itemList.getSize(); i++) {
        for (int j = i + 1; j < itemList.getSize(); j++) {
            if (itemList[i].getCategory() > itemList[j].getCategory()) {
                Item temp = itemList[i];
                itemList[i] = itemList[j];
                itemList[j] = temp;
            }
        }
    }
}


void UserManage::filtering() {
    int selectButton = 0;
    while (true) {
        system("cls");
        cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
        else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        cout << setw(20) << "" << "�������� ��� ����������" << endl;
        for (int i = 0; i < 5; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. �� ���������" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. �� ������� " << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. �� ������" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. �� ���� (�������)" << endl;
                break;
            case 4:
                cout << (selectButton == i ? " > " : "   ") << "4. �� ���� (��������)" << endl;
                break;
            }
            if (selectButton == i) {
                cout << WHITEf; // ����� ���������
            }
        }

        char key = _getch();
        if (key == -32) {
            key = _getch();
            switch (key) {
            case 72:  // ������� �����
                selectButton = (selectButton + 4) % 5;
                break;
            case 80:  // ������� ����
                selectButton = (selectButton + 1) % 5;
                break;
            }
        }
        else if (key == 13) {  // Enter
            system("cls");
            cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;
            cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
            if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
            else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
            switch (selectButton) {
            case 0:
            {

                cout << BLUE1 << setw(20) << "" << "������� ���������, ������� �� ������ �������" << WHITE << endl;
                string category;
                getline(cin, category);
                cout << BLUE1 << setw(20)<< left << "���������" << YELLOW << setw(20) << "�����" << setw(12) << "����������" << setw(11) << "����, BYN"
                    << setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
                filterByCategory(category);
                break;
            }
            case 1:
            {
                cout << YELLOW << setw(20)<< left << "���������" << setw(20) << "�����" << setw(12) << "����������" << setw(11) << "����, BYN"
                    << BLUE1 << setw(10)  << "�� ������" << YELLOW << setw(15) << "�����" << setw(20) << WHITE << endl;
                filterByStock();
                break;
            }
            case 2:
            {
                cout << BLUE1 << setw(20) << "" << "������� �����, ������ �� ������ ������� ������" << WHITE << endl;
                string city;
                getline(cin, city);
                cout << YELLOW << setw(20)<< left << "���������" << setw(20) << "�����" << setw(12) << "����������" << setw(11) << "����, BYN"
                    << setw(10) << "�� ������" << BLUE1 << setw(15)  << "�����" << setw(20) << WHITE << endl;
                filterByTown(city);
                break;
            }
            case 3:
            {
                cout << BLUE1 << setw(20) << "" << "������� ����������� ���� �������"<<WHITE << endl;
                int price;
                cin >> price;
                cout << YELLOW << setw(20)<< left << "���������" << setw(20) << "�����" << setw(12) << "����������" << BLUE1 << setw(11)  << "����, BYN"
                    << YELLOW << setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
                filterByPriceMin(price);
                break;
            }
            case 4:
            {
                cout <<BLUE1<<setw(20)<<""<< "������� ������������ ���� �������"<<WHITE << endl;
                int price;
                cin >> price;
                cout << YELLOW << setw(20)<< left << "���������" << setw(20) << "�����" << setw(12) << "����������" << BLUE1 << setw(11)  << "����, BYN"
                    << YELLOW << setw(10) << "�� ������" << setw(15) << "�����" << setw(20) << WHITE << endl;
                filterByPriceMax(price);
                break;
            }
            }
            system("pause>nul");
        }
        else if (key == 27) {
            break;
        }
    }
}

void UserManage::filterByCategory(string category) {
    int flag = 0;
    for (int i = 0; i < itemList.getSize(); i++) {
        if (itemList[i].getCategory() == category) {
            cout << itemList[i] << endl;
            flag = 1;
        }
    }
    if (!flag) {
        system("cls");
        cout << RED << "������ �� �������" << WHITE << endl;
    }
}

void UserManage::filterByStock() {
    int flag = 0;
    for (int i = 0; i < itemList.getSize(); i++) {
        if (itemList[i].getStock()==true) {
            cout << itemList[i] << endl;
            flag = 1;
        }
    }
    if (!flag) {
        system("cls");
        cout << RED << "������ �� �������" << WHITE << endl;
    }
}

void UserManage::filterByTown(string town) {
    int flag = 0;
    for (int i = 0; i < itemList.getSize(); i++) {
        if (itemList[i].getCity() == town) {
            cout << itemList[i] << endl;
            flag = 1;
        }
    }
    if (!flag) {
        system("cls");
        cout << RED << "������ �� �������" << WHITE << endl;
    }
}

void UserManage::filterByPriceMin(int price) {
    int flag = 0;
    for (int i = 0; i < itemList.getSize(); i++) {
        if (stoi(itemList[i].getPrice())>price) {
            cout << itemList[i] << endl;
            flag = 1;
        }
    }
    if (!flag) {
        system("cls");
        cout << RED << "������ �� �������" << WHITE << endl;
    }
}

void UserManage::filterByPriceMax(int price) {
    int flag = 0;
    for (int i = 0; i < itemList.getSize(); i++) {
        if (stoi(itemList[i].getPrice()) < price) {
            cout << itemList[i] << endl;
            flag = 1;
        }
    }
    if (!flag) {
        system("cls");
        cout << RED << "������ �� �������" << WHITE << endl;
    }
}