#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Map.h"
#include "Minimap.h"
#include "Player.h"
#include "UniteArmee.h"
#include "UniteUtilitaire.h"
#include "Interface.h"
#include "Meteo.h"
#include "MenuPrincipal.h"
#include "BatimentManager.h"

class Interface;

class Game
{
private:
	int gameState; // To know if we are in menu or in game
	bool brouillardDeGuerre;
    void loadTextures();
	void loadSprites();

	void definitionCase();
	void definitionCaseDeplacement(int x, int y, int profondeur, int sens);
	void definitionCaseAttaque();
	void definitionCaseAttaque(int x, int y);

	sf::Vector2i definitionCaseClique(int x, int y);
	void surbrillanceCaseDeplacement();

	bool testClicZoneJeu(int x, int y);
	bool testUniteAlliee(int x, int y);
	bool testUniteEnnemie(int x, int y);
	bool testEntiteEnnemie(int x, int y);
	bool testUniteSelectionneTypeCase(int x, int y);
	bool testUniteAllieeInfanterie(int x, int y);
	bool inDeplacement(sf::Vector2f item);
	bool inAttaque(sf::Vector2f item);
	void calculNombreTileAffichable();

	bool tech, batiment;
    int indice;
	void afficherTechAChercher();
	void afficherBatimentAConstruire();
    void afficherPrevTechAChercher();
    void afficherNextTechAChercher();
	void afficherPrevBatimentConstruire();
	void afficherNextBatimentConstruire();
	void next();
	void prec();
	
    void buy();
	MenuPrincipal menu_p;
	Meteo meteo;
	sf::Clock weather_clock;
	void initText();
	UniteManager m_uniteManager;
	BatimentManager m_batimentManager;
	bool attaqueSelectionne, deplacementSelectionne, convertirSelectionne, reapproSelectionne, chargeUniteSelectionne, dechargeUniteSelectionne;
	sf::Vector2i caseClique;
public:
	Game(vector<Player*> joueurs, sf::Vector2i mapSize);
    sf::RenderWindow m_window;
    sf::View m_view, m_viewMinimap, m_viewInterface;
    int c_view[2], m_tour, m_numJoueurActif, m_tileSize;
	sf::Vector2f centreImage, nombreTileAffiche, m_winSize;
    TextureManager m_textureManager;
	SpriteManager m_spriteManager;
	sf::Font font;

	void attaque();
	void deplacement();
	void convertir();
	void reapprovisionne();
	void dechargeUnite();
	void chargeUnite();

	std::vector<sf::Vector2f> m_deplacement, m_attaque;

    Map m_map;
	Minimap m_minimap;
	void changeModeTopo();
	void changeModeUnite();
	void changeModeRessource();
	vector<Player*> m_players;
	Player *m_playerActif;

    void render();
	Player* getPlayerActif();

	Unite* m_uniteSelectionne;
	Batiment* m_batimentSelectionne;
    Technologie* m_technologie;
	Batiment* m_batiment;

	Interface* m_interface;

	void actionUnite();

	void clic(int x, int y);
	void clicInterface(int x, int y);
	void clicZoneJeu(int x, int y);
	void clicUnite(int x, int y, Unite *unite);
	void clicBatiment(int x, int y);

	void joueurSuivant();
	void finTour();
	void selection(sf::Vector2i caseClique, int x, int y);
	void deselection();

	void resize();

	int getState();

	void selectAttaque();
	void selectConvertir();
	void creerVille();
	void exploreSol();
	void selectReapprovisionne();
	void selectChargeUnite();
	void selectDechargeUnite();
	void selectDeplacement();

	void selectionneInfanterieAdjacent();
	void selectionneEnnemiAdjacent();
	void selectionneAllieAdjacent();
	void selectCaseDechargeable();
};