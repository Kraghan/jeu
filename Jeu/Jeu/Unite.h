#pragma once
#include "Arme.h"
#include "Entite.h"
#include <string>
#include "UniteArmeeAerienne.h"
#include "UniteArmeeMotorise.h"
#include "UniteArmeeInfanterie.h"
#include "UniteArmeeMaritime.h"

class Unite : public Entite{

private : 
	int stockRessourceActuel, deplacementRestant, stockResssourceMax, deplacementMax, champVision, resistance,
		stockMunitionActuel, stockMunitionMax, rangeMin, rangeMax;

public : 
	Unite(std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision); 

	int getStockMaxRess() const;
	int getDeplacementMax()const;
	int getChampVision()const;
	int getResistance() const;
	void setResistance(int _res);

	int getStockRessActuel()const;
	int getDeplacementRestant()const;
	
	bool peutSeDeplacer()const;

	void update();
	void render();

	void reaprovisionnement();
	void prendDegat(int degat);
	void seDeplace(int nbCaseDeplace);
	void soin();
	bool estDetruit();

	bool isUnite();
	bool isAerienne();
	bool isMotorise();
	bool isInfanterie();
	bool isMaritime();

	//static UniteArmeeInfanterie soldat("Soldat", "Unite d'infanterie basique", 50, 5, 4, 12, 2, 1, Arme::Balle, NULL);
};
