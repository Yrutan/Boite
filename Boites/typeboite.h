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
<<<<<<< HEAD
	std::vector<string> lignes_boite;
=======
	std::vector<string> lignes_boite_un;

>>>>>>> parent of 02e3f6f... save point
	void TypeBoite::extraireLignes(vector<string>& lignes, string texte);

public:
	TypeBoite();
	TypeBoite(string texte);
	TypeBoite(const vector<string>& lignes);

	virtual unique_ptr<TypeBoite> cloner() const = 0;

	virtual std::unique_ptr<Iterateur_Boite<string>> enumerateur() const = 0;

	void redimensionner();

	int getHauteur() const;
	int getLargeur() const;
	virtual const vector<string> getLignes() const;
};

#endif