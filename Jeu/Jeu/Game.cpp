#include "Game.h"
#include "Constantes.h"
#include "Button.h"

void Game::loadTextures() {
	m_textureManager.loadTexture("unite","media/res/SpriteSheetUnite.png");
	m_textureManager.loadTexture("batiment","media/res/SpriteSheetBatiment.png");
	m_textureManager.getRef("unite").setSmooth(true);
	m_textureManager.loadTexture("interface", "media/res/Interface.png");
	m_textureManager.loadTexture("interfaceBarre", "media/res/InterfaceBarre.png");
	m_textureManager.loadTexture("tile", "media/res/Tile.png");
	m_textureManager.loadTexture("ressource", "media/res/Ressource.png");
	m_textureManager.loadTexture("filtre", "media/res/Filtre.png");
	m_textureManager.loadTexture("ui", "media/res/Ui.png");
	m_textureManager.loadTexture("gui", "media/res/gui.png");
	m_textureManager.loadTexture("fin_de_tour", "media/res/fin_de_tour.png");
	m_textureManager.loadTexture("bouton_technologies", "media/res/bouton_technologies.png");
	m_textureManager.loadTexture("bouton_batiments", "media/res/bouton_batiments.png");
	m_textureManager.loadTexture("bouton_topo", "media/res/bouton_topo.png");
	m_textureManager.loadTexture("bouton_ress", "media/res/bouton_ress.png");
	m_textureManager.loadTexture("bouton_unite", "media/res/bouton_unite.png");
	m_textureManager.loadTexture("bouton_acheter", "media/res/bouton_acheter.png");
	m_textureManager.loadTexture("bouton_precedent", "media/res/bouton_precedent.png");
	m_textureManager.loadTexture("bouton_suivant", "media/res/bouton_suivant.png");

	m_textureManager.loadTexture("bouton_annuler", "media/res/bouton_annuler.png");
	m_textureManager.loadTexture("bouton_attaque", "media/res/bouton_attaque.png");
	m_textureManager.loadTexture("bouton_deplacement", "media/res/bouton_deplacement.png");
	m_textureManager.loadTexture("bouton_convertir", "media/res/bouton_convertir.png");
	m_textureManager.loadTexture("bouton_fondation", "media/res/bouton_fondation.png");
	m_textureManager.loadTexture("bouton_exploration", "media/res/bouton_exploration.png");
	m_textureManager.loadTexture("bouton_reapprovision", "media/res/bouton_reapprovision.png");
	m_textureManager.loadTexture("bouton_charger", "media/res/bouton_charger.png");
	m_textureManager.loadTexture("bouton_decharger", "media/res/bouton_decharger.png");
}

