#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Constantes.h"
#include "UniteManager.h"
#include "MenuPrincipal.h"

int main()
{
	sf::Vector2i mapSize(MAP_WIDTH, MAP_HEIGTH);
	vector<Player*> joueurs;
	joueurs.push_back(new Player(sf::Color::Cyan, "José", mapSize.x, mapSize.y));
	joueurs.push_back(new Player(sf::Color::Green, "Robert", mapSize.x, mapSize.y));
	joueurs.push_back(new Player(sf::Color::Magenta, "Gérard", mapSize.x, mapSize.y));
	joueurs.push_back(new Player(sf::Color::Red, "Thierry", mapSize.x, mapSize.y));
    Game* game = new Game(joueurs,mapSize);

	bool leftPressed(false), rightPressed(false), upPressed(false), downPressed(false);
	float zoom = 1;
	sf::Clock m_clock;

	sf::Clock c; //Timer pour les déplacements de la carte à la souris
	int fps_move_mouse = 200; //fps des déplacmeents de la caméra à la souris
	int detecte_zone = 3; //zone de détection pour la caméra à la souris

    while(game->m_window.isOpen())
    {
        sf::Event event;
        while(game->m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
				game->m_window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Left:
						if(!leftPressed)
							leftPressed = true;
                        break;
                    case sf::Keyboard::Right:
						if(!rightPressed)
							rightPressed = true;
                        break;
                    case sf::Keyboard::Up:
						if(!upPressed)
							upPressed = true;
                        break;
                    case sf::Keyboard::Down:
						if(!downPressed)
							downPressed = true;
                        break;
                    case sf::Keyboard::Space:
						if (game->m_map.getWidth() % 2 == 0)
							game->c_view[0] = (game->m_map.getWidth() * game->m_tileSize) / 2;
						else
							game->c_view[0] = ((game->m_map.getWidth() - 1) * game->m_tileSize) / 2;
						if (game->m_map.getHeigth() % 2 == 0)
							game->c_view[1] = (game->m_map.getHeigth() * game->m_tileSize) / 2;
						else
							game->c_view[1] = ((game->m_map.getHeigth() - 1) * game->m_tileSize) / 2;
                        break;
                    default:
                        break;
                }
            }

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					leftPressed = false;
					break;
				case sf::Keyboard::Right:
					rightPressed = false;
					break;
				case sf::Keyboard::Up:
					upPressed = false;
					break;
				case sf::Keyboard::Down:
					downPressed = false;
					break;
				default:
					break;
				}
			}

			if (event.type == sf::Event::Resized)
			{
				game->resize();
			}

            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta < 0)
                {
					
                }
                else
                {
                    
                }
            }

			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					game->clic(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					game->deselection();
				}
			}

			if (leftPressed)
			{
				if (game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[0] -= game->m_tileSize;
					game->centreImage.x --;
				}
			}

			if (rightPressed)
			{
				if (game->c_view[0] + ((game->m_winSize.x / 2) - game->m_tileSize) < (game->m_map.getWidth() * game->m_tileSize))
				{
					game->c_view[0] += game->m_tileSize;
					game->centreImage.x ++;
				}
			}

			if (upPressed)
			{
				if (game->c_view[1] - ((game->m_winSize.y / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] -= game->m_tileSize;
					game->centreImage.y --;
				}
			}

			if (downPressed)
			{
				if (game->c_view[1] + ((game->m_winSize.y / 2) - game->m_tileSize) < (game->m_map.getHeigth() * game->m_tileSize))
				{
					game->c_view[1] += game->m_tileSize;
					game->centreImage.y ++;
				}
			}
        }
		if (sf::Mouse::getPosition(game->m_window).x >= 0 && sf::Mouse::getPosition(game->m_window).x < game->m_winSize.x
			&& sf::Mouse::getPosition(game->m_window).y >= -30 && sf::Mouse::getPosition(game->m_window).y < game->m_winSize.y) {
			if (sf::Mouse::getPosition(game->m_window).x <= detecte_zone && sf::Mouse::getPosition(game->m_window).y <= detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] -= game->m_tileSize;
					game->centreImage.y--;
					game->c_view[0] -= game->m_tileSize;
					game->centreImage.x--;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).x <= detecte_zone && sf::Mouse::getPosition(game->m_window).y >= game->m_winSize.y - detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] += game->m_tileSize;
					game->centreImage.y++;
					game->c_view[0] -= game->m_tileSize;
					game->centreImage.x--;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).x >= game->m_winSize.x - detecte_zone && sf::Mouse::getPosition(game->m_window).y <= detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] -= game->m_tileSize;
					game->centreImage.y--;
					game->c_view[0] += game->m_tileSize;
					game->centreImage.x++;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).x >= game->m_winSize.x - detecte_zone && sf::Mouse::getPosition(game->m_window).y >= game->m_winSize.y - detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] += game->m_tileSize;
					game->centreImage.y++;
					game->c_view[0] += game->m_tileSize;
					game->centreImage.x++;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).x <= detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] - ((game->m_winSize.x / 2) - game->m_tileSize) > 0)
				{
					game->c_view[0] -= game->m_tileSize;
					game->centreImage.x--;
					c.restart();
				}
			}

			else if (sf::Mouse::getPosition(game->m_window).x >= game->m_winSize.x - detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[0] + ((game->m_winSize.x / 2) - game->m_tileSize) < (game->m_map.getWidth() * game->m_tileSize))
				{
					game->c_view[0] += game->m_tileSize;
					game->centreImage.x++;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).y <= detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[1] - ((game->m_winSize.y / 2) - game->m_tileSize) > 0)
				{
					game->c_view[1] -= game->m_tileSize;
					game->centreImage.y--;
					c.restart();
				}
			}
			else if (sf::Mouse::getPosition(game->m_window).y >= game->m_winSize.y - detecte_zone) {
				if (c.getElapsedTime().asMilliseconds() >= fps_move_mouse && game->c_view[1] + ((game->m_winSize.y / 2) - game->m_tileSize) < (game->m_map.getHeigth() * game->m_tileSize))
				{
					game->c_view[1] += game->m_tileSize;
					game->centreImage.y++;
					c.restart();
				}
			}
		}

		game->m_window.clear(sf::Color::Black);
		game->actionUnite();
		game->render();
		game->m_window.display();
		m_clock.restart();
    }

    return EXIT_SUCCESS;
}
