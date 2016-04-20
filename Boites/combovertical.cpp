#pragma once
#include"typeboite.h"
#include"uneboite.h"
#include"boite.h"
#include"combovertical.h"

struct Iterateur_ComboVertical : Iterateur_Boite<string>
{
private:
	unique_ptr<Iterateur_Boite<string>> boite_haut, boite_bas;
	bool fin_boite_haut, fin_boite_bas, separateur;
	int largeur_boite;
public:
	Iterateur_ComboVertical(const std::unique_ptr<TypeBoite>& boite_un, const std::unique_ptr<TypeBoite>& boite_deux)
	{
		this->boite_haut = std::move(boite_un->enumerateur());
		this->boite_bas = std::move(boite_deux->enumerateur());

		fin_boite_haut = false;
		fin_boite_bas = false;
		separateur = false;

		largeur_boite = boite_un->getLargeur();
		if (largeur_boite < boite_deux->getLargeur())
		{
			largeur_boite = boite_deux->getLargeur();
		}
	};
	string current() const 
	{ 
		string sortie = "";
		if (!fin_boite_haut)
		{
			sortie += boite_haut->current();
			if (sortie.length() < largeur_boite)
			{
				sortie += std::string(largeur_boite - sortie.length(), ' ');
			}
		}
		else
		{
			if (fin_boite_haut && !separateur)
			{
				sortie += std::string(largeur_boite, '-');
			}
			else if (!fin_boite_bas)
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
		return (boite_haut->has_next() || boite_bas->has_next());
	};
	void next()
	{
		if (boite_haut->has_next())
		{
			boite_haut->next();
		}
		else if(!fin_boite_haut)
		{
			fin_boite_haut = true;//1. va afficher le separateur
		}
		else
		{
			if (!separateur)
			{
				//2. separateur affiché, le "désactiver"
				// et commencer la deuxième boite
				separateur = true;
			}
			if (boite_bas->has_next())
			{
				boite_bas->next();
			}
			else
			{
				fin_boite_bas = false;
			}
		}
	}
};

<<<<<<< HEAD
ComboVertical::ComboVertical() :boite_duhaut{UneBoite().cloner()},boite_dubas{ UneBoite().cloner()} 
=======
ComboVertical::ComboVertical() {};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
>>>>>>> parent of 02e3f6f... save point
{
	redimensionner();
};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{
	boite_duhaut = std::move(boite_un.obtenir_clone());
	boite_dubas = std::move(boite_deux.obtenir_clone());
	this->redimensionner();
};
ComboVertical::ComboVertical(std::unique_ptr<TypeBoite>& boite_un, std::unique_ptr<TypeBoite>& boite_deux)
{
	boite_duhaut = std::move(boite_un);
	boite_dubas = std::move(boite_deux);
	this->redimensionner();
}


unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical(
		boite_duhaut->cloner(), 
		boite_dubas->cloner() )};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur() const
{
<<<<<<< HEAD
	return std::make_unique<Iterateur_ComboVertical>(boite_duhaut, boite_dubas);
=======
	std::vector<string> texte;

	for each (string ligne in lignes_boite_un)
	{
		texte.push_back(ligne);
	}
	texte.push_back("\n");
	for each (string ligne in lignes_boite_deux)
	{
		texte.push_back(ligne);
	}
	return std::make_unique<Iterateur_ComboVertical>(texte);
>>>>>>> parent of 02e3f6f... save point
};

void ComboVertical::redimensionner()
{
	hauteur = 0;
	largeur = 0;
	unique_ptr<Iterateur_Boite<string>> iterateur = enumerateur();
	while (iterateur->has_next())
	{
		iterateur->next();
		if (iterateur->current().length() > largeur)
		{
			this->largeur = iterateur->current().length();
		}
		++hauteur;
	}
}

<<<<<<< HEAD
=======
string ComboVertical::getTexteBoiteUn() const
{
	string texte = "";
	for (auto it = lignes_boite_un.begin(); it != lignes_boite_un.end(); ++it)
	{
		texte += *it + "\n";
	}
	return texte;
}
string ComboVertical::getTexteBoiteDeux() const
{
	string texte = "";
	for (auto it = lignes_boite_deux.begin(); it != lignes_boite_deux.end(); ++it)
	{
		texte += *it + "\n";
	}
	return texte;
}
>>>>>>> parent of 02e3f6f... save point
