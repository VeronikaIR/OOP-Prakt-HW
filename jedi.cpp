#include "Jedi.h"
#include "Planet.h"
#include "global_functions.h"
#define _CRT_SECURE_NO_WARNINGS


Rank determinRank(char* _rank) {

	if (strcmp(_rank, "Youngling")==0)
	{
		return Rank::Youngling;
	}
	else if (strcmp(_rank, "Padawan")==0)
	{
		return Rank::Padawan;
	}
	else if (strcmp(_rank, "JediKnight")==0)
	{
		return Rank::JediKnight;
	}
	else if (strcmp(_rank,"JediConsular")==0)
	{
		return Rank::JediConsular;
	}
	else if (strcmp(_rank ,"JediGuardian")==0)
	{
		return Rank::JediGuardian;
	}
	else if (strcmp(_rank ,"JediSentinel")==0)
	{
		return Rank::JediSentinel;
	}
	else if (strcmp(_rank,"JediMaster")==0)
	{
		return Rank::JediMaster;
	}
	//return Rank::Youngling;
}

Jedi::Jedi(const Jedi& other) {  //copy constructor
	
	this->set_name(other.name);

	this->jediRank = other.jediRank;

	this->midi_chlorian = other.midi_chlorian;

	this->planet = other.planet;

	this->set_spicies(other.spicies);

	this->militaryRank = other.militaryRank;
}

Jedi ::~Jedi() {
	delete[] name;
	delete[] spicies;
	delete[] militaryRank;
}

Jedi& Jedi:: operator= (const Jedi& other) {
	if (this != &other) {

		this->set_name(other.name);

		this->set_jediRank(other.jediRank);

		this->set_midi_chlorian(other.midi_chlorian);

		this->set_planet(other.planet);

		this->set_spicies(other.spicies);

		this->set_militaryRank(other.militaryRank);
	}
	return *this;
}

Jedi::Jedi(const char* _name,const Rank _rank, const double _midi_chlorian, const Planet& _planet, const char* _spicies, const char* _militaryRank) {
	this->set_name(_name);
	this->set_jediRank(_rank);
	this->set_midi_chlorian(_midi_chlorian);
	this->set_planet(_planet);
	this->set_spicies(_spicies);
	this->set_militaryRank(_militaryRank);
}


void Jedi::print() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Rank: ";  //(int)this->rank << std::endl; //TODO: create function
	switch (jediRank) {
	case Rank::Youngling: std::cout << "Youngling" << std::endl; break;
	case Rank::Padawan: std::cout << "Padawan" << std::endl; break;
	case Rank::JediKnight: std::cout << "JediKnight" << std::endl; break;
	case Rank::JediConsular: std::cout << "JediConsular" << std::endl; break;
	case Rank::JediGuardian: std::cout << "JediGuardian" << std::endl; break;
	case Rank::JediSentinel: std::cout << "JediSentinel" << std::endl; break;
	case Rank::JediMaster: std::cout << "JediMaster" << std::endl; break;

	}
	std::cout << "Planet information: " << this->planet << std::endl;
	std::cout << "Midi chlorian: " << this->midi_chlorian << std::endl;
	std::cout << "Spicies: " << this->spicies << std::endl;
	std::cout << "MilitaryRank: " << this->militaryRank << std::endl;

}



Jedi::Jedi() {  // default constructor
	name = nullptr;
	this->jediRank = Rank::Youngling;
	midi_chlorian = 0.0;
	spicies = nullptr;
	militaryRank = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Jedi& jedi) {
	out << "Jedi's name: " << jedi.get_name() << std::endl;
	out << "Jedi's rank: ";
	switch (jedi.jediRank)
	{
	case Rank::Youngling:out << "Youngling" << std::endl; break;
	case Rank::Padawan:out << "Padawan" << std::endl; break;
	case Rank::JediSentinel:out << "JediSentinel" << std::endl; break;
	case Rank::JediMaster: out << "JediMaster" << std::endl; break;
	case Rank::JediKnight: out << "JediKinght" << std::endl; break;
	case Rank::JediGuardian: out << "JediGuardian" << std::endl; break;
	case Rank::JediConsular:out << "JediConsular" << std::endl; break;
	}
	out << "Jedi's midi chlorian: " << jedi.get_midi_chlorian() << std::endl;
	out << "Jedi's planet: " << jedi.get_planet().get_planetName() << std::endl;
	out << "Jedi's spicies: " << jedi.get_spicies() << std::endl;
	out << "Jedi's military rank: " << jedi.get_militaryRank() << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Jedi& jedi) {
	std::cout << "Enter Jedi's name: " << std::endl;
	char jediName[32];
	in >> jediName;
	jedi.set_name(jediName);

	std::cout << "Enter Jedi's rank: " << std::endl;
	char jediRank[32];
	in >> jediRank;
	jedi.set_jediRank(determinRank(jediRank));

	std::cout << "Enter Jedi's midi chlorian: " << std::endl;
	double midiClorian;
	in >> midiClorian;
	jedi.set_midi_chlorian(midiClorian);

	std::cout << "Enter Jedi's planet:" << std::endl;
	Planet planet;
	in >> planet;
	jedi.set_planet(planet);

	std::cout << "Enter Jedi's spicies: " << std::endl;
	char jediSpicies[32];
	in >> jediSpicies;
	jedi.set_spicies(jediSpicies);

	std::cout << "Enter Jedi's militaryRank: " << std::endl;
	char militaryRank[32];
	in >> militaryRank;
	jedi.set_militaryRank(militaryRank);

	return in;
}

void Jedi::ReadFromFile(const char* myFile, int& position) {
	std::ifstream input;
	input.open(myFile);
	char buff[64];
	int i = 0;
	input.seekg(position, std::ios::cur);

	while (input.getline(buff, 64, '\n')) {
		i++;
		position += CountSymbols(buff) + 2;

		if (i == 1) {
			this->set_name(buff);
		}

		else if (i == 2) {
			this->set_jediRank(determinRank(buff));
		}
		else if (i == 3) {
			this->set_midi_chlorian(atof(buff));
		}
		else if (i == 4) {
			this->get_planet().set_planetName(buff);
		}
		else if (i == 5) {
			this->set_spicies(buff);

		}
		else {
			this->set_militaryRank(buff);
		}
		if (i == 6) {
			break;
		}
	}
	position += 2;
	input.close();
}

void Jedi::Write_file_Jedi(const char* fileName) {
	std::ofstream myFile(fileName, std::ios::app);

	myFile << this->get_name() << std::endl;
	/*
	myFile << this->get_jediRank() << std::endl;
	switch (myFile.get_jediRank())
	{
	case Rank::Youngling: myFile << "Youngling" << std::endl; break;
	case Rank::Padawan: jediText << "Padawan" << std::endl; break;
	case Rank::JediKnight: jediText << "JediKnight" << std::endl; break;
	case Rank::JediConsular: jediText << "JediConsular" << std::endl; break;
	case Rank::JediGuardian: jediText << "JediGuardian" << std::endl; break;
	case Rank::JediSentinel: jediText << "JediSentinel" << std::endl; break;
	case Rank::JediMaster: jediText << "JediMaster" << std::endl; break;
	}
	*/

	myFile << this->get_midi_chlorian() << std::endl;
	myFile << this->get_planet().get_planetName() << std::endl;
	myFile << this->get_spicies() << std::endl;
	myFile << this->get_midi_chlorian() << std::endl;

	myFile.close();
}