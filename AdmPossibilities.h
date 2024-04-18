#include "UserManage.h"
#pragma once
//ACCOUNTS
void UserManage::seeAllUsers() {
	cout << setw(20) << "" << PIRPLE << "Список пользователей" << WHITE << endl;
	cout << YELLOW<<setw(2)<<"№" << setw(19) << "ЛОГИН" << setw(6) << "РОЛЬ" << setw(9) << "ДОСТУП" << WHITE << endl;
	for (int i = 0; i < listManage.getSize(); i++) {
		cout<<setw(2) << i + 1 << " " <<setw(18)<< listManage[i].getLogin() << setw(6) << listManage[i].getRole() << setw(9) << listManage[i].getAccess() << endl;
	}
}

void UserManage::addUser(int role) {
	cout << setw(20) << "" << PIRPLE << "Добавление пользователя" << WHITE << endl;
	string username;
	string password;

	regist(0);
	if (role == 1) {
		listManage[listManage.getSize() - 1].setRole(1);
		listManage[listManage.getSize() - 1].setAccess(1);
	}

}

void UserManage::editUser()
{
	cout << setw(20) << "" << PIRPLE << "Редактирование пользователя" << WHITE << endl;
	seeAllUsers();

	int num;
	cout << BLUEf << "Введите логин пользователя, которого вы хотите редактировать" <<WHITEf<< endl;
	string loginEdit;
	cin >> loginEdit;

	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginEdit) {
			if (listManage[i].getAccess() == 0) {
				cout << "Чтобы предоставить пользователю доступ нажмите enter" << endl;
				char key = _getch();
				if (key == 13) {
					listManage[i].setAccess(1);
					cout << GREEN << "Доступ пользователя изменен" << WHITE << endl;
				}
			}
			else {
				cout << "Чтобы заблокировать пользователя нажмите enter" << endl;
				char key = _getch();
				if (key == 13) {
					listManage[i].setAccess(0);
					listManage[i].setRole(0);
					cout << RED << "Пользователь заблокирован" << WHITE << endl;
				}
			}
			cout << YELLOW << "Измененный пользователь " << listManage[i].getLogin() <<listManage[i].getRole() << " " << listManage[i].getAccess() << WHITE << endl;
			return;
		}
	}
	cout << RED << endl << "Не существует пользователя с таким логином" << WHITE << endl;
}

void UserManage::deleteUser() {
	cout << setw(20) << "" << PIRPLE << "Удаление пользователя" << WHITE << endl;
	seeAllUsers();
	cout <<BLUEf<< "Введите логин пользователя, которого хотите удалить"<<WHITEf << endl;
	string loginDel;
	cin >> loginDel;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginDel) {
			cout << "Вы уверены, что хотите удалить пользователя " << PIRPLE << loginDel << WHITE<<"?"  << endl;
			cout << GREY << "Введите \"да\", чтобы продолжить" << WHITE << endl;
			string confirm;
			cin >> confirm;
			if (confirm == "да") {
				if (UserManage::currentUser->getLogin() != loginDel) {
					listManage.removeAt(i);
					cout << "Пользователь " << loginDel << " успешно удален" << endl;
					return;
				}
				else {
					cout << RED << "Вы не можете удалить себя" << WHITE << endl;
					return;
				}
			}
		}
	}
	cout << RED << "Не существует пользователя с таким логином" << WHITE << endl;
}

void UserManage::giveRights() {
	cout << setw(20) << "" << PIRPLE << "Передача прав администратора" << WHITE << endl;
	cout << BLUEf << "Введите логин пользователя, которому хотите предоставить права администратора" << WHITEf << endl;
	string loginAdmin;
	cin >> loginAdmin;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginAdmin) {
			cout << "Вы уверены, что хотите предоставить права пользователю " << PIRPLE << loginAdmin << WHITE << "?" << endl;
			cout << GREY << "Введите \"да\", чтобы продолжить" << WHITE << endl;
			string confirm;
			cin >> confirm;
			if (confirm == "да") {
				if (UserManage::currentUser->getLogin() != loginAdmin) {
					listManage[i].setRole(1);
					cout <<YELLOW<< "Пользователь " <<PIRPLE<< loginAdmin <<YELLOW<< " получил права администратора"<<WHITE << endl;
					return;
				}
			}
		}
	}
	cout << RED << "Не существует пользователя с таким логином" << WHITE << endl;
}

