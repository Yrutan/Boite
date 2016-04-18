#ifndef COMBOHORIZONTAL_H
#define COMBOHORIZONTAL_H

#include"typeboite.h"
#include"boite.h"



class ComboHorizontal : TypeBoite
{
protected:
	string texte_origine_boite_deux;
	std::vector<string> lignes_boite_deux;

	int largeur_boite_un;
	int largeur_boite_deux;

public:
	ComboHorizontal(const Boite & boite_un, const Boite & boite_deux);

	unique_ptr<TypeBoite> cloner() const;
	std::unique_ptr<Iterateur_Boite<string>> enumerateur() const;

	void redimensionner();

	string getTexte() const;
	string getTexteBoiteUn() const;
	string getTexteBoiteDeux() const;


};



#endif