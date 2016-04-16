#ifndef COMBOHORIZONTAL_H
#define COMBOHORIZONTAL_H

#include"typeboite.h"
#include"boite.h"



class ComboHorizontal : TypeBoite
{
	//std::vector<string> lignes;

public:
	ComboHorizontal();
	//ComboHorizontal(Boite boite1, Boite boite2) {};

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur() const;

};



#endif