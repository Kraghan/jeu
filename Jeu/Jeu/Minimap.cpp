#include <SFML/Graphics.hpp>
#include <iostream>
#include "Minimap.h"

#define TAILLE_MINIMAP 165
#define X 20
#define Y 45

Minimap::Minimap() {}

Minimap::Minimap(Map *map) {
	m_width = map->getWidth();
	m_heigth = map->getHeigth();

	m_imageMinimap.create(m_width,m_heigth);
	m_imageRessource.create(m_width, m_heigth);
	m_topo = true;
	m_ressource = false;
	m_unite = false;

	for (unsigned int i = 0; i < m_width; i++) {
		for (unsigned int j = 0; j < m_heigth;j++) {
			switch (map->getTile(i, j).getTypeCase()) {
			case TypeCase::PLAINE:
				m_imageMinimap.setPixel(i, j, sf::Color(45,200,111));
				break;

			case TypeCase::PLAGE:
				m_imageMinimap.setPixel(i, j, sf::Color(236,220,184));
				break;

			case TypeCase::MONTAGNE:
				m_imageMinimap.setPixel(i, j, sf::Color(137, 164, 166));
				break;

			case TypeCase::MER:
				m_imageMinimap.setPixel(i, j, sf::Color(166,255,245));
				break;

			case TypeCase::FORET:
				m_imageMinimap.setPixel(i, j, sf::Color(27,145,77));
				break;

			case TypeCase::MARAIS:
				m_imageMinimap.setPixel(i, j, sf::Color(88,167,140));
				break;

			case TypeCase::COLINE:
				m_imageMinimap.setPixel(i, j, sf::Color(187,128,68));
				break;

			case TypeCase::VILLE:
				m_imageMinimap.setPixel(i, j, sf::Color(83, 72, 57));
				break;

			default:
				break;
			}
			switch (map->getTile(i, j).getRessource()) {
				case Ressource::VIVRES:
					m_imageRessource.setPixel(i, j, sf::Color(250, 90, 0));
					break;

				case Ressource::METAL:
					m_imageRessource.setPixel(i, j, sf::Color(50, 50, 50));
					break;

				case Ressource::PETROLE:
					m_imageRessource.setPixel(i, j, sf::Color(250, 250, 250));
					break;

				default:
					m_imageRessource.setPixel(i, j, m_imageMinimap.getPixel(i, j));
			}
		}
	}
}

Minimap::Minimap(Map *map, Player *player) {
	m_width = map->getWidth();
	m_heigth = map->getHeigth();
	m_imageMinimap.create(m_width, m_heigth);
	m_imageRessource.create(m_width, m_heigth);
	m_topo = true;
	m_ressource = false;
	m_unite = false;
	updateBrouillard(map, player);
}

void Minimap::updateBrouillard(Map *map, Player *player) {
	
	for (int i = 0; i < m_width; i++) {
		for (int j = 0; j < m_heigth;j++) {
			if (player->aDecouvertLaCase(i, j)) {
				switch (map->getTile(i, j).getTypeCase()) {
				case TypeCase::PLAINE:
					m_imageMinimap.setPixel(i, j, sf::Color(45, 200, 111));
					break;

				case TypeCase::PLAGE:
					m_imageMinimap.setPixel(i, j, sf::Color(236, 220, 184));
					break;

				case TypeCase::MONTAGNE:
					m_imageMinimap.setPixel(i, j, sf::Color(137, 164, 166));
					break;

				case TypeCase::MER:
					m_imageMinimap.setPixel(i, j, sf::Color(166, 255, 245));
					break;

				case TypeCase::FORET:
					m_imageMinimap.setPixel(i, j, sf::Color(27, 145, 77));
					break;

				case TypeCase::MARAIS:
					m_imageMinimap.setPixel(i, j, sf::Color(88, 167, 140));
					break;

				case TypeCase::COLINE:
					m_imageMinimap.setPixel(i, j, sf::Color(187, 128, 68));
					break;

				case TypeCase::VILLE:
					m_imageMinimap.setPixel(i, j, sf::Color(83, 72, 57));
					break;
				
				default:
					m_imageMinimap.setPixel(i, j, sf::Color::Black);
					break;
				}
				if (player->aDecouvertLaRessource(i, j)) {
					switch (map->getTile(i, j).getRessource()) {
					case Ressource::VIVRES:
						m_imageRessource.setPixel(i, j, sf::Color(250, 90, 0));
						break;

					case Ressource::METAL:
						m_imageRessource.setPixel(i, j, sf::Color(250, 250, 250));
						break;

					case Ressource::PETROLE:
						m_imageRessource.setPixel(i, j, sf::Color(50, 50, 50));
						break;
					default:
						m_imageRessource.setPixel(i, j, m_imageMinimap.getPixel(i, j));
					}
				}
				else {
					m_imageRessource.setPixel(i, j, m_imageMinimap.getPixel(i, j));
				}
			}
			else {
				m_imageMinimap.setPixel(i, j, sf::Color::Black);
				m_imageRessource.setPixel(i, j, sf::Color::Black);
			}
		}
	}
}

