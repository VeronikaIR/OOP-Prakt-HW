#pragma once
#include <iostream>
#include <functional>


template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class LList {
private:

	Node<T>* head;
	Node<T>* tail;
	//Node<T>* last;

public:
	LList();
	void createNode(T element);
	void insert_first(T element);
	void insert_back(T element);
	void insert_position(int pos, T element);
	void delete_first();
	void delete_last();
	void delete_position(int pos);
	void get_ith(T pos);
	int get_size();
	LList<T>& operator+=(T element);
	void append(Node<T>& obj);
	void removeAll(T element);
	void recursionReverse(LList<T>& list);
	const T operator[](T index)const;
	T& operator[](T index);
	void reverse();


	void Print();

	int count(T element);

	~LList();


};

template <typename T>
LList<T>::LList() {
	head = nullptr;
	tail = nullptr;
	//last = nullptr
}

template <typename T>
void LList<T>::createNode(T element) {

	Node<T>* temp = new Node<T>();
	temp->data = element;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		tail = temp;
		//last = temp;
		temp = NULL;
	}
	else {
		temp->next = temp;
		tail = temp;
	}
}

template <typename T>
void LList<T>::insert_first(T element) {

	Node<T>* newFirst = new Node<T>();
	newFirst->data = element;
	newFirst->next = head;
	head = newFirst;

}


template <typename T>
void LList<T>::insert_back(T element) {

	Node<T>* newLast = new Node<T>();
	newLast->data = element;
	newLast->next = nullptr;

	if (head == nullptr) {
		head = newLast;
		tail = newLast;
		//last = newLast;

		newLast = nullptr;
	}
	else {
		tail->next = newLast;
		tail = newLast;
	}

}


template <typename T>
void LList<T>::insert_position(int pos, T element) {

	Node<T>* newNode = new Node<T>();
	newNode->data = element;

	Node<T>* prev = new Node<T>();
	Node<T>* curr = new Node<T>();
	curr = head;

	for (int i = 1; i < pos; ++i) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = newNode;
	newNode->next = curr;

}

template <typename T>
void LList<T>::delete_first() {

	Node<T>* temp = new Node<T>();
	temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void LList<T>::delete_last() {

	Node<T>* curr = new Node<T>();
	Node<T>* prev = new Node<T>();

	curr = head;

	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}

	tail = prev;
	prev->next = nullptr;
	delete curr;
}

template <typename T>
void LList<T>::delete_position(int pos) {
	Node<T>* curr = new Node();
	Node<T>* prev = new Node();

	curr = head;

	for (int i = 1; i < pos; ++i) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
}

template <typename T>
void LList<T>::Print() {
	Node<T>* temp = new Node<T>();
	temp = head;

	while (temp != nullptr) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}

}


template <typename T>
int LList<T>::count(T element) {  //working !!

	int counter = 0;

	Node<T>* curr;
	curr = head;

	while (curr != nullptr) {
		if (curr->data == element) {
			counter++;
		}
		curr = curr->next;
	}
	return counter;
}


template <typename T>
void LList<T>::get_ith(T pos) {

	Node<T>* curr = new Node<T>();
	curr = head;

	while (pos != 0) {
		curr = curr->next;
		pos--;
	}
	std::cout << curr->data << std::endl;

}


template <typename T>
int LList<T>::get_size() {

	Node<T>* curr = new Node<T>();
	curr = head;
	int size = 0;

	while (curr != nullptr)
	{
		size++;
		curr = curr->next;
	}
	return size;
}

template <typename T>
LList<T>& LList<T>::operator+=(T element) {

	Node<T>* newNode = new Node<T>();
	newNode->data = element;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	return  *this;
}

template<typename T>
void LList<T>::append(Node<T>& obj) {





}


template <typename T>
void LList<T>::removeAll(T element) {

	Node<T>* curr = new Node<T>();
	//Node<T>* prev = new Node<T>();
	curr = head;

	while (curr != nullptr) {

		Node<T>* temp = new Node<T>();
		temp = curr ->next;
		delete curr;
		curr = temp;
	}

}


template <typename T>
const T LList<T>::operator[](T index)const {

	Node<T>* curr = new Node<T>();
	curr = head;

	while (index != 0) {
		curr = curr->next;
		index--;
	}
	//std::cout << curr->data << std::end;

	return curr->data;

}

template <typename T>
T& LList<T>::operator[](T index) {

	Node<T>* curr = new Node<T>();
	curr = head;

	while (index != 0) {
		curr = curr->next;
		index--;
	}
	//std::cout << curr->data << std::endl;

	return curr->data;
}

template <typename T>
void LList<T>::reverse() {

	Node<T>* curr = new Node<T>();
	curr = head;
	Node<T>* prev = new Node<T>();
	prev = nullptr;
	Node<T>* next = new Node<T>();
	next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

template <typename T>
void LList<T>::recursionReverse(LList<T>& list) {

	int size = list.get_size();
	int index = 1;

	if (size == 0) {return;}

	else {
		list.insert_first(list.get_ith(index)->data);
		index++;
		list.delete_position(index);
		size--;
		recursionReverse(list);
	}

}


template <typename T>
LList<T>::~LList() {

	Node<T>* curr = head;
	while (curr != nullptr) {
		Node<T>* temp = curr->next;
		delete curr;
		curr = temp;
	}
}

