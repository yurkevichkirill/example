#define saltLength 8
#define primeNumber 18
#define DATA_SIZE 100

#include <iostream>
#include <fstream>
#include <functional>
#include <conio.h>
#include <windows.h>
#include<string>
#include<iomanip>
#include<time.h>

#include <chrono>
#include <thread>

using namespace std;

#include"Fonts.h"
#include"List.h"
#include"Cart.h"
#include"User.h"
#include"Item.h"
#include"ItemDefinition.h"
#include"UserManage.h"
#include"UserPossibilities.h"
#include"AdmPossibilities.h"
#include"DWPossibilities.h"
#include"Catalog.h"
#include"Menu.h"
#include"Authorization.h"
#include"DataWork.h"
#include"Administrator.h"


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //if (!UserManage::isFileProperlyOpen()) return 0;

    UserManage userManager;

    userManager.loadFromFile();
    userManager.readInfo();
    userManager.readInfoCategories();

    cout << CYAN << "::::::::::::::::::::::::::::::::::::::::::::" << endl <<
        "::::::::::::::::::::::::::::::::::::::::::::" << endl <<
        "::______ _______  ______ _____ ___  ___   ::" << endl <<
        "::|_   _| ____\\ \\/ / ___|_   _/ _ \\|  _ \\ ::" << endl <<
        "::  | | |  _|  \\  / |     | || | | | |_) |::" << endl <<
        "::  | | | |___ /  \\ |___  | || |_| |  __/ ::" << endl <<
        "::  |_| |_____/_/\\_\\____| |_| \\___/|_|    ::" << endl <<
        "::                                        ::" << endl <<
        "::::::::::::::::::::::::::::::::::::::::::::" << endl <<
        "::::::::::::::::::::::::::::::::::::::::::::" << endl;
    Sleep(1000);
    while (true) {
        int flag = 0;
        if (!(UserManage::currentUser)) {
            int selectButton = 0;
            while (true) {
                system("cls");
                cout << setw(20) << "" << CYAN << "Онлайн-магазин техники ТЕХСТОР" << endl;
                cout << setw(20) << "" << BLUE1 << "Главное меню" << WHITE << endl;
                cout << setw(20) << "" << BLUE2 << "Вход не выполнен" << WHITE << endl;
                for (int i = 0; i < 2; ++i) {
                    if (selectButton == i) {
                        cout << BLUEf; // ANSI escape sequence для подсветки фона (inverted colors)
                    }
                    switch (i) {
                    case 0:
                        cout << (selectButton == i ? " > " : "   ") << "1. Авторизация" << endl;
                        break;
                    case 1:
                        cout << (selectButton == i ? " > " : "   ") << "2. Регистрация" << endl;
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
                    if (selectButton == 0) {
                        userManager.logIn();
                        break;
                    }
                    else if (selectButton == 1) {
                        /*if (!UserManage::currentUser || UserManage::currentUser->getAccess() == 0) {
                            cout << RED << "У вас недостаточно прав, чтобы продолжить " << WHITE << endl;
                            system("pause>nul");
                        }
                        else if (!UserManage::currentUser) {
                            cout << "Для начала авторизуйтесь" << endl;
                            system("pause>nul");
                        }
                        else Menu::dataWorking(userManager);*/
                        userManager.regist(1);
                        break;
                    }/*
                    else if (selectButton == 2) {
                        if (!userManager.currentUser) {
                            cout << "Для начала авторизуйтесь" << endl;
                            system("pause>nul");
                        }
                        else if (userManager.currentUser->getRole() == 0) {
                            cout <<RED<< "У вас недостаточно прав, чтобы продолжить "<<WHITE << endl;
                            system("pause>nul");
                        }
                        else {
                            Menu::adminFunctions(userManager);
                        }
                    }
                    else if (selectButton == 3) {
                        userManager.currentUser = nullptr;
                        cout << "Вы вышли из аккаунта" << endl;
                        system("pause>nul");
                    }*/
                }
                else if (key == 27) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) break;
        else {
            if (UserManage::currentUser->getAccess() == 0) {
                system("cls");
                cout << "Ожидайте подтверждения" << endl;
                system("pause>nul");
                break;
            }
            else if (UserManage::currentUser->getAccess() == 1 && UserManage::currentUser->getRole() == 0) {
                cout << setw(20) << "" << BLUE2 << UserManage::currentUser->getLogin();
                cout << " " << PIRPLE << "(Пользователь)" << WHITE << endl;
                Menu::dataWorking(userManager);

                /*system("cls");
                cout << "Нажмите enter, чтобы продолжить работу, иначе программа завершит работу" << endl;
                char over = _getch();
                if (over != 13) {
                    break;
                }*/
            }
            else if (UserManage::currentUser->getAccess() == 1 && UserManage::currentUser->getRole() == 1) {
                cout << setw(20) << "" << BLUE2 << UserManage::currentUser->getLogin();
                cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
                Menu::adminFunctions(userManager);

               /* system("cls");
                cout << "Нажмите enter, чтобы продолжить работу, иначе программа завершит работу" << endl;
                char over = _getch();
                if (over != 13) {
                    break;
                }*/
            }
        }
    }

    userManager.writeInfoCategories();
    userManager.writeInfo();
    userManager.saveToFile();
    return 0;
}