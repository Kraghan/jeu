#include "Arme.h"

Arme::Arme() {
	Arme("Arme", 0, 0, 0, 0);
}

Arme::Arme(std::string _nom, int _degatInf, int _degatMotor, int _degatAerien, int _degatMarin) {
	nom = _nom;
	degInf = _degatInf;
	degMot = _degatMotor;
	degAer = _degatAerien;
	degMar = _degatMarin;
}

std::string Arme::getType() {
	return nom;
}

int Arme::getDegatInfanterie() {
	return degInf;
}

int Arme::getDegatMotorise() {
	return degMot;
}

int Arme::getDegatAerien() {
	return degAer;
}

int Arme::getDegatMarin() {
	return degMar;
}

