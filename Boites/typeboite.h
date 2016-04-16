

#ifndef TYPEBOITE
#define TYPEBOITE

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
using namespace std;

template <class T>
struct Iterateur_Boite
{
public:
	virtual string current() const = 0;
	virtual bool has_next() const = 0;
	virtual void next() = 0;
	virtual ~Iterateur_Boite() = default;
};

class TypeBoite
{
protected:
	int hauteur;
	int largeur;

	std::vector<string> lignes;

	

public:
	TypeBoite() { largeur = 0; hauteur = 0; };
	TypeBoite(string texte)
	{
		hauteur = 0;
		largeur = 0;
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
				lignes.push_back(texte.substr(0, texte.size()));
				texte = "";
			}
		}
		redimensionner();
	};

	string getTexte() const
	{
		string texte = "";
		for each (string ligne in lignes)
		{
			texte += ligne + "\n";
		}
		return texte;
	}

	virtual unique_ptr<TypeBoite> cloner() const = 0;

	virtual std::unique_ptr<Iterateur_Boite<string>> enumerateur() = 0;


	void redimensionner()
	{
		hauteur = 0;
		for each (string ligne in this->lignes)
		{
			if (ligne.length() > this->largeur)
			{
				largeur = ligne.length();
			}
			hauteur++;
		}
	};


	int getHauteur() const { return this->hauteur; }
	int getLargeur() const { return this->largeur; }

};

#endif