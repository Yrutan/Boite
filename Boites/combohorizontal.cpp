#pragma once
#include"typeboite.h"
#include"uneboite.h"
#include"boite.h"
#include"combohorizontal.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	unique_ptr<Iterateur_Boite<string>> boite_gauche, boite_droite;
	bool debut;
	int largeur_boite_gauche, largeur_boite_droite, hauteur_boite;
public:
	Iterateur_ComboHorizontal(const std::unique_ptr<TypeBoite>& boite_gauche, const std::unique_ptr<TypeBoite>& boite_droite)
		: debut{ true }, largeur_boite_gauche{ boite_gauche->getLargeur() }, largeur_boite_droite{ boite_droite->getLargeur() }
	{
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
		if (boite_gauche->has_next())
		{
			sortie += boite_gauche->current();
		}
		else
		{
			sortie += std::string(largeur_boite_gauche,' ');
		}
		sortie += "|";
		if (boite_droite->has_next())
		{
			sortie += boite_droite->current();
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
		if (!debut)
		{
			if (boite_gauche->has_next())
			{
				boite_gauche->next();
			}
			if (boite_droite->has_next())
			{
				boite_droite->next();
			}
		}
		debut = {};
	};
};
ComboHorizontal::ComboHorizontal() :boite_gauche{ UneBoite().cloner() }, boite_droite{ UneBoite().cloner() } { redimensionner(); };

ComboHorizontal::ComboHorizontal(const Boite & boite_un, const Boite & boite_deux) 
{
	boite_gauche = boite_un.cloner();
	boite_droite = boite_deux.cloner();

	for each (string ligne in boite_un.getLignes())
	{
		lignes_boite.push_back(ligne);
	}
	for each (string ligne in boite_deux.getLignes())
	{
		lignes_boite_deux.push_back(ligne);
	}
	redimensionner();
};
ComboHorizontal::ComboHorizontal(std::unique_ptr<TypeBoite>& boite_un, 
	std::unique_ptr<TypeBoite>& boite_deux)
{
	boite_gauche = std::move(boite_un);
	boite_droite = std::move(boite_deux);

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
	largeur_boite_un = 0;
	largeur_boite_deux = 0;
	for each (string ligne in this->lignes_boite)
	{
		if (ligne.length() > largeur_boite_un)
		{
			largeur_boite_un = ligne.length();
		}
		++hauteur;
	}
	int hauteur_boite_deux = 0; 
	for each (string ligne in this->lignes_boite_deux)
	{
		if (ligne.length() > largeur_boite_deux)
		{
			largeur_boite_deux = ligne.length();
		}
		++hauteur_boite_deux;
	}
	// compare laquelle des deux boites a la plus grande hauteur
	if (hauteur_boite_deux > hauteur)
	{
		hauteur = hauteur_boite_deux;
	}
	largeur = largeur_boite_un + largeur_boite_deux + 1;// +1 pour la séparation entre les deux boites
}

const vector<string> ComboHorizontal::getLignes() const
{
	vector<string> lignes;

	unique_ptr<Iterateur_Boite<string>> iterateur = enumerateur();

	while (iterateur->has_next())
	{
		iterateur->next();
		lignes.push_back(iterateur->current());
	}
	return lignes;
}
