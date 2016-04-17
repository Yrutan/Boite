#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combovertical.h"



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


ComboVertical::ComboVertical() {};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{

};

unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur() const
{
	return std::make_unique<Iterateur_ComboVertical>(this->lignes_boite_un);
};
