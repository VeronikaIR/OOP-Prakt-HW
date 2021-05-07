#include "Planet.h"
#include "global_functions.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


PlanetEnum determinPlanet_rank(char* curr_pl_rank) {

	if (strcmp(curr_pl_rank, "Chthonian")==0)
	{
		return PlanetEnum::Chthonian;
	}
	else if (strcmp(curr_pl_rank,"Carbon")==0)
	{
		return PlanetEnum::Carbon;
	}
	else if (strcmp(curr_pl_rank ,"Coreless")==0)
	{
		return PlanetEnum::Coreless;
	}
	else if (strcmp(curr_pl_rank ,"Desert")==0)
	{
		return PlanetEnum::Desert;
	}
	else
	{
		return PlanetEnum::Gas_dwarf;
	}
}

Planet::Planet(const Planet& other) {    //copy constructor
	this->set_planetName(other.planetName);

	this->set_planetSystem(other.planetSystem);

	this->set_repbublic(other.republic);

	this->planetRank = other.planetRank;

}

Planet& Planet::operator=(const Planet& other) {
	if (this != &other) {
		this->set_planetName(other.planetName);

		this->set_planetSystem(other.planetSystem);

		this->set_repbublic(other.republic);
		this->set_planet_rank(other.planetRank);

		//this->set_planet_rank(other.planetRank);
	}

	return *this;
}

Planet::Planet(const char* _name, const char* _planetSystem, const char* _republic, char* _planetRank) {
	this->set_planetName(_name);
	this->set_planetSystem(_planetSystem);
	this->set_repbublic(_republic);
	this->set_planet_rank(_planetRank);
}

/*
void Planet::print()///???
{
	std::cout << "Planet name: " << this->get_planetName() << std::endl;
	std::cout << "Plante system: " << this->get_planetSystem() << std::endl;
	std::cout << "Republic: " << this->get_repbublic() << std::endl;
}
*/

Planet::Planet() {
	planetName = nullptr;
	planetSystem = nullptr;
	republic = nullptr;
	planetRank = PlanetEnum::Chthonian;
}

Planet::~Planet() {
	delete[] planetName;
	delete[] planetSystem;
	delete[] republic;//HERE
}

std::ostream& operator<<(std::ostream& out, const Planet& planet) {  //in -> set
	out << "Name of planet: " << planet.get_planetName() << std::endl;
	out << "Planet system: " << planet.get_planetSystem() << std::endl;
	out << "Repblic: " << planet.get_repbublic() << std::endl;
	out << "Type of planet: ";
	switch (planet.planetRank) {
	case PlanetEnum::Chthonian: out << "Chthonian" << std::endl; break;
	case PlanetEnum::Carbon: out << "Carbon" << std::endl;  break;
	case PlanetEnum::Coreless:out << "Coreless" << std::endl; break;
	case PlanetEnum::Desert:out << "Desert" << std::endl; break;
	case PlanetEnum::Gas_dwarf:out << "Gas_dwarf" << std::endl; break;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
	std::cout << "Enter planet name: " << std::endl;
	char name[32];
	in >> name;
	planet.set_planetName(name);

	std::cout << "Enter planet system: " << std::endl;
	char planetSystem[32];
	in >> planetSystem;
	planet.set_planetSystem(planetSystem);

	std::cout << "Enter planet republic: " << std::endl;
	char planetRepublic[32];
	in >> planetRepublic;
	planet.set_repbublic(planetRepublic);

	std::cout << "Enter planet rank: " << std::endl;
	char planetRank[32];
	in >> planetRank;
	planet.set_planet_rank(planetRank);

	return in;
}

/*
void Planet::ReadFromFile(const char* myFile, int& position) {
	std::ifstream input;
	input.open(myFile);
	char buff[64];
	int i = 0;
	input.seekg(position, std::ios::cur);

	while (input.getline(buff, 64, '\n')) {

		if (i % 4 == 0 && i > 0) {
			break;
		}
		i++;

		//position += CountSymbols(buff) + 2;

		if (i == 1) {
			this->set_planetName(buff);
		}
		else if (i == 2) {
			this->set_planetSystem(buff);
		}
		else if (i == 3) {
			this->set_repbublic(buff);
		}
		else {
			this->set_planet_rank(determinPlanet_rank(buff));
		}
	}

	position += 2;

	input.close();
}
*/

/*
void Planet::ReadFromFile(const char* myFile, int& position) {
	std::ifstream input;
	input.open(myFile);
	char buff[64];
	int i = 0;
	input.seekg(position, std::ios::cur);

	while (input.getline(buff, 64, '\n')) {

		i++;
		position += CountSymbols(buff) + 2;

		if (i == 1) {
			this->set_planetName(buff);
		}
		if (i == 2) {
			this->set_planetSystem(buff);
		}
		if (i == 3) {
			this->set_repbublic(buff);
		}
		else {
			this->set_planet_rank(determinPlanet_rank(buff));
		}
		if (i == 4) {
			break;
		}
	}
	position += 2;
	input.close();

}

*/


void Planet::Write_file_Planet(const char* fileName) {
	std::ofstream myFile(fileName, std::ios::app);

	myFile << this->get_planetName() << std::endl;
	myFile << this->get_planetSystem() << std::endl;
	myFile << this->get_repbublic() << std::endl;

	//rank ??
	/*

	switch (P.get_planet_rank()) {
	case PlanetEnum::Chthonian: planetText << "Chthonian" << std::endl; break;
	case PlanetEnum::Carbon: planetText << "Carbon" << std::endl; break;
	case PlanetEnum::Coreless:planetText << "Coreless" << std::endl; break;
	case PlanetEnum::Desert:planetText << "Desert" << std::endl; break;
	case PlanetEnum::Gas_dwarf:planetText << "Gas_dwarf" << std::endl; break;
	}
	*/

	myFile.close();
}