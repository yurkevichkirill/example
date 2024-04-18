#pragma once

template<typename T>
class ListUser {
public:
	ListUser();
	~ListUser();
	void push_back(T data);
	void removeAt(int);
	void clear();
	int getSize() { return Size; }
	T& operator[](const int index);
private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};

template<typename T>
ListUser<T>::ListUser() {
	Size = 0;
	head = nullptr;

}

template<typename T>
inline ListUser<T>::~ListUser()
{
}

template<typename T>
inline void ListUser<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void ListUser<T>::removeAt(int index) {
	if (index < 0 || index >= Size) {
		// Индекс находится за пределами списка
		return;
	}
	if (index == 0) {
		// Если удаляемый элемент находится в начале списка
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
	}
	else {
		// Ищем элемент, предшествующий удаляемому
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}
		// Сохраняем указатель на удаляемый элемент
		Node<T>* temp = previous->pNext;
		// Перестраиваем связи в списке
		previous->pNext = temp->pNext;
		// Удаляем элемент
		delete temp;
	}
	Size--;
}

template<typename T>
void ListUser<T>::clear() {
	for (int i = 0; i < getSize(); i++) {
		removeAt(i);
	}
}


template<typename T>
inline T& ListUser<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


