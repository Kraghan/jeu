#pragma once

#include "Entite.h"
#include "Ressource.h"

using namespace std;

class Batiment : public Entite
{
private:
	Ressource ressourceStock;
	int stock, maxStock;
public:
	Batiment(int _x, int _y, string _nom, string _desc, Ressource _ressourceStock, int _maxStock, int _coutEnergie, int _coutVivre, int _coutMetal, int _coutPetrole);
    ~Batiment();

	void prendDegat(int degat);
	void soin();
	void render(sf::RenderWindow *renderWindow, sf::Color color, SpriteManager *manager);
	void update();
	void setStock(int _stock);
	void setStockMax(int _maxStock);

	bool estDetruit();
	bool isBatiment();
	bool isProductionRessource();
	bool isProductionUnite();
	sf::Sprite getIcon(SpriteManager* manager);
	
	Ressource getRessourceStocked();

	int getStock();
	int getMaxStock();

	int getCoutEnergie();
	int getCoutVivre();
	int getCoutMetal();
	int getCoutPetrole();
private:
	int coutEnergie;
	int coutVivre;
	int coutMetal;
	int coutPetrole;
};