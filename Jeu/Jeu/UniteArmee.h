#pragma once
#include "Unite.h"
#include "Arme.h"
#include <string>

class UniteArmee : Unite {

private:
	int munMax, munRestante, rangeMax, rangeMin;
	Arme *armePrincipale, *armeSecondaire;

public :
	UniteArmee(std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision,
		int _munMax, int _rangeMax, int _rangeMin, Arme principale, Arme secondaire);
	int UniteArmee::getRangeMin()const;
	int UniteArmee::getRangeMax()const;
	int UniteArmee::getStockMunActuel()const;
	int UniteArmee::getStockMaxMun()const;
	
	void attaque(Entite *ennemi);
	void attaqueUnite(Unite *ennemi);
	void attaqueBatiment();
};