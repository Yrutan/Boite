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

	std::unique_ptr<TypeBoite> boite_gauche;
	std::unique_ptr<TypeBoite> boite_droite;

public:
	ComboHorizontal();
	ComboHorizontal(const Boite & boite_un, const Boite & boite_deux);
	ComboHorizontal(std::unique_ptr<TypeBoite>& boite_un, std::unique_ptr<TypeBoite>& boite_deux);
	unique_ptr<TypeBoite> cloner() const;
	std::unique_ptr<Iterateur_Boite<string>> enumerateur() const;

	void redimensionner();

	const vector<string> ComboHorizontal::getLignes() const;
};



#endif