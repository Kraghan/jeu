#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Game.h"

class Game;

class Button 
{
private : 
	bool enabled, pressed;
	sf::Sprite sprite;
	sf::Vector2i coord;
	sf::Vector2u taille;
	std::string name;
	void(Game::*func)(void);

public :
	Button(std::string _name, sf::Vector2i _coord, sf::Sprite _button, void(Game::*_func)(void));
	void Enable();
	void Disable();
	bool isEnabled();
	bool clic(Game* game, int x, int y);
	std::string getNom();
	void move(int x, int y);

	void render(sf::RenderWindow *renderWindow);

	
};