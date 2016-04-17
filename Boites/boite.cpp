#include "typeboite.h"
#include"uneboite.h"
#include"combohorizontal.h"
#include"combovertical.h"
#include"boite.h"

Boite::Boite() :boite{ std::move(new UneBoite()) } {};

Boite::Boite(string texte) :boite{ std::move(new UneBoite(texte)) } {};

Boite::Boite(const TypeBoite& boite) :boite{ std::move(boite.cloner()) } { };

int Boite::getHauteur() const { return boite->getHauteur(); };
int Boite::getLargeur() const { return boite->getLargeur(); };

std::unique_ptr<Iterateur_Boite<string>> Boite::enumerateur() const
{
	return boite->enumerateur();
};


string Boite::getTexte() const
{
	int largeur = getLargeur();
	string texte = "";
	unique_ptr<Iterateur_Boite<string>> iterateur = enumerateur();
	while (iterateur->has_next())
	{
		iterateur->next();
		texte += "|" + iterateur->current();
		int largeur_ligne = iterateur->current().length();
		if (largeur_ligne < getLargeur())
		{
			for (int i = largeur_ligne; i < getLargeur(); ++i)
			{
				texte += " ";
			}
		}
		texte += "|\n";
	}
	return texte;
}

std::ostream& operator<<(std::ostream& os, const Boite& bt)
{
	// cadre du débute de la boite
	os << "+";
	for (int i = 0; i < bt.getLargeur(); ++i) { os << "-"; }
	os << "+\n";
	//début du contenu de la boite
	os << bt.getTexte();
	// fin du contenu de la boite
	// cadre de la fin de la boite
	os << "+";
	for (int i = 0; i < bt.getLargeur(); ++i) { os << "-"; }
	os << "+";

	return os;
};
