#pragma once

bool UserManage::isFileProperlyOpen(const string fileName) {
	fstream file(fileName, ios_base::in | ios_base::out);
	return file.is_open();
}

string UserManage::maskedInput() {
	bool isOpen = false;
	string input;
	char ch;
	while ((ch = _getch()) != 13) {
		if (ch == 8) {
			if (!input.empty()) {
				cout << "\b \b";
				input.pop_back();
			}
		}
		else if (ch == '`') {
			isOpen = !isOpen;
			if (isOpen) {
				for (int i = 0; i < input.size(); i++) {
					cout << "\b \b";
				}
				cout << input;
			}
			else {
				for (int i = 0; i < input.size(); i++) {
					cout << "\b";
				}
				cout << setfill('*') << setw(input.size()) << "" << setfill(' ');
			}
		}
		else {
			if (!input.empty() && !isOpen) {
				cout << "\b*";
			}
			input.push_back(ch);
			cout << ch;
		}
	}
	if (!isOpen) {
		cout << "\b*";
	}
	return input;
}

User* UserManage::currentUser = nullptr;

const string UserManage::generateSalt()
{
	srand((unsigned int)(time(nullptr)));
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string salt;
	for (int i = 0; i < saltLength; ++i) {
		salt += charset[rand() % charset.size()];
	}
	return salt;
}

const string UserManage::hashWithSalt(const string& input, const string& salt) {
	string saltedPassword = salt + input;

	uint64_t hash = 0;
	for (char character : saltedPassword) {
		hash = (hash * primeNumber) + character;
	}
	string hashString = to_string(hash);

	return hashString;
}

void UserManage::regist(int choose) {

	string username;
	string password;
	string repeated;

	cout <<BLUEf<< "Введите логин" <<WHITEf<< endl;
	cout << GREY << "Длина логина не менее 4 символов и не более 16"<<WHITE << endl;
	bool isAvailable = false;
	while (!isAvailable) {
		getline(cin, username);
		if (username.size() < 4 || username.size() > 16) {
			cout << RED << "Логин не соответствует требованиям длины, повторите ввод" <<WHITE<< endl;
			isAvailable = false;
			return;
		}
		else isAvailable = true;
		if (isAvailable) {
			for (int i = 0; i < listManage.getSize(); i++) {
				if (listManage[i].getLogin() == username) {
					cout << RED << "Данный логин занят другим пользователем, повторите ввод"<<WHITE << endl;
					system("pause>nul");
					isAvailable = false;
					break;
				}
			}
		}
	}
	cout <<BLUEf<< "Введите пароль"<<WHITEf << endl;
	cout << GREY << "Длина пароля от 4 до 16 символов" <<WHITE<< endl;
	cout << GREY << "Для лучшей защиты включайте в пароль буквы верхнего и нижнего региста, а также специальные символы"<<WHITE << endl;
	cout << GREY << "Нажмите ~, чтобы показать/скрыть пароль" <<WHITE<< endl;

	password = maskedInput();

	isAvailable = false;
	while (!isAvailable) {
		if (password.size() < 4 || password.size() > 16) {
			cout << RED << "Пароль не соответствует требованиям длины, повторите ввод"<<WHITE << endl;
			system("pause>nul");
			isAvailable = false;
			return;
		}
		else isAvailable = true;
	}
	isAvailable = false;
	while (!isAvailable) {
		cout <<endl<<BLUEf<<"Повторите пароль"<<WHITEf << endl;
		repeated = maskedInput();
		if (repeated == password) {
			cout << GREEN<<endl << "Вы успешно зарегистрированы" <<WHITE<< endl;
			isAvailable = true;
			break;
		}
		else cout << RED <<endl<< "Пароли не совпадают"<<WHITE << endl;
		return;
	}
	if (!isAvailable) {
		cout << RED << "Вы не зарегистрированы"<<WHITE << endl;
		return;
	}

	string salt = generateSalt();

	int var = listManage.getSize() == 0 ? 1 : 0;
	listManage.push_back(User(username, hashWithSalt(password, salt), salt, var, var));
	if (choose == 1) {
		currentUser = &listManage[listManage.getSize() - 1];
	}
	
}

