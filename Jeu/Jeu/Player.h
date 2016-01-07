#pragma once
#include "Unite.h"
#include "Batiment.h"
#include "CouleurJoueur.h"
#include "SpriteManager.h"
#include "Technologie.h"
#include <list>
#include <iostream>

class Player {
private : 
	sf::Color couleur;
	int energie;
	int essence;
	int metaux;
	int vivre;
	std::vector<Unite*> listUnite;
	std::vector<Batiment*> listBatiment;

public : 
	Player(sf::Color color);

	void creerUnite(Unite *unite,int x, int y, int resistance);
	void detruireUnite(int index);

	void initTechnologies();
	void rechercheTechnologie(Technologie *tech);
	
	//void creerBatiment(Batiment batiment);
	void detruireBatiment(int index);
	void render(sf::RenderWindow *renderWindow, SpriteManager *manager);
	void update();
	int getNombreUnite();
	int getNombreBatiment();
	Unite* getUnite(int index);
	Batiment* getBatiment(int index);
	sf::Color getColor();
};