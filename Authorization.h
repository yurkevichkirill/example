#pragma once

void Menu::authorization(UserManage& userManager) {
        int selectButton = 0;
        while (true) {
            system("cls");
            cout << setw(20) << "" << CYAN << "Онлайн-магазин техники ТЕХСТОР" << endl;
            cout << setw(20) << "" << BLUE1 << "Авторизация" << WHITE << endl;
            if (UserManage::currentUser == nullptr) {
                cout << setw(20) << "" << BLUE2 << "Вход не выполнен" << WHITE << endl;
            }
            else {
                cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
                if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(Пользователь)" << WHITE << endl;
                else cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
            }
            for (int i = 0; i < 3; ++i) {
                if (selectButton == i) {
                    cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
                }
                switch (i) {
                case 0:
                    cout << (selectButton == i ? " > " : "   ") << "1. Регистрация" << endl;
                    break;
                case 1:
                    cout << (selectButton == i ? " > " : "   ") << "2. Вход" << endl;
                    break;
                case 2:
                    cout << (selectButton == i ? " > " : "   ") << "3. Изменить пароль" << endl;
                    break;
                }
                if (selectButton == i) {
                    cout << WHITEf; // Сброс подсветки
                }
            }

            char key = _getch();
            if (key == -32) {
                key = _getch();
                switch (key) {
                case 72:  // Стрелка вверх
                    selectButton = (selectButton + 2) % 3;
                    break;
                case 80:  // Стрелка вниз
                    selectButton = (selectButton + 1) % 3;
                    break;
                }
            }
            else if (key == 13) {  // Enter
                system("cls");

                cout << setw(20) << "" << BLUE2 << "Регистрация" << WHITE << endl;
                if (selectButton == 0) {
                    if (UserManage::currentUser) {
                        cout << "Вы уже вошли в систему" << endl;
                        system("pause>nul");
                    }
                    else userManager.regist(1);
                }
                else if (selectButton == 1) {
                    userManager.logIn();
                }
                else if (selectButton == 2) {
                    if (UserManage::currentUser != nullptr) {
                        userManager.changePassword();
                    }
                    else cout << "Для начала войдите в систему" << endl;
                }
                system("pause>nul");
            }
            else if (key == 27) {
                break;
            }
        }
    

	return;
}