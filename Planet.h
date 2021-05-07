#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include <fstream>
#include "global_functions.h"
#define _CRT_SECURE_NO_WARNINGS


enum class PlanetEnum
{
	Chthonian,
	Carbon,
	Coreless,
	Desert,
	Gas_dwarf
};

PlanetEnum determinPlanet_rank(char* curr_planet_rank);

class Planet {
private:
	char* planetName;
	char* planetSystem;
	char* republic;
	PlanetEnum planetRank;

public:
	void set_planetName(const char* _name) {
		if (_name == nullptr) {
			return;
	}
		//if (this->planetName != nullptr) {
		//	delete[] planetName;
		//}

		this->planetName = new char[strlen(_name) + 1];

		strcpy(this->planetName, _name);
	}

	char* get_planetName() const {
		return this->planetName;
	}

	void set_planetSystem(const char* _planetSystem) {
		if (_planetSystem == nullptr) {
			return;
		}
		//if (this->planetSystem != nullptr) {
		//	delete[] this->planetSystem;
		//}

		this->planetSystem = new char[strlen(_planetSystem) + 1];

		strcpy(this->planetSystem, _planetSystem);
	}

	char* get_planetSystem()const {
		return this->planetSystem;
	}

	void set_repbublic(const char* _repbublic) {
		if (_repbublic == nullptr) {
			return;
		}
		//if (this->republic != nullptr) {
		//	delete[] this->republic;
		//}

		this->republic = new char[strlen(_repbublic) + 1];

		strcpy(this->republic, _repbublic);
	}

	char* get_repbublic()const {
		return this->republic;
	}

	void set_planet_rank(char* _planetRank) {
		this->planetRank = determinPlanet_rank( _planetRank);
	}

	void set_planet_rank(const PlanetEnum _planetRank) {
		this->planetRank = planetRank;
	}

	PlanetEnum get_planet_rank() const {
		return this->planetRank;
	}

	//void print();
	Planet();                                                        //default constructor
	Planet(const Planet& other);                                     //constructor with parameter
	~Planet();                                                       //destructor
	Planet& operator=(const Planet& other);                          //overload operator =
	Planet(const char* _name, const char* _planetSystem, const char* _repulic, char* _planetRank);
	friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
	friend std::istream& operator>>(std::istream& in, Planet& planet);


	//void ReadFromFile(const char* myFile, int& position);
	void Write_file_Planet(const char* fileName); //textFile
};

template <class T>

void Print(const T& object)
{
	std::cout << object;
}