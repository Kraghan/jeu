#include "BatimentManager.h"


BatimentManager::BatimentManager()
{
	m_batiments["Ville"] = new Batiment(-1,-1,"Ville","Batiment permettant d'effectuer les actions de base", Ressource::AUCUNE, 0, 0, 0, 0, 0);
	m_batiments["AvantPoste"] = new Batiment(-1, -1, "Ville", "Batiment permettant d'effectuer les actions de base", Ressource::AUCUNE, 0, 0, 0, 0, 0);
	m_batiments["Bibliotheque"] = new Batiment(-1, -1, "Bibliotheque", "Batiment permettant d'effectuer des recherches", Ressource::AUCUNE, 0, 0, 0, 0, 0);

	m_batiments["Grenier"] = new Batiment(-1, -1, "Grenier", "Batiment de stockage de vivres", Ressource::VIVRES, 250, 0, 0, 0, 0);
	m_batiments["Reserve"] = new Batiment(-1, -1, "Reserve", "Batiment de stockage de metal", Ressource::METAL, 250, 0, 0, 0, 0);
	m_batiments["Reservoir"] = new Batiment(-1, -1, "Reservoir", "Batiment de stockage de petrole", Ressource::PETROLE, 250, 0, 0, 0, 0);

	m_batiments["PuitPetrole"] = new ProductionRessource(-1, -1, "Puit à pétrole", "Batiment qui produit du pétrole", Ressource::PETROLE, 100, Ressource::PETROLE, 5, 0, 0, 0, 0);
	m_batiments["Generateur"] = new ProductionRessource(-1, -1, "Generateur", "Batiment qui produit et stock de l'energie", Ressource::ENERGIE, 300, Ressource::ENERGIE, 10, 0, 0, 0, 0);
	m_batiments["StationPompage"] = new ProductionRessource(-1, -1, "Station de pompage", "Batiment qui produit des vivres", Ressource::VIVRES, 100, Ressource::VIVRES, 5, 0, 0, 0, 0);
	m_batiments["ExploitationMetal"] = new ProductionRessource(-1, -1, "Exploitation de metal", "Batiment qui produit du métal", Ressource::METAL, 100, Ressource::METAL, 5, 0, 0, 0, 0);
	
	//m_batiments["Caserne"] = new ProductionsUnite();
	//m_batiments["Usine"] = new ProductionsUnite();
	//m_batiments["Aeroport"] = new ProductionsUnite();
	//m_batiments["Port"] = new ProductionsUnite();
	//m_batiments["Caserne"] = new ProductionsUnite(0, 0, "Puit à pétrole", "Batiment qui produit du pétrole", 10, 10, 10, 10, manager->getRef("Soldat"), NULL);
}

vector<Batiment*> BatimentManager::getBatimentConstructible() {
	std::vector<Batiment*> listBatiments;
	for (map<std::string, Batiment*>::iterator it = m_batiments.begin(); it != m_batiments.end(); ++it)
	{
		listBatiments.push_back(it->second);
	}

	return listBatiments;
}

void BatimentManager::addBatiment(const std::string& name, Batiment batiment)
{
	m_batiments[name] = &batiment;
}

Batiment* BatimentManager::getRef(const std::string& batiment)
{
	return m_batiments.at(batiment);
}

Batiment* BatimentManager::creerBatiment(const std::string &unite, int x, int y)
{
	Batiment* nouveauBatiment;
	if (getRef(unite)->isProductionRessource()) 
	{
		nouveauBatiment = new ProductionRessource(*(ProductionRessource*)getRef(unite));
	}
	else if (getRef(unite)->isProductionUnite())
	{
		nouveauBatiment = new ProductionsUnite(*(ProductionsUnite*)getRef(unite));
	}
	else 
	{
		nouveauBatiment = new Batiment(*getRef(unite));
	}

	nouveauBatiment->setCoord(x, y);
	return nouveauBatiment;
}