#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combohorizontal.h"

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

ComboHorizontal::ComboHorizontal() {};
//ComboHorizontal(Boite boite1, Boite boite2) {};

unique_ptr<TypeBoite> ComboHorizontal::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboHorizontal};
}

std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur() const
{
	return std::make_unique<Iterateur_ComboHorizontal>(this->lignes);
};