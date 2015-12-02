#include "UniteArmeeMotorise.h"

UniteArmeeMotorise::UniteArmeeMotorise(std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision,
	int _munMax, int _rangeMax, int _rangeMin, Arme principale, Arme secondaire) 
	:UniteArmee(_nom,_desc, _ressMax, _deplacementMax, _champVision, _munMax, _rangeMax, _rangeMin, principale,secondaire)
{

}

bool UniteArmeeMotorise::isMotorise()
{
	return true;
}