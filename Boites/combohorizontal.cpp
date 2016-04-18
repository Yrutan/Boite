#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combohorizontal.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	std::vector<string> boite_un;
	std::vector<string> boite_deux;
	std::vector<string>::const_iterator courant_boite_un, fin_boite_un,
		courant_boite_deux, fin_boite_deux;
	bool debut;
	int largeur_boite_un, largeur_boite_deux, hauteur_boite;
public:
	Iterateur_ComboHorizontal(const std::vector<string> &liste_un, const std::vector<string> &liste_deux)
		: debut{ true }, largeur_boite_un{ 0 }, largeur_boite_deux{0}, hauteur_boite {0}
	{
		for (auto it = liste_un.begin(); it != liste_un.end(); ++it, ++hauteur_boite)
		{
			boite_un.push_back(*it);
			if (it->length() > largeur_boite_un)
			{
				largeur_boite_un = it->length();
			}
		}
		int hauteur_boite_deux = 0;
		for (auto it = liste_deux.begin(); it != liste_deux.end(); ++it, ++hauteur_boite_deux)
		{
			boite_deux.push_back(*it);
			if (it->length() > largeur_boite_deux)
			{
				largeur_boite_deux = it->length();
			}
		}
		if (hauteur_boite_deux > hauteur_boite)
		{
			hauteur_boite = hauteur_boite_deux;
		}
		courant_boite_un = boite_un.begin();
		fin_boite_un = boite_un.end();
		courant_boite_deux = boite_deux.begin();
		fin_boite_deux = boite_deux.end();
	};
	string terminerLigne(const int& nb_espace_manquant) const
	{
		return std::string(nb_espace_manquant, ' ');
	};

	string current() const
	{
		string sortie = "";

		if (courant_boite_un != fin_boite_un)
		{
			sortie += *courant_boite_un;
			if (courant_boite_un->length() < largeur_boite_un)
			{
				sortie += terminerLigne(largeur_boite_un - courant_boite_un->length());
			}
		}
		else
		{
			sortie += terminerLigne(largeur_boite_un);
		}
		sortie += "|";
		if (courant_boite_deux != fin_boite_deux)
		{
			sortie += *courant_boite_deux;
			if (courant_boite_deux->length() < largeur_boite_deux)
			{
				sortie += terminerLigne(largeur_boite_deux - courant_boite_deux->length());
			}
		}
		else
		{
			sortie += terminerLigne(largeur_boite_deux);
		}
		return sortie;
	};
	bool has_next() const
	{
		return boite_un_has_next() || boite_deux_has_next();
	};
	bool boite_un_has_next() const
	{
		return courant_boite_un != fin_boite_un && std::next(courant_boite_un) != fin_boite_un;
	};
	bool boite_deux_has_next() const
	{
		return courant_boite_deux != fin_boite_deux && std::next(courant_boite_deux) != fin_boite_deux;
	};
	void next()
	{
		if (!debut)
		{
			if (boite_un_has_next() || courant_boite_un != fin_boite_un)
			{
				++courant_boite_un;
			}
			if (boite_deux_has_next() || courant_boite_deux != fin_boite_deux)
			{
				++courant_boite_deux;
			}
		}
		debut = {};
	};
};


ComboHorizontal::ComboHorizontal(const Boite & boite_un, const Boite & boite_deux)
{
	this->hauteur = 0;
	this->largeur = 0;
	texte_origine_boite_un = boite_un.getTexte();
	extraireLignes(lignes_boite_un, boite_un.getTexte());

	texte_origine_boite_deux = boite_deux.getTexte();
	extraireLignes(lignes_boite_deux, boite_deux.getTexte());

	redimensionner();
};

unique_ptr<TypeBoite> ComboHorizontal::cloner() const
{
	return unique_ptr<TypeBoite>{
		new ComboHorizontal( Boite( getTexteBoiteUn() ), Boite( getTexteBoiteDeux() ) )
	};
}

std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur() const
{
	return std::make_unique<Iterateur_ComboHorizontal>(lignes_boite_un, lignes_boite_deux);
};

void ComboHorizontal::redimensionner()
{
	hauteur = 0;
	largeur = 0;
	largeur_boite_un = 0;
	largeur_boite_deux = 0;
	for each (string ligne in this->lignes_boite_un)
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

string ComboHorizontal::getTexte() const
{
	return "";
}

string ComboHorizontal::getTexteBoiteUn() const
{
	return texte_origine_boite_un;
}
string ComboHorizontal::getTexteBoiteDeux() const
{
	return texte_origine_boite_deux;
}