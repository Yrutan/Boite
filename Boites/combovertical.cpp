#pragma once
#include"typeboite.h"
#include"uneboite.h"
#include"boite.h"
#include"combovertical.h"

struct Iterateur_ComboVertical : Iterateur_Boite<string>
{
private:
	unique_ptr<Iterateur_Boite<string>> boite_haut, boite_bas;
	bool debut_boite_haut, debut_boite_bas, fin_boite_haut, separateur_boite;
	int largeur_boite, hauteur_boite_haut, hauteur_boite_bas;
public:
	Iterateur_ComboVertical(const std::unique_ptr<TypeBoite>& boite_haut, const std::unique_ptr<TypeBoite>& boite_bas)
		: boite_haut{ boite_haut->enumerateur() }, boite_bas{boite_bas->enumerateur()}, 
		debut_boite_haut{true}, debut_boite_bas{ true },
		fin_boite_haut{ false }, separateur_boite{false},
		hauteur_boite_haut{boite_haut->getHauteur()}, hauteur_boite_bas{ boite_bas->getHauteur() }
	{
		largeur_boite = boite_haut->getLargeur();
		if (largeur_boite < boite_bas->getLargeur())
		{
			largeur_boite = boite_bas->getLargeur();
		}
		this->boite_haut = std::move(boite_haut->enumerateur());
		this->boite_bas = std::move(boite_bas->enumerateur());
	};
	string current() const 
	{ 
		string sortie = "";
		if (boite_haut->has_next() && !fin_boite_haut)
		{
			sortie += boite_haut->current();
			if (sortie.length() < largeur_boite)
			{
				sortie += std::string(largeur_boite - sortie.length(),' ');
			}
		}
		else if (fin_boite_haut && !separateur_boite)// si le séparateur n'a pas encore passé
		{
			sortie += std::string(largeur_boite, '-');
		}
		else
		{
			if (boite_bas->has_next())
			{
				sortie += boite_bas->current();
				if (sortie.length() < largeur_boite)
				{
					sortie += std::string(largeur_boite - sortie.length(), ' ');
				}
			}
		}
		return sortie;
	};
	bool has_next() const 
	{ 
		return boite_haut->has_next() || boite_bas->has_next();
	};
	void next() 
	{ 
		if (!debut_boite_haut)
		{
			if (boite_haut->has_next())
			{
				boite_haut->next();
			}
			else if (!fin_boite_haut) //1. fin de la première boite, envoyer le séparateur
			{
				// atteint la fin de la boite du haut
				fin_boite_haut = true;
			}
			else if(!separateur_boite)//2. séparateur déjà envoyé, commencer la deuxième boite
			{
				// la ligne entre la boite du haut et la boite du bas a été envoyée
				separateur_boite = true;
				debut_boite_bas = {};// 2. la première ligne de la deuxième boite va être envoyé
			}
			else // 3. on a déjà envoyé la première ligne de la deuxième boite
			{
				if (boite_bas->has_next())
				{
					boite_bas->next();
				}
			}
		}
		debut_boite_haut = {};
	};
};

ComboVertical::ComboVertical() :boite_duhaut{UneBoite().cloner()},boite_dubas{ UneBoite().cloner()} 
{
	redimensionner();
};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{
	boite_duhaut = boite_un.cloner();
	boite_dubas = boite_deux.cloner();
	this->redimensionner();
};
ComboVertical::ComboVertical(std::unique_ptr<TypeBoite>& boite_un, std::unique_ptr<TypeBoite>& boite_deux)
{
	boite_duhaut = std::move(boite_un);
	boite_dubas = std::move(boite_deux);
	redimensionner();
}


unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical(
		boite_duhaut->cloner(), 
		boite_dubas->cloner() )};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur() const
{
	return std::make_unique<Iterateur_ComboVertical>(boite_duhaut, boite_dubas);
};

void ComboVertical::redimensionner()
{
	hauteur = boite_duhaut->getHauteur() + boite_dubas->getHauteur();
	largeur = boite_duhaut->getLargeur();
	if (largeur < boite_dubas->getLargeur())
	{
		largeur = boite_dubas->getLargeur();
	}
}

const vector<string> ComboVertical::getLignes() const
{
	vector<string> lignes;
	lignes.insert(lignes.end(), boite_duhaut->getLignes().begin(), boite_duhaut->getLignes().end());
	//lignes.push_back(std::string(largeur, '-'));
	lignes.insert(lignes.end(), boite_dubas->getLignes().begin(), boite_dubas->getLignes().end());
	return lignes;
}
