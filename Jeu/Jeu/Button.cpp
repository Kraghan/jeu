#include "Button.h"

Button::Button(std::string _name, sf::Vector2i _coord, sf::Sprite _sprite, void(Game::*_func)(void))
{
	this->name = _name;
	this->coord = _coord;
	this->taille = _sprite.getTexture()->getSize();
	this->func = _func;
	this->sprite = _sprite;
	enabled = true;
}

void Button::Enable()
{
	enabled = true;
}

void Button::Disable()
{
	enabled = false;
}

bool Button::isEnabled()
{
	return enabled;
}

bool Button::clic(Game* game, int x, int y)
{
	if (x >= coord.x && x <= coord.x + taille.x && y >= coord.y && y <= coord.y + taille.y && enabled)
	{
		(game->*func)();
		return true;
	}
	return false;
}

void Button::render(sf::RenderWindow *renderWindow)
{
	if (!enabled)
		return;
	sprite.setPosition(coord.x, coord.y);
	renderWindow->draw(sprite);
}

std::string Button::getNom()
{
	return name;
}

void Button::move(int x, int y)
{
	this->coord = sf::Vector2i(x, y);
}