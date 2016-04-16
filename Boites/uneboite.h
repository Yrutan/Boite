#pragma once
#include"typeboite.h"

struct Iterateur_UneBoite : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_UneBoite(const std::vector<string> &liste) : courant{ liste.begin() }, fin{ liste.end() }, debut{ true } {};
	string current() const { return *courant; };
	bool has_next() const { return courant != fin && std::next(courant) != fin; };
	void next() { if (!debut) { ++courant; }debut = {}; };
};

class UneBoite : public TypeBoite
{
public:
	UneBoite() {};
	UneBoite(string texte) : TypeBoite(texte) {};

	unique_ptr<TypeBoite> cloner() const
	{
		return unique_ptr<TypeBoite>{new UneBoite};
	};

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()
	{
		return std::make_unique<Iterateur_UneBoite>(this->lignes);
	};

	string toString() const { return this->getTexte(); };

};