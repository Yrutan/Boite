#pragma once
#include"typeboite.h"
#include"uneboite.h"
#include"boite.h"
#include"combovertical.h"

struct Iterateur_ComboVertical : Iterateur_Boite<string>
{
private:
	std::vector<string> liste;
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_ComboVertical(const std::vector<string> &liste) 
		: debut{ true } 
	{
		for each (string ligne in liste)
		{
			this->liste.push_back(ligne);
		}
		courant = this->liste.begin();
		fin = this->liste.end();
	};
	string current() const { return *courant; };
	bool has_next() const { return courant != fin && std::next(courant) != fin; };
	void next() { if (!debut) { ++courant; }debut = {}; };
};

ComboVertical::ComboVertical() 
	:boite_duhaut{ std::move(new Boite())},
	boite_dubas{ std::move(new Boite()) } {
	redimensionner();
};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{
	//boite_duhaut = boite_un;
	for each (string ligne in boite_un.getLignes())
	{
		lignes_boite_un.push_back(ligne);
	}
	for each (string ligne in boite_deux.getLignes())
	{
		lignes_boite_deux.push_back(ligne);
	}
	//hauteur = boite_duhaut.hauteur + boite_dubas.hauteur;
	// largeur = largest;
	this->redimensionner();
};

unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical(
		Boite(lignes_boite_un), 
		Boite(lignes_boite_deux)
		)};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur() const
{
	return std::make_unique<Iterateur_ComboHorizontal>(boite_duhaut, boite_dubas);
};

void ComboVertical::redimensionner()
{
	hauteur = 0;
	largeur = 0;
	for each (string ligne in this->lignes_boite_un)
	{
		if (ligne.length() > getLargeur())
		{
			largeur = ligne.length();
		}
		++hauteur;
	}
	int largeur_boite_deux = 0;
	for each (string ligne in this->lignes_boite_deux)
	{
		if (ligne.length() > getLargeur())
		{
			largeur = ligne.length();
		}
		++hauteur;
	}
	if (largeur_boite_deux > largeur)
	{
		largeur = largeur_boite_deux;
	}
}

const vector<string> ComboVertical::getLignes() const
{
	vector<string> lignes;
	// peut-être comme horizontal ? -
	lignes.insert(lignes.end(), lignes_boite_un.begin(), lignes_boite_un.end());
	lignes.push_back(std::string(largeur, '-'));
	lignes.insert(lignes.end(), lignes_boite_deux.begin(), lignes_boite_deux.end());
	return lignes;
}
