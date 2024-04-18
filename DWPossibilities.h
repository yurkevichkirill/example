#pragma once

void UserManage::addItem() {
    cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
    string categoryAdd, brend, city;
    string count;
    string price;
    bool isStock;
    
    //do {
        int selectButton = 0;
        while (true) {
            system("cls");
            cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
            cout <<BLUE1<<"�������� ���������� ���������"<<WHITE << endl;

            for (int i = 0; i < categories.getSize(); ++i) {
                if (selectButton == i) {
                    cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
                }
                cout << (selectButton == i ? " > " : "   ") << categories[i] << endl;
                if (selectButton == i) {
                    cout << WHITEf; // ����� ���������
                }
            }

            char key = _getch();
            if (key == -32) {
                key = _getch();
                switch (key) {
                case 72:  // ������� �����
                    selectButton = (selectButton + categories.getSize() - 1) % categories.getSize();
                    break;
                case 80:  // ������� ����
                    selectButton = (selectButton + 1) % categories.getSize();
                    break;
                }
            }
            else if (key == 13) {  // Enter
                categoryAdd = categories[selectButton];
                break;
                //system("pause>nul");
            }
            else if (key == 27) {
                break;
            }
        }

        /*cout << GREY << "����� ������ �������� �� ����� " << 20 << " ��������" << WHITE << endl;
        getline(cin, title);
        if (title.size() > 20) {
            cout << RED << "����� ��������� " << 20 << " ��������" << WHITE << endl;
            cout << "��������� ����" << endl;
        }*/
    //} while (title.size() > 20);

    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
        cout << BLUEf << "������� ����� ������: " << WHITEf << endl;
        cout << GREY << "����� ������ �������� �� ����� " << 20 << " ��������" << WHITE << endl;
        getline(cin, brend);
        if (brend.size() > 20) {
            cout << RED << "����� ��������� " << 20 << " ��������" << WHITE << endl;
            cout << "��������� ����" << endl;
            system("pause>nul");
        }
    } while (brend.size() > 20);

    bool flag;
    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
        cout << BLUEf << "������� ����������: " << WHITEf << endl;
        cout << GREY << "���������� ������ �� 1 �� 999"<<WHITE << endl;
        string test = "0123456789";
        cin >> count;
        flag = true; // ���������� ������������, ��� ���� ���������
        for (char c : count) {
            if (test.find(c) == string::npos) { // ���������, ��� ������ ������ � �����
                flag = false;
                cout << RED << "� ���� ���� �������� ������ ���� �����" << WHITE << endl;
                system("pause>nul");
                break; // ������� �� �����, ���� ������ ������������ ������
            }
        }
        if (flag) {
            int countInt = stoi(count); // ����������� ������ � �����
            if (countInt < 1 || countInt > 999) {
                cout << RED << "������ ����� �� ����� ���� �������" << WHITE << endl;
                flag = false; // ���������, ��� ����� ����� � ���������� ���������
                system("pause>nul");
            }
        }
    } while (count.size() > 3 || !flag);

    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
        cout << BLUEf << "������� ����: " << WHITEf << endl;
        cout << GREY << "���� ������ �� 1 BYN �� 100000 BYN"<<WHITE << endl;
        cin >> price;
        flag = true; // ������������, ��� �������� ������ ���������
        for (char c : price) {
            if (c < '0' || c > '9') {
                flag = false; // ���� ������� ���������� ������, ������ ���� � false
                cout << RED << "���� �����������" << WHITE << endl;
                system("pause>nul");
                break; // ������� �� �����, ��� ��� ��� ����� ������
            }
        }
        if (flag) {
            int priceInt = stoi(price); // ����������� ������ � �����
            if (priceInt < 1 || priceInt > 100000) {
                cout << RED << "������ ����� �� ����� ���� �������" << WHITE << endl;
                flag = false; // ���������, ��� ����� ����� � ���������� ���������
                system("pause>nul");

            }
        }
    } while (!flag); // ���������, ���� ���� �����
    system("pause>nul");
        selectButton = 0;
        while (true) {
            system("cls");
            cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
                cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
                if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
                else { cout << " " << PIRPLE << "(�������������)" << WHITE << endl; }
                cout << BLUE1 << "����� ���� � �������?" << WHITE << endl;
            for (int i = 0; i < 2; ++i) {
                if (selectButton == i) {
                    cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
                }
                switch (i) {
                case 0:
                    cout << (selectButton == i ? " > " : "   ") << "1. ��" << endl;
                    break;
                case 1:
                    cout << (selectButton == i ? " > " : "   ") << "2. ���" << endl;
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
                    selectButton = (selectButton + 1) % 2;
                    break;
                case 80:  // ������� ����
                    selectButton = (selectButton + 1) % 2;
                    break;
                }
            }
            else if (key == 13) {  // Enter
                system("cls");
                switch (selectButton) {
                case 0:
                    isStock = true;
                    break;
                case 1:
                    isStock = false;
                    break;
                }
                break;
            }
        }

    selectButton = 0;
    while (true) {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "����������� ������" << WHITE << endl;
            cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
            if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
            else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        cout << setw(20) << "" << BLUE1 << "�������� �����" << WHITE << endl;
        for (int i = 0; i < 4; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. �����" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. �����" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. ������" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. �������" << endl;
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
                selectButton = (selectButton + 3) % 4;
                break;
            case 80:  // ������� ����
                selectButton = (selectButton + 1) % 4;
                break;
            }
        }
        else if (key == 13) {  // Enter
            switch (selectButton) {
            case 0:
                city = "�����";
                break;
            case 1:
                city = "�����";
                break;
            case 2:
                city = "������";
                break;
            case 3:
                city = "�������";
                break;
            }
            break;  // ����� �� ����� ����� ������
        }
    }

    Item product(categoryAdd, brend, count, price, (isStock==1)?1:0, city);

    itemList.push_back(product);

    cout << GREEN << "����� ������� ���������������!\n" << WHITE << endl;
}

