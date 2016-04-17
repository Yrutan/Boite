#include"typeboite.h"

TypeBoite::TypeBoite() { largeur = 0; hauteur = 0; };
TypeBoite::TypeBoite(string texte)
	{
		hauteur = 0;
		largeur = 0;
		int index;
		while (texte.length() > 0)
		{
			index = texte.find("\n");
			if (index != string::npos)
			{
				lignes_boite_un.push_back(texte.substr(0, index));
				texte = texte.substr(index + 1);
			}
			else
			{
				lignes_boite_un.push_back(texte.substr(0, texte.size()));
				texte = "";
			}
		}
		redimensionner();
	};

	string TypeBoite::getTexte() const
	{
		string texte = "";
		for each (string ligne in lignes_boite_un)
		{
			texte += ligne + "\n";
		}
		return texte;
	}
	void TypeBoite::redimensionner()
	{
		hauteur = 0;
		for each (string ligne in this->lignes_boite_un)
		{
			if (ligne.length() > this->largeur)
			{
				largeur = ligne.length();
			}
			hauteur++;
		}
	};


	int TypeBoite::getHauteur() const { return this->hauteur; }
	int TypeBoite::getLargeur() const { return this->largeur; }