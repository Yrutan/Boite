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
		: debut_boite_haut{ true }, debut_boite_bas{true}, 
		fin_boite_haut{ false }, separateur_boite{false},
		hauteur_boite_haut{boite_haut->getHauteur()}, hauteur_boite_bas{ boite_bas->getHauteur() }
	{
		largeur_boite = boite_haut->getLargeur();
		if (largeur_boite < boite_bas->getLargeur())
		{
			largeur_boite = boite_bas->getLargeur();
		}
	};
	string current() const 
	{ 
		string sortie = "";
		if (boite_haut->has_next())
		{
			sortie += boite_haut->current();
			if (sortie.length() < largeur_boite)
			{
				sortie += std::string(largeur_boite - sortie.length(),' ');
			}
		}
		else if (fin_boite_haut && !separateur_boite)
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
	bool has_next() const { return boite_haut->has_next() || boite_bas->has_next();};
	void next() 
	{ 
		if (!debut_boite_haut)
		{
			if (boite_haut->has_next())
			{
				boite_haut->next();
			}
			else if (!fin_boite_haut) //1. fin de la premi�re boite, envoyer le s�parateur
			{
				// atteint la fin de la boite du haut
				fin_boite_haut = true;
			}
			else if(!separateur_boite)//2. s�parateur d�j� envoy�, commencer la deuxi�me boite
			{
				// la ligne entre la boite du haut et la boite du bas a �t� envoy�e
				separateur_boite = true;
			}
			else // 3. on a d�j� envoy� la premi�re ligne de la deuxi�me boite
			{
				if (boite_bas->has_next())
				{
					boite_bas->next();
				}
				debut_boite_bas = {};
			}
			debut_boite_haut = {};
		}
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
	hauteur = 0;
	largeur = 0;
	for each (string ligne in this->lignes_boite)
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
	lignes.insert(lignes.end(), lignes_boite.begin(), lignes_boite.end());
	lignes.push_back(std::string(largeur, '-'));
	lignes.insert(lignes.end(), lignes_boite_deux.begin(), lignes_boite_deux.end());
	return lignes;
}
