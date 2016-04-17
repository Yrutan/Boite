#include"typeboite.h"

void TypeBoite::extraireLignes(vector<string>& lignes, string texte)
{
	int index;
	while (texte.length() > 0)
	{
		index = texte.find("\n");
		if (index != string::npos)
		{
			lignes.push_back(texte.substr(0, index));
			texte = texte.substr(index + 1);
		}
		else
		{
			lignes.push_back(texte);
			texte.clear();
		}
	}
}

TypeBoite::TypeBoite() { this->hauteur = 0; this->largeur = 0; };
TypeBoite::TypeBoite(string texte)
{
	this->hauteur = 0;
	this->largeur = 0;
	extraireLignes(lignes_boite_un, texte);
	redimensionner();
};

void TypeBoite::redimensionner()
{
	hauteur = 0;
	for each (string ligne in this->lignes_boite_un)
	{
		if (ligne.length() > getLargeur())
		{
			largeur = ligne.length();
		}
		++hauteur;
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
			for (int i = ligne.length(); i < largeur; ++i)
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