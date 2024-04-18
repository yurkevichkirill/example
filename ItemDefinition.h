#pragma once
std::ostream& operator<<(std::ostream& os, const Item& obj) {
    os << setw(20) << left << obj.category << setw(20) << obj.brend << setw(12) <<
        obj.count << setw(11) << obj.price << setw(10) << (obj.isStock ? "Да" : "Нет") << setw(20) << obj.city;
    return os;
}
