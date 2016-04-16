#pragma once
#include"typeboite.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_ComboHorizontal(const std::vector<string> &liste) : courant{ liste.begin() }, fin{ liste.end() }, debut{ true } {};
	string current() const { return *courant; };
	bool has_next() const { return courant != fin && std::next(courant) != fin; };
	void next() { if (!debut) { ++courant; }debut = {}; };
};

class ComboHorizontal : TypeBoite
{
	//std::vector<string> lignes;

public:
	ComboHorizontal();
	//ComboHorizontal(Boite boite1, Boite boite2) {};

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur();

};