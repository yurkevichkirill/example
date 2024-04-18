#include "UserManage.h"
#pragma once
//ACCOUNTS
void UserManage::seeAllUsers() {
	cout << setw(20) << "" << PIRPLE << "������ �������������" << WHITE << endl;
	cout << YELLOW<<setw(2)<<"�" << setw(19) << "�����" << setw(6) << "����" << setw(9) << "������" << WHITE << endl;
	for (int i = 0; i < listManage.getSize(); i++) {
		cout<<setw(2) << i + 1 << " " <<setw(18)<< listManage[i].getLogin() << setw(6) << listManage[i].getRole() << setw(9) << listManage[i].getAccess() << endl;
	}
}

void UserManage::addUser(int role) {
	cout << setw(20) << "" << PIRPLE << "���������� ������������" << WHITE << endl;
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
	cout << setw(20) << "" << PIRPLE << "�������������� ������������" << WHITE << endl;
	seeAllUsers();

	int num;
	cout << BLUEf << "������� ����� ������������, �������� �� ������ �������������" <<WHITEf<< endl;
	string loginEdit;
	cin >> loginEdit;

	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginEdit) {
			if (listManage[i].getAccess() == 0) {
				cout << "����� ������������ ������������ ������ ������� enter" << endl;
				char key = _getch();
				if (key == 13) {
					listManage[i].setAccess(1);
					cout << GREEN << "������ ������������ �������" << WHITE << endl;
				}
			}
			else {
				cout << "����� ������������� ������������ ������� enter" << endl;
				char key = _getch();
				if (key == 13) {
					listManage[i].setAccess(0);
					listManage[i].setRole(0);
					cout << RED << "������������ ������������" << WHITE << endl;
				}
			}
			cout << YELLOW << "���������� ������������ " << listManage[i].getLogin() <<listManage[i].getRole() << " " << listManage[i].getAccess() << WHITE << endl;
			return;
		}
	}
	cout << RED << endl << "�� ���������� ������������ � ����� �������" << WHITE << endl;
}

void UserManage::deleteUser() {
	cout << setw(20) << "" << PIRPLE << "�������� ������������" << WHITE << endl;
	seeAllUsers();
	cout <<BLUEf<< "������� ����� ������������, �������� ������ �������"<<WHITEf << endl;
	string loginDel;
	cin >> loginDel;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginDel) {
			cout << "�� �������, ��� ������ ������� ������������ " << PIRPLE << loginDel << WHITE<<"?"  << endl;
			cout << GREY << "������� \"��\", ����� ����������" << WHITE << endl;
			string confirm;
			cin >> confirm;
			if (confirm == "��") {
				if (UserManage::currentUser->getLogin() != loginDel) {
					listManage.removeAt(i);
					cout << "������������ " << loginDel << " ������� ������" << endl;
					return;
				}
				else {
					cout << RED << "�� �� ������ ������� ����" << WHITE << endl;
					return;
				}
			}
		}
	}
	cout << RED << "�� ���������� ������������ � ����� �������" << WHITE << endl;
}

void UserManage::giveRights() {
	cout << setw(20) << "" << PIRPLE << "�������� ���� ��������������" << WHITE << endl;
	cout << BLUEf << "������� ����� ������������, �������� ������ ������������ ����� ��������������" << WHITEf << endl;
	string loginAdmin;
	cin >> loginAdmin;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginAdmin) {
			cout << "�� �������, ��� ������ ������������ ����� ������������ " << PIRPLE << loginAdmin << WHITE << "?" << endl;
			cout << GREY << "������� \"��\", ����� ����������" << WHITE << endl;
			string confirm;
			cin >> confirm;
			if (confirm == "��") {
				if (UserManage::currentUser->getLogin() != loginAdmin) {
					listManage[i].setRole(1);
					cout <<YELLOW<< "������������ " <<PIRPLE<< loginAdmin <<YELLOW<< " ������� ����� ��������������"<<WHITE << endl;
					return;
				}
			}
		}
	}
	cout << RED << "�� ���������� ������������ � ����� �������" << WHITE << endl;
}

