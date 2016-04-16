#pragma once
#include"typeboite.h"
#include"combohorizontal.h"
#include"boite.h"


	ComboHorizontal::ComboHorizontal() {};
	//ComboHorizontal(Boite boite1, Boite boite2) {};

	unique_ptr<TypeBoite> ComboHorizontal::cloner() const
	{
		return unique_ptr<TypeBoite>{new ComboHorizontal};
	}

	std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur()
	{
		return std::make_unique<Iterateur_ComboHorizontal>(this->lignes);
	};