#ifndef COMBOVERTICAL_H
#define COMBOVERTICAL_H

#include"typeboite.h"
#include"boite.h"



class ComboVertical : TypeBoite
{
private:
	unique_ptr<TypeBoite> deuxieme_boite;
public:
	ComboVertical();
	ComboVertical(const Boite & boite_un, const Boite & boite_deux);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()const;

	string getTexteBoiteUn() const;
	string getTexteBoiteDeux() const;

};


#endif