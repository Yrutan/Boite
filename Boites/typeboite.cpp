#include"typeboite.h"

TypeBoite::TypeBoite() { this->hauteur = 0; this->largeur = 0; };
TypeBoite::TypeBoite(string texte)
{
	this->hauteur = 0;
	this->largeur = 0;
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
			lignes_boite_un.push_back(texte);
			texte.clear();
		}
	}
	redimensionner();
};

void TypeBoite::redimensionner()
{
	this->hauteur = 0;
	for each (string ligne in this->lignes_boite_un)
	{
		if (ligne.length() > getLargeur())
		{
			this->largeur = ligne.length();
		}
		this->hauteur++;
	}
};

int TypeBoite::getHauteur() const { return this->hauteur; }
int TypeBoite::getLargeur() const { return this->largeur; }

string TypeBoite::getTexteBoiteUn() const 
{
	string texte = "";
	int largeur = getLargeur();
	for each (string ligne in lignes_boite_un)
	{
		texte += ligne;
		if (ligne.length() < largeur)
		{
			for (int i = ligne.length(); i < largeur; i++)
			{
				texte += " ";
			}
		}
		texte += "\n";
	}
	return texte;
}

string TypeBoite::getTexte() const
{
	return getTexteBoiteUn();
}