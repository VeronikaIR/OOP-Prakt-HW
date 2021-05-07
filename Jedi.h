#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include "Planet.h"
#include "global_functions.h"
#define _CRT_SECURE_NO_WARNINGS


enum class Rank
{
	Youngling,
	Padawan,
	JediKnight,
	JediConsular,
	JediGuardian,
	JediSentinel,
	JediMaster
};

Rank determinRank(char* _rank);

class Jedi {
private:
	char* name;
	Rank jediRank;
	double midi_chlorian;
	Planet planet;
	char* spicies;
	char* militaryRank;

public:
	void set_name(const char* _name) {
		if (_name == nullptr) {
			return;
		}
		if (this->name != nullptr) {
			delete[] this->name;
		}

		this->name = new char[strlen(_name) + 1];

		strcpy(this->name, _name);
	}

	char* get_name() const {
		return this->name;
	}
	void set_jediRank(const Rank _rank) {
		this->jediRank = _rank;
	}

	Rank get_jediRank() const {
		return this->jediRank;
	}


	void set_midi_chlorian(const double _midi_chlorian) {
		this->midi_chlorian = _midi_chlorian;
	}

	double get_midi_chlorian() const {
		return this->midi_chlorian;
	}

	void set_planet(const Planet _planet) {
		//Planet curPlanet;
		//curPlanet.set_planetName(_planet);
		this->planet = _planet;
	}

	Planet get_planet() const {
		return this->planet;
	}

	void set_spicies(const char* _spicies) {
		if (_spicies == nullptr) {
			return;
		}
		if (this->spicies != nullptr) {
			delete[] this->spicies;
		}
		this->spicies = new char[strlen(_spicies) + 1];

		strcpy(this->spicies, _spicies);
	}

	char* get_spicies() const {
		return this->spicies;
	}

	void set_militaryRank(const char* _militaryRank) {
		delete[] this->militaryRank;

		this->militaryRank = new char[strlen(_militaryRank) + 1];

		strcpy(this->militaryRank, _militaryRank);
	}

	char* get_militaryRank()const {
		return this->militaryRank;
	}

	void print();
	Jedi();
	Jedi(const Jedi& other); //cpy constructor
	~Jedi();//destructor
	Jedi& operator= (const Jedi& other);
	Jedi(const char* _name,const Rank _rank, const double _midi_chlorian,const Planet& planet, const char* _spicies, const char* _militaryRank); // constructor with parameters
	friend std::ostream& operator<<(std::ostream& out, const Jedi& jedi);
	friend std::istream& operator>>(std::istream& in, Jedi& jedi);

	void ReadFromFile(const char* myFile, int& position);
	void Write_file_Jedi(const char* fileName);
};