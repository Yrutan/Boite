#pragma once
#include"typeboite.h"
#include"boite.h"
#include"combohorizontal.h"

struct Iterateur_ComboHorizontal : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant_liste_un, fin_liste_un,
		courant_liste_deux, fin_liste_deux;
	bool debut;
public:
	Iterateur_ComboHorizontal(const std::vector<string> &liste_un, const std::vector<string> &liste_deux)
		: courant_liste_un{ liste_un.begin() }, fin_liste_un{ liste_un.end() }, 
		courant_liste_deux{ liste_deux.begin() }, fin_liste_deux{ liste_deux.end() }, debut{ true } {};
	string current() const 
	{ 
		
		return *courant_liste_un; 
	};
	bool has_next() const { return courant_liste_un != fin_liste_un && std::next(courant_liste_un) != fin_liste_un; };
	void next() { if (!debut) 
	{ 
		++courant_liste_un; }debut = {}; 
	};
};


ComboHorizontal::ComboHorizontal(Boite boite1, Boite boite2)
{

};

unique_ptr<TypeBoite> ComboHorizontal::cloner() const
{
	return unique_ptr<TypeBoite>{
		new ComboHorizontal( Boite( getTexteBoiteUn() ), Boite( getTexteBoiteDeux() ) )
	};
}

std::unique_ptr<Iterateur_Boite<string>> ComboHorizontal::enumerateur() const
{
	return std::make_unique<Iterateur_ComboHorizontal>(this->lignes_boite_un, this->lignes_boite_deux);
};

string ComboHorizontal::getTexte() const
{
	return "";
}

string ComboHorizontal::getTexteBoiteUn() const
{
	string texte = "";
	for (auto it = lignes_boite_un.begin(); it != lignes_boite_un.end(); it++)
	{
		texte += texte + "\n";
	}
	return texte;
}
string ComboHorizontal::getTexteBoiteDeux() const
{
	string texte = "";
	for (auto it = lignes_boite_deux.begin(); it != lignes_boite_deux.end(); it++)
	{
		texte += texte + "\n";
	}
	return texte;
}