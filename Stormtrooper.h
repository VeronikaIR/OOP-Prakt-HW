#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstring>
#include "Planet.h"
#include "global_functions.h"
#define _CRT_SECURE_NO_WARNINGS

enum class Rank_S
{
	Cadet,
	Private,
	LanceCorporal,
	Corporal,
	StaffSergeant,
	MasterSergeant
};

Rank_S determinRank_S(char* _rank);


class Stormtrooper {
private:
	char* id;
	Rank_S stormtrooperRank;
	char* type;
	Planet planet;
public:

	void set_id(const char* _id) {
		delete[] id;

		this->id = new char[strlen(_id) + 1];

		strcpy(this->id, _id);
	}
	char* get_id() const {
		return this->id;
	}

	void set_rank(const Rank_S _rank) {
		this->stormtrooperRank = _rank;
	}

	Rank_S get_rank() const {
		return this->stormtrooperRank;
	}

	void set_type(const char* _type) {
		delete[] type;

		this->type = new char[strlen(_type) + 1];

		strcpy(this->type, _type);
	}
	char* get_type() const {
		return this->type;
	}
	void set_planet(const Planet& _planet) {
		this->planet = _planet;
	}

	Planet get_planet() const {
		return this->planet;
	}

	Stormtrooper();  // default constructor
	Stormtrooper(const Stormtrooper& other); //copy constructor
	~Stormtrooper(); //destrctructor
	Stormtrooper& operator=(const Stormtrooper& other);
	Stormtrooper(char* _id, Rank_S _rank, char* _type, Planet _planet);
	friend std::ostream& operator<<(std::ostream& out, const Stormtrooper& stormtrooper);
	friend std::istream& operator>>(std::istream& in, Stormtrooper& stormtrooper);

	void ReadFromFile(const char* myFile, int& position);
	void Write_file_Stormtrooper(const char* fileName);

	void print();


};
