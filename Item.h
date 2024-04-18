#pragma once
class Item {
	string category;
	string brend;
	string count;
	string price;
	bool isStock;
	string city;
public:
	Item():category(""), brend(""),  count(""), price(""), isStock(false), city("") {}
    Item(string title, string description, string count, string price,
        bool isStock, string city) :
        category(title), brend(description), count(count), price(price),isStock(isStock), city(city) {}

    void setCategory(const std::string& t) { category = t; }
    void setBrend(const std::string& d) { brend = d; }
    void setCount(int c) { count = c; }
    void setPrice(float p) { price = p; }
    void setStock(bool s) { isStock = s; }
    void setCity(const std::string& c) { city = c; }

    std::string getCategory() const { return category; }
    std::string getBrend() const { return brend; }
    string getCount() const { return count; }
    string getPrice() const { return price; }
    bool getStock() const { return isStock; }
    std::string getCity() const { return city; }

    friend ostream& operator<<(std::ostream& os, const Item& obj);
};