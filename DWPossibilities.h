#pragma once

void UserManage::addItem() {
    cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
    string categoryAdd, brend, city;
    string count;
    string price;
    bool isStock;
    
    //do {
        int selectButton = 0;
        while (true) {
            system("cls");
            cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
            cout <<BLUE1<<"Выберите подходящую категорию"<<WHITE << endl;

            for (int i = 0; i < categories.getSize(); ++i) {
                if (selectButton == i) {
                    cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
                }
                cout << (selectButton == i ? " > " : "   ") << categories[i] << endl;
                if (selectButton == i) {
                    cout << WHITEf; // Сброс подсветки
                }
            }

            char key = _getch();
            if (key == -32) {
                key = _getch();
                switch (key) {
                case 72:  // Стрелка вверх
                    selectButton = (selectButton + categories.getSize() - 1) % categories.getSize();
                    break;
                case 80:  // Стрелка вниз
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

        /*cout << GREY << "Текст должен занимать не более " << 20 << " символов" << WHITE << endl;
        getline(cin, title);
        if (title.size() > 20) {
            cout << RED << "Длина превышает " << 20 << " символов" << WHITE << endl;
            cout << "Повторите ввод" << endl;
        }*/
    //} while (title.size() > 20);

    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
        cout << BLUEf << "Введите бренд товара: " << WHITEf << endl;
        cout << GREY << "Текст должен занимать не более " << 20 << " символов" << WHITE << endl;
        getline(cin, brend);
        if (brend.size() > 20) {
            cout << RED << "Длина превышает " << 20 << " символов" << WHITE << endl;
            cout << "Повторите ввод" << endl;
            system("pause>nul");
        }
    } while (brend.size() > 20);

    bool flag;
    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
        cout << BLUEf << "Введите количество: " << WHITEf << endl;
        cout << GREY << "Количество товара от 1 до 999"<<WHITE << endl;
        string test = "0123456789";
        cin >> count;
        flag = true; // Изначально предполагаем, что ввод корректен
        for (char c : count) {
            if (test.find(c) == string::npos) { // Проверяем, что каждый символ — цифра
                flag = false;
                cout << RED << "В этом поле возможно ввести лишь цифры" << WHITE << endl;
                system("pause>nul");
                break; // Выходим из цикла, если найден недопустимый символ
            }
        }
        if (flag) {
            int countInt = stoi(count); // Преобразуем строку в число
            if (countInt < 1 || countInt > 999) {
                cout << RED << "Данное число не может быть введено" << WHITE << endl;
                flag = false; // Проверяем, что число лежит в допустимом диапазоне
                system("pause>nul");
            }
        }
    } while (count.size() > 3 || !flag);

    do {
        system("cls");
        cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
        cout << BLUEf << "Введите цену: " << WHITEf << endl;
        cout << GREY << "Цена товара от 1 BYN до 100000 BYN"<<WHITE << endl;
        cin >> price;
        flag = true; // Предполагаем, что введённая строка корректна
        for (char c : price) {
            if (c < '0' || c > '9') {
                flag = false; // Если находим нецифровой символ, ставим флаг в false
                cout << RED << "Ввод некорректен" << WHITE << endl;
                system("pause>nul");
                break; // Выходим из цикла, так как уже нашли ошибку
            }
        }
        if (flag) {
            int priceInt = stoi(price); // Преобразуем строку в число
            if (priceInt < 1 || priceInt > 100000) {
                cout << RED << "Данное число не может быть введено" << WHITE << endl;
                flag = false; // Проверяем, что число лежит в допустимом диапазоне
                system("pause>nul");

            }
        }
    } while (!flag); // Повторяем, пока флаг ложен
    system("pause>nul");
        selectButton = 0;
        while (true) {
            system("cls");
            cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
                cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
                if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(Пользователь)" << WHITE << endl;
                else { cout << " " << PIRPLE << "(Администратор)" << WHITE << endl; }
                cout << BLUE1 << "Товар есть в наличии?" << WHITE << endl;
            for (int i = 0; i < 2; ++i) {
                if (selectButton == i) {
                    cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
                }
                switch (i) {
                case 0:
                    cout << (selectButton == i ? " > " : "   ") << "1. Да" << endl;
                    break;
                case 1:
                    cout << (selectButton == i ? " > " : "   ") << "2. Нет" << endl;
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
                    selectButton = (selectButton + 1) % 2;
                    break;
                case 80:  // Стрелка вниз
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
        cout << PIRPLE << setw(20) << "" << "Регистрация товара" << WHITE << endl;
            cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
            if (UserManage::currentUser->getRole() == 0) cout << " " << PIRPLE << "(Пользователь)" << WHITE << endl;
            else cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
        cout << setw(20) << "" << BLUE1 << "Выберите город" << WHITE << endl;
        for (int i = 0; i < 4; ++i) {
            if (selectButton == i) {
                cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
            }
            switch (i) {
            case 0:
                cout << (selectButton == i ? " > " : "   ") << "1. Минск" << endl;
                break;
            case 1:
                cout << (selectButton == i ? " > " : "   ") << "2. Брест" << endl;
                break;
            case 2:
                cout << (selectButton == i ? " > " : "   ") << "3. Гомель" << endl;
                break;
            case 3:
                cout << (selectButton == i ? " > " : "   ") << "4. Витебск" << endl;
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
            switch (selectButton) {
            case 0:
                city = "Минск";
                break;
            case 1:
                city = "Брест";
                break;
            case 2:
                city = "Гомель";
                break;
            case 3:
                city = "Витебск";
                break;
            }
            break;  // Выход из цикла после выбора
        }
    }

    Item product(categoryAdd, brend, count, price, (isStock==1)?1:0, city);

    itemList.push_back(product);

    cout << GREEN << "Товар успешно зарегистрирован!\n" << WHITE << endl;
}

//void UserManage::input(string text, int size) {
//    do {
//        cout << BLUEf << "Введите "<<text<<" товара: " << WHITEf;
//        cout << GREY << "Текст должен занимать не более "<<size<<" символов" << WHITE << endl;
//        getline(cin, text);
//        if (text.size() > size) {
//            cout << RED << "Длина превышает "<<size<<" символов" << WHITE << endl;
//            cout << "Повторите ввод";
//        }
//    } while (text.size() > size);
//}

void UserManage::writeInfo() {
    if (isFileProperlyOpen("itemdata.txt")) {
        ofstream fout("itemdata.txt");
        for (int i = 0; i < itemList.getSize(); i++) {
            fout << setw(20) << left << itemList[i].getCategory() << setw(20) << itemList[i].getBrend() << setw(12) <<
                itemList[i].getCount() << setw(11) << itemList[i].getPrice() << setw(10) << (itemList[i].getStock() ? "Да" : "Нет") << setw(20) << itemList[i].getCity() << endl;
        }
        fout.close();
    }
    else cout << RED << "Не удалось открыть файл для чтения" <<WHITE<< endl;
}

void UserManage::readInfo() {
    if (isFileProperlyOpen("itemdata.txt")) {
        ifstream fin("itemdata.txt");
        string title, description, count, price, city, isStock;
        while (fin >> title >> description >> count >> price >> isStock >> city) {
            itemList.push_back(Item(title, description, count, price, (isStock == "Да") ? true : false, city));
        }
        fin.close();
    }
    else cout<< RED << "Не удалось открыть файл для записи" << WHITE << endl;
}

void UserManage::fillCatalog() {
    string scheduleTitle[8] = { "Ноутбук","ПК","Смартфон","Планшет","Наушники","Видеокамера","Телевизор","Фотоаппарат" };
    string scheduleDescription[8] = { "Samsung","Xiaomi","Realme","Honor","Huawei","Sony","Apple","LG" };
    string scheduleDigit = "123456789";
    string scheduleCity[4] = { "Брест","Минск","Гомель","Витебск" };

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

    cout << PIRPLE << left << setw(20) << "" << "Каталог товаров" << WHITE << endl;

    std::cout << "Загрузка";

    for (int i = 0; i < 10; ++i) {
        std::cout << ".";
        std::cout.flush(); // Сбрасываем буфер вывода
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Задержка в 300 миллисекунд
    }

    std::cout << std::endl; // Переход на новую строку

    cout <<GREEN<< "Каталог успешно заполнен случайными значениями" << WHITE << endl;
}

//void UserManage::addItemToCart(const Item& item) {
//    currentUser->getShoppingCart().addItem(item);
//}
