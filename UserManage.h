#pragma once

class UserManage {
	ListUser<User> listManage;
	ListUser<Item>itemList;
	ListUser<string>categories;
public:
	static User* currentUser;
	//AUTHORIZATION
	void regist(int choose);
	void logIn();
	void changePassword();
	void loadFromFile();
	void saveToFile();
	void logOut();
	static bool isFileProperlyOpen(const string fileName);
	string maskedInput();
	const string generateSalt();
	const string hashWithSalt(const string&, const string&);
	//ADMIN
	void seeAllUsers();
	void addUser(int);
	void editUser();
	void deleteUser();
	void giveRights();
	void confirmAll();
	void confirmOne();
	//DATAWORK
	void seeCatalog();
	void addItem();
	/*void goToCart() {}
	void checkMyItems() {}*/
	void input(string text, int size);
	void readInfo();
	void writeInfo();
	void fillCatalog();
	/*void addItemToCart(const Item& item);*/
	void sorting();
	void sortByPriceUp();
	void sortByPriceDown();
	void sortByTitle();
	void filtering();
	void filterByTown(string city);
	void filterByStock();
	void filterByPriceMin(int price);
	void filterByPriceMax(int price);
	void filterByCategory(string category);

	//ADM_DATA_WORK
	void addCategory();
	void deleteCategory();
	void editCategory();
	bool seeAllCategories();
	void readInfoCategories();
	void writeInfoCategories();
};




