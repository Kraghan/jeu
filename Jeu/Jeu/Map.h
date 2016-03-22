#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"
#include "SpriteManager.h"
#include "Constantes.h"
#include "Player.h"

class Map {
private:
	int m_width, m_heigth;
    vector<vector<Tile>> m_tiles;
    unsigned int permutation[256];

public:
	Map() {};
	Map(int width, int heigth);

	int getWidth();
	int getHeigth();

	bool isInBound(int x, int y);

    void mapGenerator();
    float bruitPerlin(float x, float y, float res);
    TypeCase whichType(float hauteur);

	Tile getTile(int x, int y);

    void render(sf::RenderWindow* renderWindow, SpriteManager *manager, Player *player, sf::Vector2f nbCase, sf::Vector2f caseCentrale);
	void render(sf::RenderWindow* renderWindow, SpriteManager *manager, sf::Vector2f nbCase, sf::Vector2f caseCentrale);

	void loadMap(std::string nomMap);
};