void Minimap::render(sf::RenderWindow *renderWindow, int width, int height) {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image img;
	img.create(m_width, m_heigth);
	texture.loadFromImage(img);
	sprite.setTexture(texture);
	if (m_ressource) {
		texture.loadFromImage(m_imageRessource);
		sprite.setTexture(texture);
	}
	else if (m_topo) {
		texture.loadFromImage(m_imageMinimap);
		sprite.setTexture(texture);
	}
	else if (m_unite) {
		return;
	}

	float scale = (float)TAILLE_MINIMAP / m_width;
	if ((float)TAILLE_MINIMAP / m_heigth < scale) {
		scale = (float)TAILLE_MINIMAP / m_heigth;
	}

	sprite.scale(scale, scale);

	int x = X + (TAILLE_MINIMAP - m_width*scale) / 2;
	int y = height - INTERFACE_HEIGTH + Y - (TAILLE_MINIMAP - m_heigth*scale) / 2;

	sprite.setPosition(x, y);
	renderWindow->draw(sprite);
}

void Minimap::renderPlayer(sf::RenderWindow *renderWindow, vector<Player*> player, int nbJoueur, int width, int height) {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image img;
	img.create(m_width, m_heigth);
	for (int j = 0; j < nbJoueur; j ++) {
		for (int i = 0; i < player[j]->getNombreUnite(); i++) {
			Unite* unite = player[j]->getUnite(i);
			if (m_imageMinimap.getPixel(unite->getCoordX(), unite->getCoordY()) != sf::Color()) {
				img.setPixel(unite->getCoordX(), unite->getCoordY(), player[j]->getColor());
			}
		}

		for (int i = 0; i < player[j]->getNombreBatiment(); i++) {
			Batiment* batiment = player[j]->getBatiment(i);
			if (m_imageMinimap.getPixel(batiment->getCoordX(), batiment->getCoordY()) != sf::Color()) {
				img.setPixel(batiment->getCoordX(), batiment->getCoordY(), player[j]->getColor());
			}
		}
	}

	for (unsigned int i = 0; i < m_width; i++) {
		for (unsigned int j = 0; j < m_heigth; j++) {
			if (img.getPixel(i, j) == sf::Color(0, 0, 0)) {
				img.setPixel(i, j, m_imageMinimap.getPixel(i, j));
			}
		}
	}

	float scale = (float) TAILLE_MINIMAP / m_width;
	if ((float) TAILLE_MINIMAP / m_heigth < scale) {
		scale = (float) TAILLE_MINIMAP / m_heigth;
	}

	texture.loadFromImage(img);
	sprite.setTexture(texture);

	sprite.scale(scale, scale);

	int x = X + (TAILLE_MINIMAP - m_width*scale) / 2;
	int y = height - INTERFACE_HEIGTH + Y - (TAILLE_MINIMAP - m_heigth*scale) / 2;

	sprite.setPosition(x, y);
	renderWindow->draw(sprite);
}

void Minimap::changeModeTopo() {
	if (!m_topo) {
		m_ressource = false;
		m_unite = false;
		m_topo = true;
	}
}

void Minimap::changeModeRessource() {
	if (!m_ressource) {
		m_ressource = true;
		m_unite = false;
		m_topo = false;
	}
}

void Minimap::changeModeUnite() {
	if (!m_unite) {
		m_ressource = false;
		m_unite = true;
		m_topo = false;
	}
}

bool Minimap::getUniteMode() {
	return m_unite;
}

