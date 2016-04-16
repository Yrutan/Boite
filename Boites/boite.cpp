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


string Boite::toString() const
{
	int largeur = getLargeur();
	string texte = "+";
	for (int i = 0; i < largeur; i++) { texte += "-"; }
	texte += "+\n";

	//contenu de la boite

	unique_ptr<Iterateur_Boite<string>> iterateur = enumerateur();

	while (iterateur->has_next())
	{
		iterateur->next();
		texte += "|" + iterateur->current();
		int largeur_ligne = iterateur->current().length();
		if (largeur_ligne < getLargeur())
		{
			for (int i = largeur_ligne; i < getLargeur(); i++)
			{
				texte += " ";
			}
		}
		texte += "|\n";
	}

	// fin du contenu de la boite

	texte += "+";
	for (int i = 0; i < largeur; i++) { texte += "-"; }
	texte += "+\n";
	return texte;
}

const std::ostream& operator<<(std::ostream& os, const Boite& bt)
{
	os << bt.toString();
	return os;
};

/*
const ostream& operator<<(ostream& os, const Boite& bt)
{
	int largeur = bt.getLargeur();
	os << "+";
	for (int i = 0; i < largeur; i++) { os << "-"; }
	os << "+" << endl;

	//contenu de la boite

	unique_ptr<Iterateur_Boite<string>> iterateur = bt.enumerateur();

	while (iterateur->has_next())
	{
		iterateur->next();
		os << "|" << iterateur->current();
		int largeur_ligne = iterateur->current().length();
		if (largeur_ligne < bt.getLargeur())
		{
			for (int i = largeur_ligne; i < bt.getLargeur(); i++)
			{
				os << " ";
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
*/