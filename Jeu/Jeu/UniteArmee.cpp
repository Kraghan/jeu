#include "UniteArmee.h"

UniteArmee::UniteArmee(std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision,
	int _munMax, int _rangeMax, int _rangeMin,Arme principale, Arme secondaire) : Unite(_nom, _desc, _ressMax, _deplacementMax, _champVision) 
{
	rangeMin = _rangeMin;
	rangeMax = _rangeMax;
	munMax = _munMax;
	munRestante = munMax;
	armePrincipale = &principale;
	armeSecondaire = &secondaire;
}

int UniteArmee::getRangeMin()const
{
	return rangeMin;
}

int UniteArmee::getRangeMax()const
{
	return rangeMax;
}

int UniteArmee::getStockMunActuel()const
{
	return munRestante;
}

int UniteArmee::getStockMaxMun()const
{
	return munMax;
}

void UniteArmee::attaque(Entite *ennemi)
{
	if (ennemi->isUnite()) {
		attaqueUnite((Unite*) ennemi);
	}
	else if (ennemi->isBatiment()) {
		attaqueBatiment();
	}
}

void UniteArmee::attaqueUnite(Unite *ennemi)
{
	if (ennemi->isAerienne()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatAerien());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL){
			ennemi->prendDegat(armeSecondaire->getDegatAerien());
			munRestante--;
		}
	}

	else if (ennemi->isInfanterie()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatInfanterie());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatInfanterie());
			munRestante--;
		}
	}

	else if (ennemi->isMaritime()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatMarin());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatMarin());
			munRestante--;
		}
	}

	else if (ennemi->isMotorise()) {
		if (munRestante > 0) {
			ennemi->prendDegat(armePrincipale->getDegatMotorise());
			munRestante--;
		}
		else if (munRestante < 0 && armeSecondaire != NULL) {
			ennemi->prendDegat(armeSecondaire->getDegatMotorise());
			munRestante--;
		}
	}
}