void Game::loadSprites()
{
	m_spriteManager.loadSprite("vie", m_textureManager.getRef("ui"), 128, 10, 0, 1);
	m_spriteManager.loadSprite("vieEnleve", m_textureManager.getRef("ui"), 128, 10, 0, 0);

	m_spriteManager.loadSprite("interface", m_textureManager.getRef("interface"), 800, 200, 0, 0);
	m_spriteManager.getRef("interface").setPosition(0, WIN_HEIGTH - 200);

	m_spriteManager.loadSprite("fin_de_tour", m_textureManager.getRef("fin_de_tour"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_ress", m_textureManager.getRef("bouton_ress"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_unite", m_textureManager.getRef("bouton_unite"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_topo", m_textureManager.getRef("bouton_topo"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_technologies", m_textureManager.getRef("bouton_technologies"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_batiments", m_textureManager.getRef("bouton_batiments"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_acheter", m_textureManager.getRef("bouton_acheter"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_suivant", m_textureManager.getRef("bouton_suivant"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("bouton_precedent", m_textureManager.getRef("bouton_precedent"), 113, 34, 0, 0);

	m_spriteManager.loadSprite("button_annuler", m_textureManager.getRef("bouton_annuler"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_attaque", m_textureManager.getRef("bouton_attaque"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_deplacement", m_textureManager.getRef("bouton_deplacement"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_convertir", m_textureManager.getRef("bouton_convertir"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_fondation", m_textureManager.getRef("bouton_fondation"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_exploration", m_textureManager.getRef("bouton_exploration"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_reapprovision", m_textureManager.getRef("bouton_reapprovision"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_chargerUnite", m_textureManager.getRef("bouton_charger"), 113, 34, 0, 0);
	m_spriteManager.loadSprite("button_dechargerUnite", m_textureManager.getRef("bouton_decharger"), 113, 34, 0, 0);

	m_spriteManager.loadSprite("filtre selection", m_textureManager.getRef("filtre"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("filtre attaque", m_textureManager.getRef("filtre"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("filtre deplacement", m_textureManager.getRef("filtre"), 128, 128, 0, 1);
	m_spriteManager.loadSprite("filtre agi", m_textureManager.getRef("filtre"), 128, 128, 1, 1);

	m_spriteManager.loadSprite("interfaceBarre", m_textureManager.getRef("interfaceBarre"), 800, 60, 0, 0);
	m_spriteManager.getRef("interfaceBarre").setPosition(0, 0);

	m_spriteManager.loadSprite("petrole",m_textureManager.getRef("ressource"),32,32,0,0);
	m_spriteManager.loadSprite("vivre", m_textureManager.getRef("ressource"), 32, 32, 1, 0);
	m_spriteManager.loadSprite("metal", m_textureManager.getRef("ressource"), 32, 32, 0,1);
	m_spriteManager.loadSprite("void", m_textureManager.getRef("ressource"), 32, 32, 1, 1);

	m_spriteManager.loadSprite("plaine", m_textureManager.getRef("tile"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("plage", m_textureManager.getRef("tile"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("montagne", m_textureManager.getRef("tile"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("mer", m_textureManager.getRef("tile"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("foret", m_textureManager.getRef("tile"), 128, 128, 4,0);
	m_spriteManager.loadSprite("marais", m_textureManager.getRef("tile"), 128, 128, 5, 0);
	m_spriteManager.loadSprite("coline", m_textureManager.getRef("tile"), 128, 128, 6, 0);
	m_spriteManager.loadSprite("ville", m_textureManager.getRef("tile"), 128, 128, 7,0);
	m_spriteManager.loadSprite("ruine", m_textureManager.getRef("tile"), 128, 128, 8, 0);

	m_spriteManager.loadSprite("infanterie", m_textureManager.getRef("unite"), 128, 128, 0, 0);
	m_spriteManager.loadSprite("soldat", m_textureManager.getRef("unite"), 128, 128, 1, 0);
	m_spriteManager.loadSprite("soldat_arme", m_textureManager.getRef("unite"), 128, 128, 2, 0);
	m_spriteManager.loadSprite("demolisseur", m_textureManager.getRef("unite"), 128, 128, 3, 0);
	m_spriteManager.loadSprite("colon", m_textureManager.getRef("unite"), 128, 128, 0, 4);
	m_spriteManager.loadSprite("recruteur", m_textureManager.getRef("unite"), 128, 128, 2, 4);
	m_spriteManager.loadSprite("explorateur", m_textureManager.getRef("unite"), 128, 128, 4, 0);

	m_spriteManager.loadSprite("maritime", m_textureManager.getRef("unite"), 128, 128, 0, 1);
	m_spriteManager.loadSprite("cuirasse", m_textureManager.getRef("unite"), 128, 128, 1, 1);
	m_spriteManager.loadSprite("torpilleur", m_textureManager.getRef("unite"), 128, 128, 2, 1);
	m_spriteManager.loadSprite("corvette", m_textureManager.getRef("unite"), 128, 128, 3, 1);
	m_spriteManager.loadSprite("barge", m_textureManager.getRef("unite"), 128, 128, 4, 1);

	m_spriteManager.loadSprite("motorise", m_textureManager.getRef("unite"), 128, 128, 0, 2);
	m_spriteManager.loadSprite("artillerie", m_textureManager.getRef("unite"), 128, 128, 3, 2);
	m_spriteManager.loadSprite("transporteur", m_textureManager.getRef("unite"), 128, 128, 1, 4);
	m_spriteManager.loadSprite("jeep", m_textureManager.getRef("unite"), 128, 128, 1, 2);
	m_spriteManager.loadSprite("char", m_textureManager.getRef("unite"), 128, 128, 2, 2);
	m_spriteManager.loadSprite("dca", m_textureManager.getRef("unite"), 128, 128, 4, 2);

	m_spriteManager.loadSprite("aerien", m_textureManager.getRef("unite"), 128, 128, 0, 3);
	m_spriteManager.loadSprite("chasseur", m_textureManager.getRef("unite"), 128, 128, 1, 3);
	m_spriteManager.loadSprite("bombardier", m_textureManager.getRef("unite"), 128, 128, 2, 3);
	m_spriteManager.loadSprite("helicoptere", m_textureManager.getRef("unite"), 128, 128, 3, 3);
	m_spriteManager.loadSprite("helico_transport", m_textureManager.getRef("unite"), 128, 128, 4, 3);

	m_spriteManager.loadSprite("batiment",m_textureManager.getRef("batiment"),128,128,0,0);
	m_spriteManager.loadSprite("centre_ville",m_textureManager.getRef("batiment"),128,128,1,0);
	m_spriteManager.loadSprite("bibliotheque",m_textureManager.getRef("batiment"),128,128,1,0);
	m_spriteManager.loadSprite("prod_energie",m_textureManager.getRef("batiment"),128,128,0,1);
	m_spriteManager.loadSprite("prod_petrole",m_textureManager.getRef("batiment"),128,128,1,1);
	m_spriteManager.loadSprite("stock_energie",m_textureManager.getRef("batiment"),128,128,0,3);
	m_spriteManager.loadSprite("stock_petrole",m_textureManager.getRef("batiment"),128,128,1,3);
	m_spriteManager.loadSprite("caserne",m_textureManager.getRef("batiment"),128,128,0,2);
	m_spriteManager.loadSprite("usine",m_textureManager.getRef("batiment"),128,128,1,2);

	m_spriteManager.loadSprite("gui_haut_gauche", m_textureManager.getRef("gui"), 10, 30, 0, 0);
	m_spriteManager.loadSprite("gui_haut_milieu", m_textureManager.getRef("gui"), 10, 30, 1, 0);
	m_spriteManager.loadSprite("gui_haut_droite", m_textureManager.getRef("gui"), 10, 30, 2, 0);
	m_spriteManager.loadSprite("gui_centre_gauche", m_textureManager.getRef("gui"), 10, 30, 3, 0);
	m_spriteManager.loadSprite("gui_centre_milieu", m_textureManager.getRef("gui"), 10, 30, 4, 0);
	m_spriteManager.loadSprite("gui_centre_droite", m_textureManager.getRef("gui"), 10, 30, 5, 0);
	m_spriteManager.loadSprite("gui_bas_gauche", m_textureManager.getRef("gui"), 10, 30, 6, 0);
	m_spriteManager.loadSprite("gui_bas_milieu", m_textureManager.getRef("gui"), 10, 30, 7, 0);
	m_spriteManager.loadSprite("gui_bas_droite", m_textureManager.getRef("gui"), 10, 30, 8, 0);
}

Game::Game(vector<Player*> joueurs, sf::Vector2i mapSize)
	: meteo(&m_window), menu_p(&m_window)
{
	gameState = 1;
	brouillardDeGuerre = true;
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
	m_tour = 0;
	m_winSize = sf::Vector2f(WIN_WIDTH, WIN_HEIGTH);
	std::cout << "Chargement des textures ..." << std::endl;
    loadTextures();
	std::cout << "Chargement des textures termine" << std::endl;
	std::cout << "Chargement des sprites ..." << std::endl;
	loadSprites();
	std::cout << "Chargement des sprites termine" << std::endl;
	m_map = Map(mapSize.x, mapSize.y);
	m_minimap = Minimap(&m_map);
	m_interface = new Interface(m_winSize.x, m_winSize.y);
    m_window.create(sf::VideoMode(m_winSize.x,m_winSize.y), "Jeu de Strategie");
	centreImage.x = mapSize.x / 2; centreImage.y = mapSize.y / 2;
	m_tileSize = SPRITE;
	m_batimentManager = BatimentManager();
	m_uniteManager = UniteManager();
	if (mapSize.x % 2 == 0)
		c_view[0] = (mapSize.x * m_tileSize) / 2;
	else
		c_view[0] = ((mapSize.x -1) * m_tileSize) / 2;
	if (mapSize.y % 2 == 0)
		c_view[1] = (mapSize.y * m_tileSize) / 2;
	else
		c_view[1] = ((mapSize.y - 1) * m_tileSize) / 2;

    m_view = sf::View(sf::Vector2f((float)c_view[0],(float)c_view[1]-INTERFACE_HEIGTH),sf::Vector2f(m_winSize.x,m_winSize.y));
	m_viewInterface = sf::View(sf::Vector2f(m_winSize.x/2, m_winSize.y/2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewMinimap = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
    m_window.setFramerateLimit(60);
	m_players = joueurs;
	setSpawnPlayer();
	m_numJoueurActif = 0;
	m_playerActif = m_players[m_numJoueurActif];
	
	if (!font.loadFromFile("media/kenvector_future.ttf"))
	{
		std::cout << "Erreur chargement font" << std::endl;
	}

	Button* bouton_fin_de_tour = new Button("fin de tour", sf::Vector2i(m_winSize.x - (113 + 25), m_winSize.y - 175), m_spriteManager.getRef("fin_de_tour"), &Game::finTour);
	m_interface->ajouterBouton(bouton_fin_de_tour);
	Button* bouton_technologies = new Button("technologies", sf::Vector2i(m_winSize.x - (113 + 25), m_winSize.y - 125), m_spriteManager.getRef("bouton_technologies"), &Game::afficherTechAChercher);
	m_interface->ajouterBouton(bouton_technologies);
	Button* bouton_batiments = new Button("batiments", sf::Vector2i(m_winSize.x - (113 + 25), m_winSize.y - 75), m_spriteManager.getRef("bouton_batiments"), &Game::afficherBatimentAConstruire);
	m_interface->ajouterBouton(bouton_batiments);
	Button* bouton_acheter = new Button("acheter", sf::Vector2i(330, m_winSize.y - 65), m_spriteManager.getRef("bouton_acheter"), &Game::buy);
	bouton_acheter->Disable();
	m_interface->ajouterBouton(bouton_acheter);

	Button* bouton_suivant = new Button("suivant", sf::Vector2i(630, m_winSize.y - 65), m_spriteManager.getRef("bouton_suivant"), &Game::next);
	bouton_suivant->Disable();
	m_interface->ajouterBouton(bouton_suivant);

	Button* bouton_precedent = new Button("precedent", sf::Vector2i(480, m_winSize.y - 65), m_spriteManager.getRef("bouton_precedent"), &Game::prec);
	bouton_precedent->Disable();
	m_interface->ajouterBouton(bouton_precedent);

	Button* bouton_minimap_topo = new Button("topo", sf::Vector2i(200, m_winSize.y - 175), m_spriteManager.getRef("bouton_topo"), &Game::changeModeTopo);
	m_interface->ajouterBouton(bouton_minimap_topo);
	Button* bouton_minimap_ress = new Button("ress", sf::Vector2i(200, m_winSize.y - 125), m_spriteManager.getRef("bouton_ress"), &Game::changeModeRessource);
	m_interface->ajouterBouton(bouton_minimap_ress);
	Button* bouton_minimap_unite = new Button("unite", sf::Vector2i(200, m_winSize.y - 75), m_spriteManager.getRef("bouton_unite"), &Game::changeModeUnite);
	m_interface->ajouterBouton(bouton_minimap_unite);

	Button* annuler = new Button("annuler", sf::Vector2i(0, 0), m_spriteManager.getRef("button_annuler"), &Game::deselection);
	m_interface->ajouterBouton(annuler);

	Button* deplacement = new Button("deplacement", sf::Vector2i(0, 0), m_spriteManager.getRef("button_deplacement"), &Game::selectDeplacement);
	m_interface->ajouterBouton(deplacement);

	Button* attaque = new Button("attaque", sf::Vector2i(0, 0), m_spriteManager.getRef("button_attaque"), &Game::selectAttaque);
	m_interface->ajouterBouton(attaque);

	Button* convertir = new Button("convertir", sf::Vector2i(0, 0), m_spriteManager.getRef("button_convertir"), &Game::selectConvertir);
	m_interface->ajouterBouton(convertir);

	Button* fondation = new Button("creation_ville", sf::Vector2i(0, 0), m_spriteManager.getRef("button_fondation"), &Game::creerVille);
	m_interface->ajouterBouton(fondation);

	Button* exploration = new Button("exploration", sf::Vector2i(0, 0), m_spriteManager.getRef("button_exploration"), &Game::exploreSol);
	m_interface->ajouterBouton(exploration);

	Button* reappro = new Button("reapprovision", sf::Vector2i(0, 0), m_spriteManager.getRef("button_reapprovision"), &Game::selectReapprovisionne);
	m_interface->ajouterBouton(reappro);

	Button* charger = new Button("charger", sf::Vector2i(0, 0), m_spriteManager.getRef("button_chargerUnite"), &Game::selectChargeUnite);
	m_interface->ajouterBouton(charger);

	Button* decharger = new Button("decharger", sf::Vector2i(0, 0), m_spriteManager.getRef("button_dechargerUnite"), &Game::selectDechargeUnite);
	m_interface->ajouterBouton(decharger);

	m_interface->getButton("annuler")->Disable();
	m_interface->getButton("deplacement")->Disable();
	m_interface->getButton("attaque")->Disable();
	m_interface->getButton("convertir")->Disable();
	m_interface->getButton("creation_ville")->Disable();
	m_interface->getButton("exploration")->Disable();
	m_interface->getButton("reapprovision")->Disable();
	m_interface->getButton("charger")->Disable();
	m_interface->getButton("decharger")->Disable();
	
	if (brouillardDeGuerre)
	{
		m_minimap = Minimap(&m_map, m_playerActif);
	}
	else
	{
		m_minimap = Minimap(&m_map);
	}

	tech = false;
	batiment = false;
    indice = 0;

	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
}

void Game::render() {
	if (gameState == 0) {
		menu_p.render();
	}
	if (gameState == 1) {
		//Render de la map et des entites (batiments et unite) 
		m_view.setCenter((float)c_view[0], (float)c_view[1]);
		m_window.setView(m_view);
		calculNombreTileAffichable();
		if (brouillardDeGuerre) {
			m_map.render(&m_window, &m_spriteManager, m_playerActif, nombreTileAffiche, centreImage);
		}
		else {
			m_map.render(&m_window, &m_spriteManager, nombreTileAffiche, centreImage);
		}
		for (int i = 0; i < m_players.size(); i++) {
			if (brouillardDeGuerre) {
				m_players[i]->render(&m_window, &m_spriteManager, m_playerActif, nombreTileAffiche, centreImage);
			}
			else
				m_players[i]->render(&m_window, &m_spriteManager, nombreTileAffiche, centreImage);
		}

		if (m_uniteSelectionne != NULL) {
			surbrillanceCaseDeplacement();
		}
		// Render de l'interface
		m_window.setView(m_viewInterface);
		m_interface->render(&m_window, &m_spriteManager);
		if (m_uniteSelectionne != NULL) {
			m_interface->renderInfoUnite(&m_window, font, m_uniteSelectionne,320,m_winSize.y - INTERFACE_HEIGTH + 40);
		}
		if (m_batimentSelectionne != NULL) {
			m_interface->renderInfoBatiment(&m_window, font, m_batimentSelectionne, 320, m_winSize.y - INTERFACE_HEIGTH + 40);
		}
		if (tech) {
			m_interface->renderTechnologies(&m_window, font, m_technologie);
		}
		if (batiment) {
			m_interface->renderBatiment(&m_window, font, m_batiment);
		}
		m_interface->renderPlayer(&m_window, m_playerActif, font,m_winSize.y-INTERFACE_HEIGTH + 5);
		// Render de la minimap
		m_window.setView(m_viewMinimap);
		if (brouillardDeGuerre) {
			m_minimap.updateBrouillard(&m_map, m_playerActif);
		}
		m_minimap.render(&m_window, m_winSize.x, m_winSize.y);
		if (m_minimap.getUniteMode()) {
			m_minimap.renderPlayer(&m_window, m_players, m_players.size(), m_winSize.x, m_winSize.y);
		}

		if (weather_clock.getElapsedTime().asMilliseconds() < 16) { // 60 fps
			meteo.render();
			weather_clock.restart();
		}
	}
}

void Game::clic(int x, int y) {

	if (gameState == 0) {		
		if (menu_p.hitQuitter(x, y)) {
			m_window.close();
		}

		if (menu_p.hitNouvellePartie(x, y)) {
			gameState = 1;
		}
	}

	if (gameState == 1) {
		if (!m_interface->clic(this, x, y)) {
			if (testClicZoneJeu(x, y)) {
				clicZoneJeu(x, y);
			}
		}
	}
}

bool Game::testClicZoneJeu(int x, int y) {
	return y < m_winSize.y - INTERFACE_HEIGTH;
}

sf::Vector2i Game::definitionCaseClique(int x, int y) {
	sf::Vector2i caseClique(-1, -1);
	// Variable à modifier pour gérer le zoom
	int tailleCaseSurEcran = m_tileSize;
	int nbCaseAfficheParLigne = floor((double)m_winSize.x / (double)tailleCaseSurEcran);
	int nbCaseAfficheParColonne = floor((double)m_winSize.y / (double)tailleCaseSurEcran);
	int decalageX = round((double)(m_winSize.x - (nbCaseAfficheParLigne * tailleCaseSurEcran)) / 2);
	int decalageY = round((double)(m_winSize.y - (nbCaseAfficheParColonne * tailleCaseSurEcran)) / 2);
	if (nbCaseAfficheParLigne % 2 == 1) {
		decalageX = tailleCaseSurEcran/2+decalageX;
	}
	if (nbCaseAfficheParColonne % 2 == 1) {
		decalageY = tailleCaseSurEcran / 2 + decalageY;
	}
	// Défini les zones de clics des cases
	for (int i = 0; i < nbCaseAfficheParLigne; i++) {
		if (x >= decalageX + i*tailleCaseSurEcran && x < decalageX + (i + 1)*tailleCaseSurEcran) {
			caseClique.x = centreImage.x - (nbCaseAfficheParLigne / 2) + i;
			break;
		}
	}
	for (int j = 0; j < nbCaseAfficheParColonne; j++) {
		if(y < decalageY + (j + 1)*tailleCaseSurEcran  && y >= (j*tailleCaseSurEcran) + decalageY) {
			caseClique.y = centreImage.y - (nbCaseAfficheParColonne / 2) + j;
			break;
		}
	}
	if (x < decalageX) {
		caseClique.x = centreImage.x - (nbCaseAfficheParLigne / 2) - 1;
	}
	else if (x > decalageX + nbCaseAfficheParLigne*tailleCaseSurEcran) {
		caseClique.x = centreImage.x + (nbCaseAfficheParLigne / 2);
	}
	if (y < decalageY) {
		caseClique.y = centreImage.y - (nbCaseAfficheParColonne / 2) - 1;
	}
	else if (y > decalageY + nbCaseAfficheParColonne*tailleCaseSurEcran) {
		caseClique.y = centreImage.y + (nbCaseAfficheParColonne / 2);
	}
	return caseClique;
}

void Game::deplacement() {
	for (int i = 0; i < m_deplacement.size(); i++) {
		if (caseClique.x == m_deplacement[i].x / m_tileSize && caseClique.y == m_deplacement[i].y / m_tileSize) {
			m_uniteSelectionne->seDeplace(caseClique.x, caseClique.y, &m_window, m_playerActif->getColor(), &m_spriteManager);
			m_uniteSelectionne->setResistance(m_map.getTile(caseClique.x, caseClique.y).getBonusRes());
			if (brouillardDeGuerre) {
				m_playerActif->decouvre();
			}
		}
	}
}

void Game::attaque() {
	for (int i = 0; i < m_attaque.size(); i++) {
		if (caseClique.x == m_attaque[i].x / m_tileSize && caseClique.y == m_attaque[i].y / m_tileSize) {
			UniteArmee *unite = (UniteArmee*)m_uniteSelectionne;
			for (int j = 0; j < m_players.size(); j++) {
				Player* p = m_players[j];
				if (p->getNom() != m_uniteSelectionne->getNom()) {
					for (int k = 0; k < p->getNombreUnite(); k++) {
						if (p->getUnite(k)->getCoordX() == caseClique.x && p->getUnite(k)->getCoordY() == caseClique.y) {
							unite->attaque(p->getUnite(k));

							if (p->getUnite(k)->estDetruit()) {
								if (p->getUnite(k)->isUtilitaire()) {
									UniteUtilitaire* u = (UniteUtilitaire*)p->getUnite(k);
									if (u->estPlein()) {
										Unite* temp = u->getUnite();
										for (int i = 0; i < p->getNombreUnite(); i++) {
											if (p->getUnite(i)->getCoordX() == temp->getCoordX() && p->getUnite(i)->getCoordY() == temp->getCoordY()) {
												p->detruireUnite(i);
											}
										}
									}
								}
								p->detruireUnite(k);
							}
							if (p->aPerdu()) {
								// Annoncer défaite joueur
								cout << "Le joueur " << p->getNom() << " a perdu" << endl;
								m_players.erase(m_players.begin() + j);
								return;
								if (m_players.size() == 1) {
									// Victoire du joueur
									cout << "Victoire du joueur " << m_players[0]->getNom() << endl;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Game::convertir() {
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	for (int j = 0; j < m_players.size(); j++) {
		Player* p = m_players[j];
		if (p->getNom() != m_uniteSelectionne->getNom()) {
			for (int k = 0; k < p->getNombreUnite(); k++) {
				if (p->getUnite(k)->getCoordX() == caseClique.x && p->getUnite(k)->getCoordY() == caseClique.y) {
					Unite* ennemi = p->getUnite(k);
					u->convertir(ennemi, m_playerActif, p);
					m_playerActif->decouvre();

					if (p->aPerdu()) {
						// Annoncer défaite joueur
						cout << "Le joueur " << p->getNom() << " a perdu" << endl;
						m_players.erase(m_players.begin() + j);
						return;
						if (m_players.size() == 1) {
							// Victoire du joueur
							cout << "Victoire du joueur " << m_players[0]->getNom() << endl;
						}
					}
				}
			}
		}
	}
}

void Game::reapprovisionne() {
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	for (int k = 0; k < m_playerActif->getNombreUnite(); k++) {
		if (m_playerActif->getUnite(k)->getCoordX() == caseClique.x && m_playerActif->getUnite(k)->getCoordY() == caseClique.y) {
			Unite* allie = m_playerActif->getUnite(k);
			u->reapprovisionne(allie);
		}
	}
}

void Game::chargeUnite() {
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	for (int k = 0; k < m_playerActif->getNombreUnite(); k++) {
		if (m_playerActif->getUnite(k)->getCoordX() == caseClique.x && m_playerActif->getUnite(k)->getCoordY() == caseClique.y) {
			Unite* allie = m_playerActif->getUnite(k);
			u->chargeUnite(allie);
		}
	}
}

void Game::dechargeUnite() {
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	u->dechargeUnite(caseClique.x,caseClique.y);
}

void Game::actionUnite() {
	if (caseClique.x != -1 && caseClique.y != -1) {
		if (attaqueSelectionne) {
			attaque();
			deselection();
		}
		else if (deplacementSelectionne) {
			deplacement();
			deselection();
		}
		else if (convertirSelectionne) {
			convertir();
			deselection();
		}
		else if (reapproSelectionne) {
			reapprovisionne();
			deselection();
		}
		else if (chargeUniteSelectionne) {
			chargeUnite();
			deselection();
		}
		else if (dechargeUniteSelectionne) {
			dechargeUnite();
			deselection();
		}
	}
}

void Game::clicZoneJeu(int x, int y) {
	caseClique = definitionCaseClique(x, y);
	if (m_uniteSelectionne != NULL && m_uniteSelectionne->peutAgir()) {
		
	}
	else {
		selection(caseClique, x, y);
	}
}

void Game::clicInterface(int x, int y) {
	m_interface->clic(this, x, y);
}

void Game::afficherTechAChercher() {
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
	batiment = false;
    tech = true;
    indice = 0;
    m_technologie = m_playerActif->getTechnoARechercher()[indice];
	m_interface->getButton("acheter")->Enable();
	m_interface->getButton("suivant")->Enable();
	m_interface->getButton("precedent")->Enable();
}

void Game::afficherBatimentAConstruire() {
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
	tech = false;
	batiment = true;
	indice = 0;
	m_batiment = m_batimentManager.getBatimentConstructible()[indice];
	m_interface->getButton("acheter")->Enable();
	m_interface->getButton("suivant")->Enable();
	m_interface->getButton("precedent")->Enable();
}

void Game::afficherPrevTechAChercher() {
    if (indice > 0) {
        indice--;
        m_technologie = m_playerActif->getTechnoARechercher()[indice];
    }
}

void Game::afficherNextTechAChercher() {
    if (indice < (m_playerActif->getTechnoARechercher().size() - 1)) {
        indice++;
        m_technologie = m_playerActif->getTechnoARechercher()[indice];
    }
}

void Game::afficherPrevBatimentConstruire()
{
	if (indice > 0) {
		indice--;
		m_batiment = m_batimentManager.getBatimentConstructible()[indice];
	}
}

void Game::afficherNextBatimentConstruire()
{
	if (indice < (m_batimentManager.getBatimentConstructible().size() - 1)) {
		indice++;
		m_batiment = m_batimentManager.getBatimentConstructible()[indice];
	}
}

void Game::next()
{
	if (tech)
	{
		afficherNextTechAChercher();
	}
	else if (batiment)
	{
		afficherNextBatimentConstruire();
	}
}

void Game::prec()
{
	if (tech)
	{
		afficherPrevTechAChercher();
	}
	else if (batiment)
	{
		afficherPrevBatimentConstruire();
	}
}

void Game::buy() {
	if (tech)
	{
		m_playerActif->rechercheTechnologie(m_technologie);
		tech = false;
	}
	else if (batiment)
	{

	}
}

Player* Game::getPlayerActif() {
	return m_playerActif;
}

void Game::joueurSuivant() {
	m_numJoueurActif++;
	if (m_numJoueurActif >= m_players.size()) {
		m_tour++;
		m_numJoueurActif = 0;
	}
	std::cout << "c'est au tour du joueur " << m_numJoueurActif << std::endl;
	m_playerActif = m_players[m_numJoueurActif];
	m_playerActif->decouvre();
}

void Game::finTour() {
	m_batimentSelectionne = NULL;
	m_uniteSelectionne = NULL;
	m_deplacement.clear();
	m_attaque.clear();
	m_playerActif->update();
	joueurSuivant();
	// Ca pourrait etre sympa d'afficher en plus "C'est au tour de joueur : "
}

void Game::clicUnite(int x, int y, Unite *unite) {
	m_uniteSelectionne = unite;
	m_interface->afficherActionUnite(m_uniteSelectionne, &m_spriteManager,m_winSize.y-INTERFACE_HEIGTH);
	tech = false;
	batiment = false;
	m_interface->getButton("suivant")->Disable();
	m_interface->getButton("precedent")->Disable();
	m_interface->getButton("acheter")->Disable();

}

void Game::clicBatiment(int x, int y, Batiment *batiment)
{
	m_batimentSelectionne = batiment;
	tech = false;
	batiment = false;
	m_interface->getButton("suivant")->Disable();
	m_interface->getButton("precedent")->Disable();
	m_interface->getButton("acheter")->Disable();
}

void Game::definitionCase() {
	m_attaque.clear();
	m_deplacement.clear();
	// Unite armee
	definitionCaseDeplacement(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY(), m_uniteSelectionne->getDeplacementMax(),0);
	if (m_uniteSelectionne->isArmee()) {
		UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
		if (unite->peutAttaquer()) {
			definitionCaseAttaque();
		}
	}
	else if (m_uniteSelectionne->isUtilitaire()) {
		UniteUtilitaire* unite = (UniteUtilitaire*)m_uniteSelectionne;
		if (unite->getPeutBougerEtAttaquer()) {
		}
		// Unite type colon
		else {

		}
	}
}

bool Game::inDeplacement(sf::Vector2f item) {
	for (int i = 0; i < m_deplacement.size(); i++) {
		if (m_deplacement.at(i).x == item.x && m_deplacement.at(i).y == item.y) {
			return true;
		}
	}
	return false;
}

bool Game::inAttaque(sf::Vector2f item) {
	for (int i = 0; i < m_attaque.size(); i++) {
		if (m_attaque.at(i).x == item.x && m_attaque.at(i).y == item.y) {
			return true;
		}
	}
	return false;
}

void Game::definitionCaseDeplacement(int x, int y, int profondeur, int sens) {
	if (profondeur <= 1) {
		return;
	}
	if (m_map.isInBound(x + 1, y)  && testUniteSelectionneTypeCase(x + 1,y) && !testEntiteEnnemie(x + 1, y,m_numJoueurActif) && sens != 1) {
		if (!inDeplacement(sf::Vector2f((x + 1)*m_tileSize, y*m_tileSize)) && !testUniteAlliee(x + 1, y)) {
			m_deplacement.push_back(sf::Vector2f((x + 1)*m_tileSize, y*m_tileSize));
		}
		if (m_map.getTile(x + 1, y).getTypeCase() == TypeCase::FORET ||
			m_map.getTile(x + 1, y).getTypeCase() == TypeCase::COLINE ||
			m_map.getTile(x + 1, y).getTypeCase() == TypeCase::MARAIS) {
			definitionCaseDeplacement(x + 1, y, profondeur - 2,2);
		}
		else {
			definitionCaseDeplacement(x + 1, y, profondeur - 1,2);
		}
	}
	if (m_map.isInBound(x - 1, y)  && testUniteSelectionneTypeCase(x - 1, y) && !testEntiteEnnemie(x - 1, y, m_numJoueurActif) && sens != 2) {
		if (!inDeplacement(sf::Vector2f((x - 1)*m_tileSize, y*m_tileSize)) && !testUniteAlliee(x - 1, y)) {
			m_deplacement.push_back(sf::Vector2f((x - 1)*m_tileSize, y*m_tileSize));
		}
		if (m_map.getTile(x - 1, y).getTypeCase() == TypeCase::FORET ||
			m_map.getTile(x - 1, y).getTypeCase() == TypeCase::COLINE ||
			m_map.getTile(x - 1, y).getTypeCase() == TypeCase::MARAIS) {
			definitionCaseDeplacement(x - 1, y, profondeur - 2,1);
		}
		else {
			definitionCaseDeplacement(x - 1, y, profondeur - 1,1);
		}
	}
	if (m_map.isInBound(x, y + 1)  && testUniteSelectionneTypeCase(x, y + 1) && !testEntiteEnnemie(x, y + 1, m_numJoueurActif) && sens != 3) {
		if (!inDeplacement(sf::Vector2f(x*m_tileSize, (y + 1)*m_tileSize)) && !testUniteAlliee(x, y + 1)) {
			m_deplacement.push_back(sf::Vector2f(x*m_tileSize, (y + 1)*m_tileSize));
		}
		if (m_map.getTile(x, y + 1).getTypeCase() == TypeCase::FORET ||
			m_map.getTile(x, y + 1).getTypeCase() == TypeCase::COLINE ||
			m_map.getTile(x, y + 1).getTypeCase() == TypeCase::MARAIS) {
			definitionCaseDeplacement(x, y + 1, profondeur - 2,4);
		}
		else {
			definitionCaseDeplacement(x, y + 1, profondeur - 1,4);
		}
	}
	if (m_map.isInBound(x, y - 1) && testUniteSelectionneTypeCase(x, y - 1) && !testEntiteEnnemie(x, y - 1, m_numJoueurActif) && sens != 4) {
		if (!inDeplacement(sf::Vector2f(x*m_tileSize, (y - 1)*m_tileSize)) && !testUniteAlliee(x, y - 1)) {
			m_deplacement.push_back(sf::Vector2f(x*m_tileSize, (y - 1)*m_tileSize));
		}
		if (m_map.getTile(x, y - 1).getTypeCase() == TypeCase::FORET ||
			m_map.getTile(x, y - 1).getTypeCase() == TypeCase::COLINE ||
			m_map.getTile(x, y - 1).getTypeCase() == TypeCase::MARAIS) {
			definitionCaseDeplacement(x, y - 1, profondeur - 2,3);
		}
		else {
			definitionCaseDeplacement(x, y - 1, profondeur - 1,3);
		}
	}
}

void Game::definitionCaseAttaque() {
	UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
	if (unite->getPeutBougerEtAttaquer()) {
		for (int i = 0; i < m_deplacement.size();i++) {
			definitionCaseAttaque(m_deplacement[i].x/m_tileSize, m_deplacement[i].y / m_tileSize);
		}
	}
	else {
		definitionCaseAttaque(unite->getCoordX(), unite->getCoordY());
	}
}

void Game::definitionCaseAttaque(int x, int y) {
	UniteArmee* unite = (UniteArmee*)m_uniteSelectionne;
	int max = unite->getRangeMax();
	int min = unite->getRangeMin();
	for (int i = x - max; i <= x + max; i++) {
		if (m_map.isInBound(i, 0)) {
			for (int j = y - max; j <= y + max; j++) {
				if (m_map.isInBound(i, j) && abs(y - j) + abs(x - i) >= min && abs(y - j) + abs(x - i) < max && !inAttaque(sf::Vector2f(i*m_tileSize, j*m_tileSize)) && testEntiteEnnemie(i,j, m_numJoueurActif)) {
					m_attaque.push_back(sf::Vector2f(i*m_tileSize, j*m_tileSize));
				}
			}
		}
	}
}

void Game::calculNombreTileAffichable() {
	 nombreTileAffiche.x = m_winSize.x / m_tileSize;
	 nombreTileAffiche.y = (m_winSize.y - INTERFACE_HEIGTH) / m_tileSize ;
}

void Game::surbrillanceCaseDeplacement() {
	sf::Sprite sprite = m_spriteManager.getRef("filtre attaque");
	for (int i = 0; i < m_attaque.size(); i++) {
		sprite.setPosition(m_attaque[i]);
		m_window.draw(sprite);
	}

	sprite = m_spriteManager.getRef("filtre deplacement");
	for (int i = 0; i < m_deplacement.size(); i++) {
		sprite.setPosition(m_deplacement[i]);
		m_window.draw(sprite);
	}
	sprite = m_spriteManager.getRef("filtre selection");
	sprite.setPosition(sf::Vector2f(m_uniteSelectionne->getCoordX()*m_tileSize, m_uniteSelectionne->getCoordY()*m_tileSize));
	m_window.draw(sprite);
}

bool Game::testUniteAlliee(int x, int y) {
	if (x == m_uniteSelectionne->getCoordX() && y == m_uniteSelectionne->getCoordY()) {
		return false;
	}
	for (int i = 0; i < getPlayerActif()->getNombreUnite(); i++) {
		if (m_playerActif->getUnite(i)->getCoordX() == x && m_playerActif->getUnite(i)->getCoordY() == y) {
			return true;
		}
	}
	return false;
}

bool Game::testUniteAllieeInfanterie(int x, int y) {
	if (x == m_uniteSelectionne->getCoordX() && y == m_uniteSelectionne->getCoordY()) {
		return false;
	}
	for (int i = 0; i < getPlayerActif()->getNombreUnite(); i++) {
		if (m_playerActif->getUnite(i)->getCoordX() == x && m_playerActif->getUnite(i)->getCoordY() == y) {
			return m_playerActif->getUnite(i)->isInfanterie();
		}
	}
	return false;
}

bool Game::testUniteEnnemie(int x, int y) {
	for (int j = 0; j < m_players.size(); j++) {
		Player* p = m_players[j];
		if (p->getNom() != m_uniteSelectionne->getNom()) {
			for (int i = 0; i < p->getNombreUnite(); i++) {
				if (p->getUnite(i)->getCoordX() == x && p->getUnite(i)->getCoordY() == y) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Game::testEntiteEnnemie(int x, int y, int numPlayer) {
	for (int j = 0; j < m_players.size(); j++) {
		Player* p = m_players[j];
		if (p->getNom() != m_players[numPlayer]->getNom()) {
			for (int i = 0; i < p->getNombreUnite(); i++) {
				if (p->getUnite(i)->getCoordX() == x && p->getUnite(i)->getCoordY() == y) {
					return true;
				}
			}
			for (int i = 0; i < p->getNombreBatiment(); i++) {
				if (p->getBatiment(i)->getCoordX() == x && p->getBatiment(i)->getCoordY() == y) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Game::testUniteSelectionneTypeCase(int x, int y) {
	TypeCase caseActuelle = m_map.getTile(x, y).getTypeCase();
	if (caseActuelle == TypeCase::MONTAGNE && !m_uniteSelectionne->isAerienne())
		return false;
	if (m_uniteSelectionne->isMaritime()) {
		if (caseActuelle == TypeCase::MER || caseActuelle == TypeCase::PLAGE) 
			return true;
	}
	else if (m_uniteSelectionne->isInfanterie() || m_uniteSelectionne->isMotorise()) {
		if (caseActuelle == TypeCase::MER)
			return false;
	}
	return true;
}

void Game::selection(sf::Vector2i caseClique, int x, int y) {
	if(m_uniteSelectionne == NULL && m_batimentSelectionne == NULL){
		m_deplacement.clear();
		m_attaque.clear();
		for (int i = 0; i < m_playerActif->getNombreUnite(); i++) {
			if (m_playerActif->getUnite(i)->getCoordX() == caseClique.x && m_playerActif->getUnite(i)->getCoordY() == caseClique.y && m_playerActif->getUnite(i)->peutAgir()) {
				clicUnite(x, y, m_playerActif->getUnite(i));
			}
		}
		if (m_uniteSelectionne == NULL) {
			for (int i = 0; i < m_playerActif->getNombreBatiment(); i++) {
				if (m_playerActif->getBatiment(i)->getCoordX() == caseClique.x && m_playerActif->getBatiment(i)->getCoordY() == caseClique.y) {
					clicBatiment(x, y, m_playerActif->getBatiment(i));
				}
			}
		}
	}
}

void Game::deselection() {
	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
	caseClique.x = caseClique.y = -1;
	m_uniteSelectionne = NULL;
	m_batimentSelectionne = NULL;
	m_interface->removeActionUnite();
}

void Game::resize()
{
	m_winSize.x = m_window.getSize().x;
	m_winSize.y = m_window.getSize().y;
	m_view = sf::View(sf::Vector2f((float)c_view[0], (float)c_view[1]), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewInterface = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_viewMinimap = sf::View(sf::Vector2f(m_winSize.x / 2, m_winSize.y / 2), sf::Vector2f(m_winSize.x, m_winSize.y));
	m_interface->resize(m_winSize.x, m_winSize.y);
	m_interface->getButton("fin de tour")->move(m_winSize.x-(113 + 25), m_winSize.y - 175);
	m_interface->getButton("technologies")->move(m_winSize.x - (113 + 25), m_winSize.y - 125);
	m_interface->getButton("batiments")->move(m_winSize.x - (113 + 25), m_winSize.y - 75);
	m_interface->getButton("topo")->move(200, m_winSize.y - 175);
	m_interface->getButton("ress")->move(200, m_winSize.y - 125);
	m_interface->getButton("unite")->move(200, m_winSize.y - 75);
	m_interface->getButton("acheter")->move(330, m_winSize.y - 65);
	m_interface->getButton("suivant")->move(630, m_winSize.y - 65);
	m_interface->getButton("precedent")->move(480, m_winSize.y - 65);
	if (m_uniteSelectionne != NULL) {
		m_interface->removeActionUnite();
		m_interface->afficherActionUnite(m_uniteSelectionne, &m_spriteManager, m_winSize.y - INTERFACE_HEIGTH);
	}
}

int Game::getState() {
	return gameState;
}

void Game::changeModeTopo() {
	m_minimap.changeModeTopo();
}

void Game::changeModeRessource() {
	m_minimap.changeModeRessource();
}

void Game::changeModeUnite() {
	m_minimap.changeModeUnite();
}

void Game::selectionneEnnemiAdjacent() {
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteEnnemie(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() - 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteEnnemie(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() + 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
		if (testUniteEnnemie(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() - 1)*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
		if (testUniteEnnemie(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() + 1)*m_tileSize));
		}
	}
}

void Game::selectionneAllieAdjacent() {
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteAlliee(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() - 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteAlliee(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() + 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
		if (testUniteAlliee(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() - 1)*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
		if (testUniteAlliee(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() + 1)*m_tileSize));
		}
	}
}

void Game::selectionneInfanterieAdjacent() {
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteAllieeInfanterie(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() - 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
		if (testUniteAllieeInfanterie(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() + 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
		if (testUniteAllieeInfanterie(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() - 1)*m_tileSize));
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
		if (testUniteAllieeInfanterie(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
			m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() + 1)*m_tileSize));
		}
	}
}

void Game::selectCaseDechargeable() {
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY())) {
		if (m_map.getTile(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY()).getTypeCase() != TypeCase::MONTAGNE &&
			m_map.getTile(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY()).getTypeCase() != TypeCase::MER) {
			if(m_uniteSelectionne->isMaritime() && m_map.getTile(m_uniteSelectionne->getCoordX() - 1, m_uniteSelectionne->getCoordY()).getTypeCase() == TypeCase::PLAGE )
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() - 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
			else if (!m_uniteSelectionne->isMaritime()) {
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() - 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
			}
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY())) {
		if (m_map.getTile(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY()).getTypeCase() != TypeCase::MONTAGNE &&
			m_map.getTile(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY()).getTypeCase() != TypeCase::MER) {
			if (m_uniteSelectionne->isMaritime() && m_map.getTile(m_uniteSelectionne->getCoordX() + 1, m_uniteSelectionne->getCoordY()).getTypeCase() == TypeCase::PLAGE)
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() + 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
			else if (!m_uniteSelectionne->isMaritime()) {
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX() + 1)*m_tileSize, (m_uniteSelectionne->getCoordY())*m_tileSize));
			}
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1)) {
		if (m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1).getTypeCase() != TypeCase::MONTAGNE &&
			m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1).getTypeCase() != TypeCase::MER) {
			if (m_uniteSelectionne->isMaritime() && m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() - 1).getTypeCase() == TypeCase::PLAGE)
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() - 1)*m_tileSize));
			else if (!m_uniteSelectionne->isMaritime()) {
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() - 1)*m_tileSize));
			}
		}
	}
	if (m_map.isInBound(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1)) {
		if (m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1).getTypeCase() != TypeCase::MONTAGNE &&
			m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1).getTypeCase() != TypeCase::MER) {
			if (m_uniteSelectionne->isMaritime() && m_map.getTile(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY() + 1).getTypeCase() == TypeCase::PLAGE)
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() + 1)*m_tileSize));
			else if (!m_uniteSelectionne->isMaritime()) {
				m_attaque.push_back(sf::Vector2f((m_uniteSelectionne->getCoordX())*m_tileSize, (m_uniteSelectionne->getCoordY() + 1)*m_tileSize));
			}
		}
	}
}

void Game::selectAttaque() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	definitionCaseAttaque(m_uniteSelectionne->getCoordX(),m_uniteSelectionne->getCoordY());
	attaqueSelectionne = true;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
	actionUnite();
}

void Game::selectDeplacement() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	definitionCaseDeplacement(m_uniteSelectionne->getCoordX(), m_uniteSelectionne->getCoordY(), m_uniteSelectionne->getDeplacementMax(), 0);
	attaqueSelectionne = false;
	deplacementSelectionne = true;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
	actionUnite();
}

void Game::selectConvertir() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	selectionneEnnemiAdjacent();
	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = true;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
	actionUnite();
}

void Game::selectReapprovisionne() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	selectionneAllieAdjacent();
	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = true;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = false;
	actionUnite();
}

void Game::selectChargeUnite() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	selectionneInfanterieAdjacent();
	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = true;
	dechargeUniteSelectionne = false;
	actionUnite();
}

void Game::selectDechargeUnite() {
	m_deplacement.clear();
	m_attaque.clear();
	caseClique.x = caseClique.y = -1;
	selectCaseDechargeable();
	attaqueSelectionne = false;
	deplacementSelectionne = false;
	convertirSelectionne = false;
	reapproSelectionne = false;
	chargeUniteSelectionne = false;
	dechargeUniteSelectionne = true;
	actionUnite();
}

void Game::creerVille() {
	m_deplacement.clear();
	m_attaque.clear();
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	u->creationVille(m_playerActif);
	deselection();
}

void Game::exploreSol() {
	m_deplacement.clear();
	m_attaque.clear();
	UniteUtilitaire* u = (UniteUtilitaire*)m_uniteSelectionne;
	u->explorationDeSol(m_playerActif);
	deselection();
}

int Game::random(int a, int b) {
	return rand() % (b - a) + a;
}

bool Game::testInfanterieTypeCase(int x, int y) {
	switch (m_map.getTile(x, y).getTypeCase()) {
	case TypeCase::FORET:
		return true;
	case TypeCase::COLINE:
		return true;
	case TypeCase::MARAIS:
		return true;
	case TypeCase::PLAGE:
		return true;
	case TypeCase::PLAINE:
		return true;
	case TypeCase::RUINE:
		return true;
	case TypeCase::VILLE:
		return true;
	default : 
		return false;
	}
}

bool Game::presenceEnnemie(int x, int y, int radius, int numJoueur) {
	for (int i = x - radius; i < x + radius; i++) {
		if (m_map.isInBound(i, 0)) {
			for (int j = y - radius; j < y + radius; j++) {
				if (m_map.isInBound(i, j)) {
					if (testEntiteEnnemie(i, j,numJoueur)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Game::spawnProche(int x, int y, int radius, vector<sf::Vector2i> spawnPoint) {
	for (int i = x - radius; i < x + radius; i++) {
		if (m_map.isInBound(i, 0)) {
			for (int j = y - radius; j < y + radius; j++) {
				if (m_map.isInBound(i, j)) {
					for (int k = 0; k < spawnPoint.size(); k ++){
						if (spawnPoint[k].x == i && spawnPoint[k].y == j) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void Game::setSpawnPlayer() {
	vector<sf::Vector2i> pointSpawn;
	for (int i = 4; i < m_map.getWidth()-5; i++) {
		for (int j = 4; j < m_map.getHeigth()-5; j++) {
			if (testInfanterieTypeCase(i, j) && !spawnProche(i, j, 7, pointSpawn)) {
				if (testInfanterieTypeCase(i + 1, j) && testInfanterieTypeCase(i, j + 1)) {
					pointSpawn.push_back(sf::Vector2i(i, j));
				}
			}
		}
	}
	if (pointSpawn.size() < m_players.size()) {
		cerr << "Pas assez de point de spawn pour le nombre de joueur" << endl;
		return;
	}
	for (int joueur = 0; joueur < m_players.size();joueur++) {
		int index = random(0, pointSpawn.size());
		Player* p = m_players[joueur];
		p->creerUnite(m_uniteManager.creerUnite("Colon", pointSpawn[index].x, pointSpawn[index].y), m_map.getTile(pointSpawn[index].x, pointSpawn[index].y).getBonusRes());
		p->creerUnite(m_uniteManager.creerUnite("Soldat", pointSpawn[index].x + 1, pointSpawn[index].y), m_map.getTile(pointSpawn[index].x + 1, pointSpawn[index].y).getBonusRes());
		p->creerUnite(m_uniteManager.creerUnite("Explorateur", pointSpawn[index].x, pointSpawn[index].y + 1), m_map.getTile(pointSpawn[index].x, pointSpawn[index].y + 1).getBonusRes());
		p->decouvre();
		pointSpawn.erase(pointSpawn.begin()+index);
	}
}