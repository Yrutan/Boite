#ifndef BOITE
#define BOITE

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

class TypeBoite;
class UneBoite;
class ComboVertical;
class ComboHorizontal;

class Boite
{
	unique_ptr<TypeBoite> boite;

public:

	Boite();
	Boite(string texte);
	Boite(const TypeBoite& boite);

	int getHauteur() const;
	int getLargeur() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur();
};

ostream& operator<<(ostream& os, Boite& bt)
{
	int largeur = bt.getLargeur();
	os << "+";
	for (int i = 0; i < largeur; i++) { os << "-"; }
	os << "+" << endl;

	//contenu de la boite

	unique_ptr<Iterateur_Boite<string>> enumerateur = bt.enumerateur();

	while (enumerateur->has_next())
	{
		enumerateur->next();
		os << "|" << enumerateur->current();
		int largeur_ligne = enumerateur->current().length();
		if (largeur_ligne < bt.getLargeur())
		{
			for (int i = largeur_ligne; i < bt.getLargeur(); i++)
			{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

	// fin du contenu de la boite

	os << "+";
	for (int i = 0; i < largeur; i++) { os << "-"; }
	os << "+" << endl;
	return os;
};
#endif