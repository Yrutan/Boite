#ifndef BOITE_H
#define BOITE_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class TypeBoite;
class ComboHorizontal;
class ComboVertical;
template <class T>
struct Iterateur_Boite;

class Boite
{
private:
	std::unique_ptr<TypeBoite> boite;
public:
	Boite();
	Boite(string texte);
	Boite(const ComboVertical& cv);
	Boite(const TypeBoite& boite);

	int getHauteur() const;
	int getLargeur() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur() const;

	string getTexte() const;
	friend std::ostream& operator<<(std::ostream& os, const Boite& bt);
};



#endif