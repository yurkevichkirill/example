#pragma once
#pragma once
//
//class ShoppingCart {
//private:
//    ListUser<Item> cart; // Вектор для хранения товаров в корзине
//
//public:
//    ShoppingCart() {}
//    // Метод для добавления товара в корзину
//    void addItem(const Item& item) {
//        cart.push_back(item);
//    }
//
//    // Метод для удаления товара из корзины по индексу
//    void removeItem(int index) {
//        if (index >= 0 && index < cart.getSize()) {
//            cart.removeAt(index);
//        }
//    }
//
//    // Метод для получения общего количества товаров в корзине
//    int getItemCount() {
//        return cart.getSize();
//    }
//
//    // Метод для получения товара из корзины по индексу
//    Item getItem(int index) {
//        if (index >= 0 && index < cart.getSize()) {
//            return cart[index];
//        }
//        // Возвращаем пустой товар, если индекс некорректный
//        return Item();
//    }
//
//    // Метод для очистки корзины
//    void clearCart() {
//        cart.clear();
//    }
//};
