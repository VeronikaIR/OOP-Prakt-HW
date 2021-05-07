#pragma once

#pragma warning(disable : 4996)
#include "Stormtrooper.h"
#include "global_functions.h"
#define _CRT_SECURE_NO_WARNINGS


Rank_S determinRank_S(char* _rank) {

	if (_rank == "Cadet")
	{
		return Rank_S::Cadet;
	}
	else if (_rank == "Private")
	{
		return Rank_S::Private;
	}
	else if (_rank == "LanceCorporal")
	{
		return Rank_S::LanceCorporal;
	}
	else if (_rank == "Corporal")
	{
		return Rank_S::Corporal;
	}
	else if (_rank == "StaffSergeant")
	{
		return Rank_S::StaffSergeant;
	}
	else
	{
		return Rank_S::MasterSergeant;
	}
}


Stormtrooper::Stormtrooper() {  // default constructor
	id = nullptr;
	this->stormtrooperRank = Rank_S::Cadet;
	type = nullptr;
}

Stormtrooper::Stormtrooper(const Stormtrooper& other) { //cpy
	this->id = new char[strlen(other.id) + 1];
	strcpy(this->id, other.id);
	this->stormtrooperRank = other.stormtrooperRank;
	this->type = new char[strlen(other.type) + 1];
	strcpy(this->type, other.type);
	this->planet = other.planet;
}
Stormtrooper::~Stormtrooper() {
	delete[]id;
	delete[]type;
}


Stormtrooper& Stormtrooper::operator=(const Stormtrooper& other) {
	if (this != &other) {
		delete[] id;
		this->id = new char[strlen(other.id) + 1];
		strcpy(this->id, other.id);
		this->stormtrooperRank = other.stormtrooperRank;
		this->planet = other.planet;
	}
	return *this;
}

Stormtrooper::Stormtrooper(char* _id, Rank_S _rank, char* _type, Planet _planet)
{
	this->id = new char[strlen(_id) + 1];
	strcpy(this->id, _id);
	this->stormtrooperRank = _rank;
	this->type = new char[strlen(_type) + 1];
	strcpy(this->type, _type);
	this->planet = _planet;
}

std::ostream& operator<<(std::ostream& out, const Stormtrooper& stormtrooper) {
	out << "Stormtrooper's ID: " << stormtrooper.get_id() << std::endl;
	out << "Stormtrooper's rank: ";
	switch (stormtrooper.stormtrooperRank)
	{
	case Rank_S::Cadet: out << "Cadet" << std::endl; break;
	case Rank_S::Private: out << "Private" << std::endl; break;
	case Rank_S::LanceCorporal: out << "LanceCorporal" << std::endl; break;
	case Rank_S::Corporal: out << "Corporal" << std::endl; break;
	case Rank_S::StaffSergeant: out << "StaffSergeant" << std::endl; break;
	case Rank_S::MasterSergeant: out << "MasterSergeant" << std::endl; break;
	}
	out << "Stormtrooper's type: " << stormtrooper.get_type() << std::endl;
	out << "Stormtrooper's planet: " << stormtrooper.get_planet() << std::endl;

	return out;

}

std::istream& operator>>(std::istream& in, Stormtrooper& stormtrooper) {
	std::cout << "Enter Trooper's ID: " << std::endl;
	char id[32];
	in >> id;
	stormtrooper.set_id(id);

	std::cout << "Enter Trooper's rank: " << std::endl;
	char trooperRank[32];
	in >> trooperRank;
	stormtrooper.set_rank(determinRank_S(trooperRank));

	std::cout << "Enter Trooper's type: " << std::endl;
	char trooperType[32];
	in >> trooperType;
	stormtrooper.set_type(trooperType);

	std::cout << "Enter Trooper's planet: " << std::endl;
	//char planetName[32];
	Planet planet;
	in >> planet;
	stormtrooper.set_planet(planet);
	//	planet.set_planetName(planetName);
	//stormtrooper.set_planet(planet);


	return in;
}

void Stormtrooper::print()
{
	std::cout << "ID :" << this->id << std::endl;
	std::cout << "Rank :"; // << (int)this->get_rank() << std::endl;
	switch (stormtrooperRank)
	{
	case Rank_S::Cadet: std::cout << "Cadet" << std::endl; break;
	case Rank_S::Private: std::cout << "Private" << std::endl; break;
	case Rank_S::LanceCorporal: std::cout << "LanceCorporal" << std::endl; break;
	case Rank_S::Corporal: std::cout << "Corporal" << std::endl; break;
	case Rank_S::StaffSergeant: std::cout << "StaffSergeant" << std::endl; break;
	case Rank_S::MasterSergeant: std::cout << "MasterSergeant" << std::endl; break;
	}
	std::cout << "Planet :" << this->planet << std::endl;

}


void Stormtrooper::ReadFromFile(const char* myFile, int& position) {
	std::ifstream input;
	input.open(myFile);
	char buff[64];
	int i = 0;
	input.seekg(position, std::ios::cur); // pointer

	while (input.getline(buff, 64, '\n'))
	{
		i++;
		position += CountSymbols(buff) + 2;

		if (i == 1)
		{
			this->set_id(buff);
		}
		else if (i == 2)
		{
			this->set_id(buff);
		}
		else if (i == 3)
		{
			this->set_rank(determinRank_S(buff));
		}
		else
		{
			this->set_type(buff);
		}
		if (i == 4)
		{
			break;
		}
	}

	position += 2;
	input.close();
}


void Stormtrooper::Write_file_Stormtrooper(const char* fileName) {
	std::ofstream myFile(fileName, std::ios::app);

	myFile << this->get_id() << std::endl;

	//rank ??
	/*
	switch (S.get_rank())
	{
	case Rank_S::Cadet:stormtrooperText << "Cadet" << std::endl;
	case Rank_S::Private:stormtrooperText << "Private" << std::endl;
	case Rank_S::LanceCorporal:stormtrooperText << "LanceCorporal" << std::endl;
	case Rank_S::Corporal:stormtrooperText << "Corporal" << std::endl;
	case Rank_S::StaffSergeant:stormtrooperText << "StaffSergeant" << std::endl;
	case Rank_S::MasterSergeant: stormtrooperText << "MasterSergeant" << std::endl; break;
	}
	*/
	myFile << this->get_type() << std::endl;
	myFile << this->get_planet().get_planetName();

	myFile.close();
}