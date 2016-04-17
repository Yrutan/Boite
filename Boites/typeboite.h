#ifndef TYPEBOITE_H
#define TYPEBOITE_H

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
	std::vector<string> lignes_boite_un;

public:
	TypeBoite();
	TypeBoite(string texte);

	virtual unique_ptr<TypeBoite> cloner() const = 0;

	virtual std::unique_ptr<Iterateur_Boite<string>> enumerateur() const = 0;

	void redimensionner();

	int getHauteur() const;
	int getLargeur() const;
	string getTexte() const;
	string getTexteBoiteUn() const;
};

#endif