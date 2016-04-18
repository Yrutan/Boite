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

TypeBoite::TypeBoite() :texte_origine_boite_un{ "" }{ redimensionner(); };
TypeBoite::TypeBoite(string texte) :texte_origine_boite_un{texte}
{
	this->hauteur = 0;
	this->largeur = 0;
	extraireLignes(lignes_boite_un, texte);
	redimensionner();
};

void TypeBoite::redimensionner()
{
	hauteur = 0;
	largeur = 0;
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
	return texte_origine_boite_un;
}

string TypeBoite::getTexte() const
{
	return texte_origine_boite_un;
}