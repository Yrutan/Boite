#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combohorizontal.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	std::vector<string> liste;
	std::vector<string> boite_un;
	std::vector<string> boite_deux;
	std::vector<string>::const_iterator courant_boite_un, fin_boite_un,
		courant_boite_deux, fin_boite_deux;
	bool debut;
	int largeur_boite_un, largeur_boite_deux, hauteur_boite;
public:
	Iterateur_ComboHorizontal(const std::vector<string> &liste)
		:liste{ liste }, debut{ true }, largeur_boite_un{ 0 },
		largeur_boite_deux{ 0 }, hauteur_boite{ 0 }
	{
		bool separateur = false;
		auto it = liste.begin();
		for (; it != liste.end() && !separateur; ++it, ++hauteur_boite)
		{
			if (*it != "\n\n")
			{
				boite_un.push_back(*it);
				if (it->length() > largeur_boite_un)
				{
					largeur_boite_un = it->length();
				}
			}
			else
			{
				separateur = true;
				//++it; // pour passer par-dessus la ligne qui sépare les deux boites.
			}
		}
		int hauteur_boite_deux = 0;
		for (; it != liste.end() && !separateur; ++it, ++hauteur_boite_deux)
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
			if (boite_un_has_next())
			{
				++courant_boite_un;
			}
			if (boite_deux_has_next())
			{
				++courant_boite_deux;
			}
		}
		debut = {};
	};
};


ComboHorizontal::ComboHorizontal(Boite boite1, Boite boite2)
{

};

unique_ptr<TypeBoite> ComboHorizontal::cloner() const
{
	return unique_ptr<TypeBoite>{
		new ComboHorizontal( Boite( getTexteBoiteUn() ), Boite( getTexteBoiteDeux() ) )
	};
}

std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur() const
{
	std::vector<string> texte;

	for each (string ligne in lignes_boite_un)
	{
		texte.push_back(ligne);
	}
	// les vecteurs contiennent seulement des lignes sans "\n"
	// "\n\n" est utilisé comme séparateur entre les lignes des deux boites.
	texte.push_back("\n\n");
	for each (string ligne in lignes_boite_deux)
	{
		texte.push_back(ligne);
	}
	return std::make_unique<Iterateur_ComboHorizontal>(texte);
};

string ComboHorizontal::getTexte() const
{
	return "";
}

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