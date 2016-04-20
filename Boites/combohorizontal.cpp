#pragma once
#include"typeboite.h"
#include"uneboite.h"
#include"boite.h"
#include"combohorizontal.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	unique_ptr<Iterateur_Boite<string>> boite_gauche, boite_droite;
	bool fin_boite_gauche, fin_boite_droite;
	int largeur_boite_gauche, largeur_boite_droite, hauteur_boite;
public:
	Iterateur_ComboHorizontal(const std::unique_ptr<TypeBoite>& boite_gauche, const std::unique_ptr<TypeBoite>& boite_droite)
		: largeur_boite_gauche{ boite_gauche->getLargeur() }, largeur_boite_droite{ boite_droite->getLargeur() }
	{
		fin_boite_gauche = false;
		fin_boite_droite = false;
		hauteur_boite = boite_gauche->getHauteur();
		if (hauteur_boite < boite_droite->getHauteur())
		{
			hauteur_boite = boite_droite->getHauteur();
		}
		this->boite_gauche  = std::move(boite_gauche->enumerateur());
		this->boite_droite = std::move(boite_droite->enumerateur());
	};
	string terminerLigne(const int& nb_espace_manquant) const
	{
		return std::string(nb_espace_manquant, ' ');
	};

	string current() const
	{
		string sortie = "";
		if (!fin_boite_gauche)
		{
			sortie += boite_gauche->current();
			if (sortie.length() < largeur_boite_gauche)
			{
				sortie += std::string(largeur_boite_gauche - sortie.length(), ' ');
			}
		}
		else
		{
			sortie += std::string(largeur_boite_gauche,' ');
		}
		sortie += "|";
		if (!fin_boite_droite)
		{
			sortie += boite_droite->current();
			if (boite_droite->current().length() < largeur_boite_droite)
			{
				sortie += std::string(largeur_boite_droite - boite_droite->current().length(), ' ');
			}
		}
		else
		{
			sortie += std::string(largeur_boite_droite, ' ');
		}
		return sortie;
	};
	bool has_next() const
	{
		return boite_gauche->has_next() || boite_droite->has_next();
	};
	void next()
	{
		if (boite_gauche->has_next())
		{
			boite_gauche->next();
		}
		else
		{
			fin_boite_gauche = true;
		}
		if (boite_droite->has_next())
		{
			boite_droite->next();
		}
		else
		{
			fin_boite_droite = true;
		}
	};
};
ComboHorizontal::ComboHorizontal() :boite_gauche{ UneBoite().cloner() }, boite_droite{ UneBoite().cloner() } { redimensionner(); };

ComboHorizontal::ComboHorizontal(const Boite & boite_un, const Boite & boite_deux) 
{
<<<<<<< HEAD
	boite_gauche = boite_un.obtenir_clone();
	boite_droite = boite_deux.obtenir_clone();
	redimensionner();
};
ComboHorizontal::ComboHorizontal(std::unique_ptr<TypeBoite>& boite_un, 
	std::unique_ptr<TypeBoite>& boite_deux)
{
	boite_gauche = std::move(boite_un);
	boite_droite = std::move(boite_deux);
=======
	this->hauteur = 0;
	this->largeur = 0;
	extraireLignes(lignes_boite_un, boite_un.getTexte());
	extraireLignes(lignes_boite_deux, boite_deux.getTexte());

>>>>>>> parent of 02e3f6f... save point
	redimensionner();
};

unique_ptr<TypeBoite> ComboHorizontal::cloner() const
{
	return unique_ptr<TypeBoite>{
		new ComboHorizontal(boite_gauche->cloner(), boite_droite->cloner())
	};
}

std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur() const
{
	return std::make_unique<Iterateur_ComboHorizontal>(boite_gauche, boite_droite);
};

void ComboHorizontal::redimensionner()
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
		hauteur++;
	}
}


<<<<<<< HEAD
=======
string ComboHorizontal::getTexteBoiteUn() const
{
	string texte = "";
	for (auto it = lignes_boite_un.begin(); it != lignes_boite_un.end(); ++it)
	{
		texte += *it + "\n";
	}
	return texte;
}
string ComboHorizontal::getTexteBoiteDeux() const
{
	string texte = "";
	for (auto it = lignes_boite_deux.begin(); it != lignes_boite_deux.end(); ++it)
	{
		texte += *it + "\n";
	}
	return texte;
}
>>>>>>> parent of 02e3f6f... save point
