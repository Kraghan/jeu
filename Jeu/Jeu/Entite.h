#pragma once
#include <string>

class Entite
{
private : 
	std::string nom, description;
	int const PV_MAX = 10;
	int pvRestant;

public : 
	Entite(std::string _nom,std::string _desc);

	std::string getNom() const;
	std::string getDescription() const;
	int getPvRestant() const;
	void setPvRestant(int pv);
	void virtual prendDegat(int degat) = 0;
	void virtual soin() = 0;
	bool virtual estDetruit() = 0;

	bool isUnite();
	bool isBatiment();
};