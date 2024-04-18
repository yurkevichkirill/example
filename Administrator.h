#pragma once
void Menu::adminFunctions(UserManage& userManager) {

    int selectButton = 0;
    while (true) {
        system("cls");
        cout << setw(20) << "" << CYAN << "Онлайн-магазин техники ТЕХСТОР" << endl;
        cout << setw(20) << "" << BLUE1 << "Функции администратора" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
        for (int i = 0; i < 3; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. Учетные записи" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. Онлайн-магазин" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. Выйти из аккаунта" << endl;
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
            if (selectButton == 0) {
                adminAccountFunctions(userManager);
            }
            else if (selectButton == 1) {
                adminStoreFunctions(userManager);
            }
            else {
                userManager.logOut();
                break;
            }
        }
        else if (key == 27) {
            break;
        }
    }
    
    
    return;
}

void Menu::adminAccountFunctions(UserManage& userManager) {
    int selectButton = 0;
    while (true) {
        system("cls");
        cout << setw(20) << "" << CYAN << "Онлайн-магазин техники ТЕХСТОР" << endl;
        cout << setw(20) << "" << BLUE1 << "Функции администратора" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;

        for (int i = 0; i < 8; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. Посмотреть данные пользователей" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. Зарегистрировать пользователя" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. Зарегистрировать администратора" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. Редактировать пользователя" << endl;
                break;
            case 4:
                cout << (selectButton == i ? " > " : "   ") << "5. Удалить пользователя" << endl;
                break;
            case 5:
                cout << (selectButton == i ? " > " : "   ") << "6. Предоставить права администратора" << endl;
                break;
            case 6:
                cout << (selectButton == i ? " > " : "   ") << "7. Подтвердить всех пользователей" << endl;
                break;
            case 7:
                cout << (selectButton == i ? " > " : "   ") << "8. Подтвердить конкретного пользователя" << endl;
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
                selectButton = (selectButton + 7) % 8;
                break;
            case 80:  // Стрелка вниз
                selectButton = (selectButton + 1) % 8;
                break;
            }
        }
        else if (key == 13) {  // Enter
            system("cls");
            switch (selectButton) {
            case 0:
                userManager.seeAllUsers();
                break;
            case 1:
                userManager.addUser(0);
                break;
            case 2:
                userManager.addUser(1);
                break;
            case 3:
                userManager.editUser();
                break;
            case 4:
                userManager.deleteUser();
                break;
            case 5:
                userManager.giveRights();
                break;
            case 6:
                userManager.confirmAll();
                break;
            case 7:
                userManager.confirmOne();
                break;
            }
            system("pause>nul");
        }
        else if (key == 27) {
            break;
        }
    }
}

void Menu::adminStoreFunctions(UserManage& userManager) {
    int selectButton = 0;
    while (true) {
        system("cls");
        cout << setw(20) << "" << CYAN << "Онлайн-магазин техники ТЕХСТОР" << endl;
        cout << setw(20) << "" << BLUE1 << "Функции администратора" << WHITE << endl;
        cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
        cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;

        for (int i = 0; i < 4; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. Посмотреть все категории каталога" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. Добавить новую категорию каталога" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. Изменить категорию каталога" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. Удалить категорию каталога" << endl;
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
                selectButton = (selectButton + 3) % 4;
                break;
            case 80:  // Стрелка вниз
                selectButton = (selectButton + 1) % 4;
                break;
            }
        }
        else if (key == 13) {  // Enter
            system("cls");
            switch (selectButton) {
            case 0:
                cout << BLUE1 << setw(20) << "" << "Категории товаров" << WHITE << endl;
                cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
                cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
                userManager.seeAllCategories();
                break;
            case 1:
                userManager.addCategory();
                break;
            case 2:
                userManager.editCategory();
                break;
            case 3:
                userManager.deleteCategory();
                break;
            }
            system("pause>nul");
        }
        else if (key == 27) {
            break;
        }
    }
}