#pragma once
#include <iostream>
#include "myVector.h"
#include <functional>


template<typename T>
void map(myVector<T>& vector, std::function<T(T)>func) {

	for (int i = 0; i < vector.get_curSize(); ++i) {
		vector[i] = func(vector[i]);
	}

}


template <typename T>
myVector<T> filter(myVector<T>& vector, std::function<T(T)> func) {

	myVector<T> newVect;

	for (int i = 0; i < vector.get_curSize(); ++i) {

		if (func(vector[i])) {
			newVect.addElement(vector[i]);
		}

	}
	return newVect;
}


inline int CountSymbols(char* text) {
	int counter = 0;

	while (text[counter] != '\0') {
		counter++;
	}
	return counter;
}

/*

bool strCmp(const char* text1, const  char* text2) {
	int i = 0;

	while (text1[i] != '\0') {
		if (text1[i] != text2[i]) {
			return false;
		}
		i++;
	}
	return true;
}

*/

/*
bool strCmp(const char* text1, const char* text2) {
	int i = 0;

	while (text1[i] != '\0') {
		if (text1[i] != text2[i]) {
			return false;
		}
		i++;
	}
	return true;
}

*/

inline int ParseToInt(char* text) {
	int number = 0;
	int n = 10;

	for (int i = 0; text[i] != '\0'; i++) {
		number = number * 10 + text[i] - 48;
	}
	return number;
}
