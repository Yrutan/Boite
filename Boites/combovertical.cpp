#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combovertical.h"

struct Iterateur_ComboVertical : Iterateur_Boite<string>
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
	Iterateur_ComboVertical(const std::vector<string> &liste) 
		:liste{liste}, debut{ true }
	{
		bool separateur = false;
		for each (string ligne in liste)
		{
			if (ligne != "\n\n")
			{
				if (!separateur)
				{
					boite_un.push_back(ligne);
				}
				else
				{
					boite_deux.push_back(ligne);
				}
			}
			else
			{
				separateur = true;
			}
		}
		courant_boite_un = boite_un.begin();
		fin_boite_un = boite_un.end();
		courant_boite_deux = boite_deux.begin();
		fin_boite_deux = boite_deux.end();
	};
	string terminerLigne(const int& nb_espace_manquant) const
	{ return std::string(nb_espace_manquant, ' '); };

	string current() const 
	{ 
		string sortie = "";

		if (courant_boite_un != fin_boite_un)
		{
			sortie += *courant_boite_un;
		}
		else
		{
			sortie += terminerLigne(largeur_boite_un);
		}
		if (courant_boite_deux != fin_boite_deux)
		{
			sortie += *courant_boite_deux;
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



ComboVertical::ComboVertical() {};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{
	this->hauteur = 0;
	this->largeur = 0;
	extraireLignes(lignes_boite_un, boite_un.getTexte());
	extraireLignes(lignes_boite_deux, boite_deux.getTexte());

	redimensionner();
};

unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur() const
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
	return std::make_unique<Iterateur_ComboVertical>(texte);
};

string ComboVertical::getTexte() const
{
	string texte = "";
	for (auto it = lignes_boite_un.begin(); it != lignes_boite_un.end(); ++it)
	{
		texte += texte + "\n";
	}
	return texte;
}

string ComboVertical::getTexteBoiteUn() const
{
	string texte = "";
	for (auto it = lignes_boite_un.begin(); it != lignes_boite_un.end(); ++it)
	{
		texte += texte + "\n";
	}
	return texte;
}
string ComboVertical::getTexteBoiteDeux() const
{
	string texte = "";
	for (auto it = lignes_boite_deux.begin(); it != lignes_boite_deux.end(); ++it)
	{
		texte += texte + "\n";
	}
	return texte;
}