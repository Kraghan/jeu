#include "UniteUtilitaire.h"

UniteUtilitaire::UniteUtilitaire(int _x, int _y, std::string _nom, std::string _desc, int _ressMax, int _deplacementMax, int _champVision, TypeUnite _type,
	int _reaproRestant, int _outilRestant, Outil _outil,bool peutReappro, bool bougeEtAttaque) 
	: Unite(_x, _y, _nom, _desc, _ressMax, _deplacementMax, _champVision, _type, bougeEtAttaque)
{
	estUtilitaire = true;
	reaproRestante = _reaproRestant;
	outilRestant = _outilRestant;
	outilMax = outilRestant;
	outil = _outil;
	peutReaprovisionner = peutReappro;
	uniteTransporté = NULL;
}

Outil UniteUtilitaire::getOutil() {
	return outil;
}

void UniteUtilitaire::reaprovisionnement() {
	Unite::reaprovisionnement();
	outilRestant = outilMax;
}

void UniteUtilitaire::reapprovisionne(Unite* unite)
{
	if (peutReaprovisionner && reaproRestante > 0) {
		unite->reaprovisionnement();
		reaproRestante--;
		setAAgi();
	}
}

void UniteUtilitaire::chargeUnite(Unite* unite)
{
	if (outil == Outil::transport) {
		unite->setCoord(-1, -1);
		uniteTransporté = unite;
	}
}

void UniteUtilitaire::dechargeUnite(int x, int y)
{
	if (outil == Outil::transport) {
		uniteTransporté->setCoord(x,y);
		uniteTransporté = NULL;
		setAAgi();
	}
}

void UniteUtilitaire::convertir(Unite* ennemi , Player* joueur, Player* joueurEnnemi)
{
	if (outil == Outil::convertisseur) {
		int index = -1;
		for (int i = 0; i < joueurEnnemi->getNombreUnite(); i++) {
			if (joueurEnnemi->getUnite(i)->getCoordX() == ennemi->getCoordX() && joueurEnnemi->getUnite(i)->getCoordY() == ennemi->getCoordY()) {
				index = i;
				break;
			}
		}
		if (joueurEnnemi->getUnite(index)->isUtilitaire()) {
			UniteUtilitaire* u = (UniteUtilitaire*)joueurEnnemi->getUnite(index);
			if (u->estPlein()) {
				Unite* temp = u->getUnite();
				for (int i = 0; i < joueurEnnemi->getNombreUnite(); i++) {
					if (joueurEnnemi->getUnite(i)->getCoordX() == temp->getCoordX() && joueurEnnemi->getUnite(i)->getCoordY() == temp->getCoordY()) {
						joueurEnnemi->detruireUnite(i);
					}
				}
			}
		}
		joueur->creerUnite(ennemi, ennemi->getResistance());
		joueurEnnemi->detruireUnite(index);
		outilRestant--;
		setAAgi();
	}
}

void UniteUtilitaire::explorationDeSol(Player* joueur) 
{
	if (outil == Outil::kitDeGeologue) {
		joueur->decouvreRessource(getCoordX(), getCoordY());
		outilRestant--;
		setAAgi();
	}
}

void UniteUtilitaire::creationVille(Player* player) {
	if (outil == Outil::fondation) {
		player->creerBatiment(new Batiment(getCoordX(), getCoordY(), "Ville", "Batiment permettant d'effectuer les actions de base", Ressource::AUCUNE, 0, 0, 0, 0, 0));
		int index = -1;
		for (int i = 0; i < player->getNombreUnite(); i++) {
			if (player->getUnite(i)->getCoordX() == getCoordX() && player->getUnite(i)->getCoordY() == getCoordY()) {
				index = i;
				break;
			}
		}
		player->detruireUnite(index);
		cout <<"ville fondée"<< player->getNombreBatiment() << endl;
	}
}

int UniteUtilitaire::getOutilRestant() {
	if (outil != Outil::transport && outil != Outil::aucun)
		return outilRestant;
	else
		return 0;
}
int UniteUtilitaire::getReaproRestante() {
	if(outil == Outil::transport)
		return reaproRestante;
	else 
		return 0;
}

bool UniteUtilitaire::estPlein() {
	return uniteTransporté != NULL;
}

Unite* UniteUtilitaire::getUnite() {
	return uniteTransporté;
}