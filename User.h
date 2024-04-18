#pragma once

class User {
	string login;
	string saltedHashPassword;
	string salt;
	int role = 0;
	int access = 0;

	/*ShoppingCart shoppingCart;*/
public:
	User(string userLogin = string(), string saltedHashPassword = string(), string salt = string(), int role = int(), int access = int());

	int getRole() { return role; }
	void setRole(int role) { this->role = role; }

	int getAccess() { return access; }
	void setAccess(int access) { this->access = access; }

	string getLogin() { return login; }
	void setLogin(string login) { this->login = login; }

	string getSalt() { return salt; }
	void setSalt(string salt) { this->salt = salt; }

	string getHash() { return saltedHashPassword; }
	void setHash(string saltedHashPassword) { this->saltedHashPassword = saltedHashPassword; }

	/*ShoppingCart& getShoppingCart() {
		return shoppingCart;
	}*/
};

User::User(string userLogin, string saltedHashPassword, string salt, int role, int access)
{
	this->login = userLogin;
	this->saltedHashPassword = saltedHashPassword;
	this->salt = salt;
	this->role = role;
	this->access = access;
}