void UserManage::logIn() {
	cout << setw(20) << "" << BLUE2 << "Вход в систему" << WHITE << endl;
	string username;
	string password;

	cout <<BLUEf<< "Введите ваш логин" <<WHITEf<< endl;
	getline(cin, username);

	for (int i = 0; i < listManage.getSize(); i++) {
		if (listManage[i].getLogin() == username ) {
			cout << BLUEf << "Введите ваш пароль" << WHITEf << endl;
			password = maskedInput();
			for (int i = 0; i < listManage.getSize(); i++) {
				if (listManage[i].getLogin() == username&&
					listManage[i].getHash()==hashWithSalt(password,listManage[i].getSalt())) {
					currentUser = &listManage[i];
					cout << GREEN << "\nВход успешно выполнен" << WHITE << endl;
					system("pause>nul");
					return;
				}
			}
			cout << RED << endl << "Пароль неверный" << WHITE << endl;
			system("pause>nul");
			return;
		}
	}
	cout << RED << "Не найдет пользователь с таким логином" <<WHITE<< endl;
	system("pause>nul");
	return;
}

void UserManage::changePassword() {
	cout << setw(20) << "" << BLUE2 << "Изменение пароля" << WHITE << endl;
	string password, newPassword, repeated;
	cout <<BLUEf<< "Введите свой старый пароль"<<WHITEf << endl;
	password=maskedInput();
	if (currentUser->getHash() == hashWithSalt(password, currentUser->getSalt())) {
		cout << endl<<BLUEf<<"Введите новый пароль" <<WHITEf<< endl;
		cout << GREY << "Длина пароля от 4 до 16 символов" << WHITE << endl;
		cout << GREY << "Для лучшей защиты включайте в пароль буквы верхнего и нижнего региста, а также специальные символы" << WHITE << endl;
		cout << GREY << "Нажмите ~, чтобы показать/скрыть пароль" << WHITE << endl;

		newPassword = maskedInput();

		bool isAvailable = false;
		while (!isAvailable) {
			if (newPassword.size() < 4 || newPassword.size() > 16) {
				cout << RED << "Новый пароль не соответствует требованиям длины, повторите ввод" << WHITE << endl;
				isAvailable = false;
				return;
			}
			else isAvailable = true;
		}
		isAvailable = false;
		while (!isAvailable) {
			cout << endl<<BLUEf << "Повторите пароль"<<WHITEf << endl;
			repeated = maskedInput();
			if (repeated == newPassword) {
				currentUser->setHash(hashWithSalt(newPassword, currentUser->getSalt()));
				cout << GREEN << endl << "Вы успешно изменили пароль" << WHITE << endl;
				isAvailable = true;
				break;
			}
			else cout << RED << endl << "Пароли не совпадают" << WHITE << endl;
			return;
		}
		if (!isAvailable) {
			cout << RED << "Пароль не был изменен" << WHITE << endl;
			return;
		}
	}
	else cout<<endl << RED << "Пароль не верный" << WHITE << endl;
}

void UserManage:: logOut() {
	if (currentUser == nullptr)
		cout << RED << "Вы уже вышли из аккаунта" << endl;
	else {
		currentUser = nullptr;
		cout << "Вы вышли из аккаунта" << endl;
	}
	system("pause>nul");
}

void UserManage::saveToFile() {
	if (isFileProperlyOpen("userdata.txt")) {
		ofstream fout("userdata.txt");
		for (int i = 0; i < listManage.getSize(); i++) {
			fout << listManage[i].getLogin() << " " << listManage[i].getHash() << " " << listManage[i].getSalt() << " " << listManage[i].getRole() << " " << listManage[i].getAccess() << endl;
		}
		fout.close();
	}
	else cout<<RED << "Не удолось открыть файл для записи" << WHITE << endl;
}

void UserManage::loadFromFile() {
	if (isFileProperlyOpen("userdata.txt")) {
		ifstream fin("userdata.txt");
		string login, salt, hash;
		int role, access;
		while (fin >> login >> hash >> salt >> role >> access) {
			listManage.push_back(User(login, hash, salt, role, access));
		}
		fin.close();
	}
	else cout<< RED << "Не удолось открыть файл для чтения" << WHITE << endl;
}