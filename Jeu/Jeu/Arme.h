#pragma once
#include <string>

class Arme {
private:
	std::string nom;
	int degInf, degMot, degAer, degMar;
public:
	Arme();
	Arme(std::string _nom, int _degatInf, int _degatMotor, int _degatAerien, int _degatMarin);
	std::string getType();
	int getDegatInfanterie();
	int getDegatMotorise();
	int getDegatAerien();
	int getDegatMarin();
};


static Arme const null("null", 0, 0, 0, 0);
static Arme const Harpon("Harpon", 8, 4, 6, 0);
static Arme const Balle("Balle", 8, 2, 2, 0);
static Arme const Roquette("Roquette", 4, 6, 6, 4);
static Arme const Canon("Canon", 2, 7, 0, 5);
static Arme const Missile("Missile", 0, 0, 8, 0);
static Arme const Torpille("Torpille", 0, 0, 0, 8);


