#pragma once
#include"combovertical.h"


ComboVertical::ComboVertical() {};
ComboVertical::ComboVertical(const Boite & boite_un, const Boite & boite_deux)
{

};

unique_ptr<TypeBoite> ComboVertical::cloner() const
{
	return unique_ptr<TypeBoite>{new ComboVertical};
};

std::unique_ptr<Iterateur_Boite<string>> ComboVertical::enumerateur()
{
	return std::make_unique<Iterateur_ComboVertical>(this->lignes);
};
