#pragma once
#include "UniteArmee.h"

class UniteArmeeAerienne : UniteArmee {
public:
	UniteArmeeAerienne(std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision,
		int _munMax, int _rangeMax, int _rangeMin, Arme principale, Arme secondaire);
	bool isAerienne();
};