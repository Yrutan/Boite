#include"typeboite.h"

void TypeBoite::extraireLignes(vector<string>& lignes, string texte)
{
	int index;
	while (texte.length() > 0)
	{
		index = texte.find('\n');
		if (index != string::npos)
		{
			lignes.push_back(texte.substr(0, index));
			texte = texte.substr(index + 1);// +1 pour enlever le '\n'
		}
		else // Lorsqu'il ne reste plus de saut de ligne
		{
			lignes.push_back(texte); // on prend le reste du texte
			texte.clear();// on vide la variable pour sortir de la boucle
		}
	}
}

TypeBoite::TypeBoite() { this->hauteur = 0; this->largeur = 0; };
TypeBoite::TypeBoite(string texte)
{
	this->hauteur = 0;
	this->largeur = 0;
	extraireLignes(this->lignes_boite, texte);
	redimensionner();
};
TypeBoite::TypeBoite(const vector<string>& lignes)
{
	this->hauteur = 0;
	this->largeur = 0;
	for each (string ligne in lignes)
	{
		lignes_boite.push_back(ligne);
	}
	redimensionner();
}

void TypeBoite::redimensionner()
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
};

int TypeBoite::getHauteur() const { return this->hauteur; }
int TypeBoite::getLargeur() const { return this->largeur; }

<<<<<<< HEAD
=======
string TypeBoite::getTexteBoiteUn() const 
{
	string texte = "";
	int largeur = getLargeur();
	for each (string ligne in lignes_boite_un)
	{
		texte += ligne + "\n";
	}
	return texte;
}
>>>>>>> parent of 02e3f6f... save point

const vector<string> TypeBoite::getLignes() const
{
<<<<<<< HEAD
	return lignes_boite;
=======
	return getTexteBoiteUn();
>>>>>>> parent of 02e3f6f... save point
}