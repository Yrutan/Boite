#ifndef COMBOVERTICAL_H
#define COMBOVERTICAL_H

#include"typeboite.h"
#include"boite.h"



class ComboVertical : TypeBoite
{
protected:
	std::vector<string> lignes_boite_deux;

	std::unique_ptr<Boite> boite_duhaut;
	std::unique_ptr<Boite> boite_dubas;

public:
	ComboVertical();
	ComboVertical(const Boite & boite_un, const Boite & boite_deux);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()const;
	
	void redimensionner();
	const vector<string> ComboVertical::getLignes() const;
};


#endif