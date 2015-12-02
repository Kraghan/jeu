#include "Entite.h"

Entite::Entite(std::string _nom, std::string _desc) {
	nom = _nom;
	description = _desc;
	pvRestant = PV_MAX;
}

std::string Entite::getNom() const{
	return nom;
}

std::string Entite::getDescription() const{
	return description;
}

int Entite::getPvRestant() const {
	return pvRestant;
}

void Entite::setPvRestant(int pv){
	pvRestant = pv;
}

bool Entite::isUnite() {
	return false;
}

bool Entite::isBatiment() {
	return false;
}