void UserManage::confirmAll() {
	cout << setw(20) << "" << PIRPLE << "Подтверждение пользователей" << WHITE << endl;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		listManage[i].setAccess(1);
	}
	cout << GREEN << "Все пользователи получили доступ" << WHITE << endl;
	seeAllUsers();
}

void UserManage::confirmOne() {
	cout << setw(20) << "" << PIRPLE << "Подтверждение пользователя" << WHITE << endl;

	cout << BLUEf << "Введите логин пользователя, которого хотите подтвердить" << WHITEf << endl;
	string loginAdmin;
	cin >> loginAdmin;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginAdmin) {			
				if (UserManage::currentUser->getLogin() != loginAdmin) {
					listManage[i].setAccess(1);
					cout <<YELLOW<< "Пользователь " <<PIRPLE<< loginAdmin << YELLOW<<" подтвержден"<<WHITE << endl;
					return;
				}
		}
	}
	cout << RED << "Не существует пользователя с таким логином" << WHITE << endl;
}
//STORE
void UserManage::addCategory() {
	cout << BLUE1 << setw(20) << "" << "Добавление категории товаров" <<WHITE<< endl;
	cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
	cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
	seeAllCategories();
	cout << "Введите название категории, которую вы хотите добавить" << endl;
	string category;
	getline(cin, category);

	for (int i = 0; i < categories.getSize(); i++) {
		if (categories[i] == category) {
			cout << "Данная категория уже существует" << endl;
			return;
		}
	}
	categories.push_back(category);
	cout <<GREEN<< "Категория " <<PIRPLE<<category<<GREEN<< " успешно добавлена"<<WHITE<<endl;
}

void UserManage::deleteCategory() {
	if (!seeAllCategories()) return;
	int selectButton = 0;
	while (true) {
		system("cls");
		cout << BLUE1 << setw(20) << "" << "Удаление категории товаров" << WHITE << endl;
		cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
		cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
		cout << "Выберите категорию, которую вы хотите удалить" << endl;

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
			categories.removeAt(selectButton);
			//system("pause>nul");
		}
		else if (key == 27) {
			break;
		}
	}
}

void UserManage::editCategory() {
	cout << BLUE1 << setw(20) << "" << "Изменение категории товаров"<<WHITE << endl;
	cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
	cout << " " << PIRPLE << "(Администратор)" << WHITE << endl;
	if (!seeAllCategories()) return;
	cout <<BLUE1<< "Выберите категорию, которую вы хотите изменить"<<WHITE << endl;
	string category;
	getline(cin, category);

	for (int i = 0; i < categories.getSize(); i++) {
		if (categories[i] == category) {
			cout << "Введите новое название для " << category << endl;
			string newCategory;
			getline(cin, newCategory);
			categories[i] = newCategory;
			cout << GREEN << "Категория "<<PIRPLE<<category<<GREEN<<" успешно обновлена на "<<PIRPLE<<newCategory<< WHITE << endl;
			return;
		}
	}
	cout <<RED<< "Категория " << category << " не найдена" <<WHITE<< endl;
}

bool UserManage::seeAllCategories() {
	if (categories.getSize() == 0) {
		cout << "Пока список категорий пуск" << endl;
		return false;
	}
	for (int i = 0; i < categories.getSize(); i++) {
		cout <<setw(3)<<left<<i+1<<YELLOW<< categories[i]<<WHITE << endl;
	}
	return true;
}

void UserManage::readInfoCategories() {
	if (isFileProperlyOpen("categorydata.txt")) {
		ifstream fin("categorydata.txt");
		string category;
		while (fin >> category) {
			categories.push_back(category);
		}
		fin.close();
	}
	else cout << RED << "Не удалось открыть файл для записи" << WHITE << endl;
}

void UserManage::writeInfoCategories() {
	if (isFileProperlyOpen("categorydata.txt")) {
		ofstream fout("categorydata.txt");
		for (int i = 0; i < categories.getSize(); i++) {
			fout << categories[i] << endl;
		}
		fout.close();
	}
	else cout << RED << "Не удалось открыть файл для чтения" << WHITE << endl;
}
