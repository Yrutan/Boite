#ifndef COMBOHORIZONTAL_H
#define COMBOHORIZONTAL_H

#include"typeboite.h"
#include"boite.h"



class ComboHorizontal : TypeBoite
{
protected:
	std::vector<string> lignes_boite_deux;

	int largeur_boite_un;
	int largeur_boite_deux;

	Boite boite_gauche;
	Boite boite_droite;

public:
	ComboHorizontal(const Boite & boite_un, const Boite & boite_deux);

	unique_ptr<TypeBoite> cloner() const;
	std::unique_ptr<Iterateur_Boite<string>> enumerateur() const;

	void redimensionner();

	const vector<string> ComboHorizontal::getLignes() const;
};



#endif