//void UserManage::input(string text, int size) {
//    do {
//        cout << BLUEf << "������� "<<text<<" ������: " << WHITEf;
//        cout << GREY << "����� ������ �������� �� ����� "<<size<<" ��������" << WHITE << endl;
//        getline(cin, text);
//        if (text.size() > size) {
//            cout << RED << "����� ��������� "<<size<<" ��������" << WHITE << endl;
//            cout << "��������� ����";
//        }
//    } while (text.size() > size);
//}

void UserManage::writeInfo() {
    if (isFileProperlyOpen("itemdata.txt")) {
        ofstream fout("itemdata.txt");
        for (int i = 0; i < itemList.getSize(); i++) {
            fout << setw(20) << left << itemList[i].getCategory() << setw(20) << itemList[i].getBrend() << setw(12) <<
                itemList[i].getCount() << setw(11) << itemList[i].getPrice() << setw(10) << (itemList[i].getStock() ? "��" : "���") << setw(20) << itemList[i].getCity() << endl;
        }
        fout.close();
    }
    else cout << RED << "�� ������� ������� ���� ��� ������" <<WHITE<< endl;
}

void UserManage::readInfo() {
    if (isFileProperlyOpen("itemdata.txt")) {
        ifstream fin("itemdata.txt");
        string title, description, count, price, city, isStock;
        while (fin >> title >> description >> count >> price >> isStock >> city) {
            itemList.push_back(Item(title, description, count, price, (isStock == "��") ? true : false, city));
        }
        fin.close();
    }
    else cout<< RED << "�� ������� ������� ���� ��� ������" << WHITE << endl;
}

void UserManage::fillCatalog() {
    string scheduleTitle[8] = { "�������","��","��������","�������","��������","�����������","���������","�����������" };
    string scheduleDescription[8] = { "Samsung","Xiaomi","Realme","Honor","Huawei","Sony","Apple","LG" };
    string scheduleDigit = "123456789";
    string scheduleCity[4] = { "�����","�����","������","�������" };

    srand((unsigned int)time(nullptr));

    for (int i = 0; i < 10; i++) {
        string randomTitle = scheduleTitle[rand() % 8];
        string randomDescription = scheduleDescription[rand() % 8];
        string randomCount;
        for (int i = 0; i < 3; i++) {
            randomCount += scheduleDigit[rand() % 9];
        }
        string randomPrice;
        for (int i = 0; i <1+ rand()%5; i++) {
            randomPrice += scheduleDigit[rand() % 9];
        }
        string randomCity = scheduleCity[rand() % 4];

        itemList.push_back(Item(randomTitle, randomDescription, randomCount, randomPrice, rand() % 2, randomCity));
    }

    cout << PIRPLE << left << setw(20) << "" << "������� �������" << WHITE << endl;

    std::cout << "��������";

    for (int i = 0; i < 10; ++i) {
        std::cout << ".";
        std::cout.flush(); // ���������� ����� ������
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // �������� � 300 �����������
    }

    std::cout << std::endl; // ������� �� ����� ������

    cout <<GREEN<< "������� ������� �������� ���������� ����������" << WHITE << endl;
}

//void UserManage::addItemToCart(const Item& item) {
//    currentUser->getShoppingCart().addItem(item);
//}