void UserManage::confirmAll() {
	cout << setw(20) << "" << PIRPLE << "������������� �������������" << WHITE << endl;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		listManage[i].setAccess(1);
	}
	cout << GREEN << "��� ������������ �������� ������" << WHITE << endl;
	seeAllUsers();
}

void UserManage::confirmOne() {
	cout << setw(20) << "" << PIRPLE << "������������� ������������" << WHITE << endl;

	cout << BLUEf << "������� ����� ������������, �������� ������ �����������" << WHITEf << endl;
	string loginAdmin;
	cin >> loginAdmin;
	for (int i = 0; i < UserManage::listManage.getSize(); i++) {
		if (listManage[i].getLogin() == loginAdmin) {			
				if (UserManage::currentUser->getLogin() != loginAdmin) {
					listManage[i].setAccess(1);
					cout <<YELLOW<< "������������ " <<PIRPLE<< loginAdmin << YELLOW<<" �����������"<<WHITE << endl;
					return;
				}
		}
	}
	cout << RED << "�� ���������� ������������ � ����� �������" << WHITE << endl;
}
//STORE
void UserManage::addCategory() {
	cout << BLUE1 << setw(20) << "" << "���������� ��������� �������" <<WHITE<< endl;
	cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
	cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
	seeAllCategories();
	cout << "������� �������� ���������, ������� �� ������ ��������" << endl;
	string category;
	getline(cin, category);

	for (int i = 0; i < categories.getSize(); i++) {
		if (categories[i] == category) {
			cout << "������ ��������� ��� ����������" << endl;
			return;
		}
	}
	categories.push_back(category);
	cout <<GREEN<< "��������� " <<PIRPLE<<category<<GREEN<< " ������� ���������"<<WHITE<<endl;
}

void UserManage::deleteCategory() {
	if (!seeAllCategories()) return;
	int selectButton = 0;
	while (true) {
		system("cls");
		cout << BLUE1 << setw(20) << "" << "�������� ��������� �������" << WHITE << endl;
		cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
		cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
		cout << "�������� ���������, ������� �� ������ �������" << endl;

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
			categories.removeAt(selectButton);
			//system("pause>nul");
		}
		else if (key == 27) {
			break;
		}
	}
}

void UserManage::editCategory() {
	cout << BLUE1 << setw(20) << "" << "��������� ��������� �������"<<WHITE << endl;
	cout << BLUE2 << setw(20) << "" << UserManage::currentUser->getLogin();
	cout << " " << PIRPLE << "(�������������)" << WHITE << endl;
	if (!seeAllCategories()) return;
	cout <<BLUE1<< "�������� ���������, ������� �� ������ ��������"<<WHITE << endl;
	string category;
	getline(cin, category);

	for (int i = 0; i < categories.getSize(); i++) {
		if (categories[i] == category) {
			cout << "������� ����� �������� ��� " << category << endl;
			string newCategory;
			getline(cin, newCategory);
			categories[i] = newCategory;
			cout << GREEN << "��������� "<<PIRPLE<<category<<GREEN<<" ������� ��������� �� "<<PIRPLE<<newCategory<< WHITE << endl;
			return;
		}
	}
	cout <<RED<< "��������� " << category << " �� �������" <<WHITE<< endl;
}

bool UserManage::seeAllCategories() {
	if (categories.getSize() == 0) {
		cout << "���� ������ ��������� ����" << endl;
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
	else cout << RED << "�� ������� ������� ���� ��� ������" << WHITE << endl;
}

void UserManage::writeInfoCategories() {
	if (isFileProperlyOpen("categorydata.txt")) {
		ofstream fout("categorydata.txt");
		for (int i = 0; i < categories.getSize(); i++) {
			fout << categories[i] << endl;
		}
		fout.close();
	}
	else cout << RED << "�� ������� ������� ���� ��� ������" << WHITE << endl;
}
