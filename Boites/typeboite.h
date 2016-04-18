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
	string texte_origine_boite_un;
	std::vector<string> lignes_boite_un;

	void TypeBoite::extraireLignes(vector<string>& lignes, string texte);

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