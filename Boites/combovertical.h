#pragma once
#include"typeboite.h"
#include"boite.h"

struct Iterateur_ComboVertical : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_ComboVertical(const std::vector<string> &liste) : courant{ liste.begin() }, fin{ liste.end() }, debut{ true } {};
	string current() const { return *courant; };
	bool has_next() const { return courant != fin && std::next(courant) != fin; };
	void next() { if (!debut) { ++courant; }debut = {}; };
};


class ComboVertical : TypeBoite
{
private:
	unique_ptr<TypeBoite> deuxieme_boite;
public:
	ComboVertical();
	ComboVertical(const Boite & boite_un, const Boite & boite_deux);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur();

};