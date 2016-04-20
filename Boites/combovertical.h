#ifndef COMBOVERTICAL_H
#define COMBOVERTICAL_H

#include"typeboite.h"
#include"boite.h"



class ComboVertical : TypeBoite
{
protected:
<<<<<<< HEAD
	std::unique_ptr<TypeBoite> boite_duhaut;
	std::unique_ptr<TypeBoite> boite_dubas;

=======
	std::vector<string> lignes_boite_deux;
>>>>>>> parent of 02e3f6f... save point
public:
	ComboVertical();
	ComboVertical(const Boite & boite_un, const Boite & boite_deux);
	ComboVertical(std::unique_ptr<TypeBoite>& boite_un, std::unique_ptr<TypeBoite>& boite_deux);
	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()const;
	
	void redimensionner();
};


#endif