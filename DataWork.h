#pragma once

void Menu::dataWorking(UserManage& userManager) {
    int selectButton = 0;
    while (true) {
        system("cls");
        cout << setw(20) << "" << CYAN << "������-������� ������� �������" << endl;
        cout << setw(20) << "" << BLUE1 << "������ � �������" << WHITE << endl;
        if (UserManage::currentUser == nullptr) {
            cout << "�������������, ����� ����������" << endl;
            _getch();
            return;
        }
        else {
            cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
            if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(������������)" << WHITE << endl;
            else cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
        }
        for (int i = 0; i < 6; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence ��� ��������� ���� (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. ������� � �������� �������" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. ���������������� �����" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. ��������� ������� ���������� ����������" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. ������� � ������� �������" << endl;
                break;
            case 4:
                cout << (selectButton == i ? " > " : "   ") << "5. ��� ������������������ ������" << endl;
                break;
            case 5:
                cout << (selectButton == i ? " > " : "   ") << "6. ����� �� ��������" << endl;
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
                    selectButton = (selectButton + 5) % 6;
                    break;
                case 80:  // ������� ����
                    selectButton = (selectButton + 1) % 6;
                    break;
                }
            }
            else if (key == 13) {  // Enter
                system("cls");
                switch (selectButton) {
                case 0:
                    userManager.seeCatalog();
                    break;
                case 1:
                    userManager.addItem();
                    break;
                case 2:
                    userManager.fillCatalog();
                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:
                    userManager.logOut();
                    break;
                }
                system("pause>nul");
            }
            else if (key == 27) {
                break;
            }
        }

        return;
    }