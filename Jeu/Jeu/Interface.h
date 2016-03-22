#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Unite.h"
#include "Technologie.h"
#include "UniteArmee.h"
#include "Batiment.h"
#include "Button.h"

class Button;

class Game;

class Interface
{
private:
	bool modeNormal,  modeBatiment;
	int width, height;
	std::vector<Button*> m_buttons;
public:
	Interface();
	Interface(int width, int height);

	void resize(int width, int height);

	bool getModeNormal();
	bool getModeBatiment();

	void setModeNormal();
	void setModeBatiment();

	void render(sf::RenderWindow *renderWindow,SpriteManager *manager);
	void renderPlayer(sf::RenderWindow *renderWindow, Player* player, sf::Font font, float y);
	void renderTechnologies(sf::RenderWindow *renderWindow, sf::Font font, Technologie* technologie);
	void renderInfoUnite(sf::RenderWindow *renderWindow, sf::Font font, Unite *unite, float x, float y);
	void renderInfoBatiment(sf::RenderWindow *renderWindow, sf::Font font, Batiment* batiment);
	void ecrireMessage(sf::RenderWindow *renderWindow, float posX, float posY, std::string msg, sf::Font pathToFont, int fontSize, sf::Color color);
	
	void afficherActionUnite(Unite* unite, SpriteManager* manager, int y);
	void removeActionUnite();
	void removeButton(string nom);

	bool clic(Game* game, int x, int y);
	void ajouterBouton(Button* b);
	Button* getButton(std::string name);
};