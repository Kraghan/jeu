#include <string>
#include "Unite.h"
using namespace std;


Unite::Unite(string _nom, string _desc, int _ressMax, int _deplacementMax, int _champVision) : Entite(_nom, _desc)
{
	stockResssourceMax = _ressMax;
	deplacementMax = _deplacementMax;
	stockRessourceActuel = stockResssourceMax;
	deplacementRestant = deplacementMax;
	champVision = _champVision;
	resistance = 0;
}

int Unite::getStockMaxRess() const
{
	return stockResssourceMax;
}

int Unite::getDeplacementMax()const
{
	return deplacementMax;
}

int Unite::getChampVision()const
{
	return champVision;
}

int Unite::getResistance() const
{
	return resistance;
}

void Unite::setResistance(int _res) 
{
	resistance = _res;
}


int Unite::getStockRessActuel()const
{
	return stockRessourceActuel;
}

int Unite::getDeplacementRestant()const
{
	return deplacementRestant;
}

bool Unite::peutSeDeplacer()const
{
	return deplacementRestant > 0;
}

void Unite::update()
{

}

void Unite::render()
{

}

void Unite::soin() {
	setPvRestant(getPvRestant() + 2);
}

bool Unite::estDetruit() {
	return getPvRestant() < 0;
}

void Unite::reaprovisionnement()
{
	stockRessourceActuel = stockResssourceMax;
}

void Unite::prendDegat(int degat)
{
	setPvRestant(getPvRestant() - (degat - resistance));
}

void Unite::seDeplace(int nbCaseDeplace)
{
	deplacementRestant -= nbCaseDeplace;
}

bool Unite::isUnite() {
	return true;
}

bool Unite::isAerienne() {
	return false;
}

bool Unite::isMotorise() {
	return false;
}

bool Unite::isInfanterie() {
	return false;
}

bool Unite::isMaritime() {
	return false;
}