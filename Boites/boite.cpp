#include "typeboite.h"
#include"uneboite.h"
#include"combohorizontal.h"
#include"combovertical.h"
#include"boite.h"

Boite::Boite() :boite{ std::move(new UneBoite()) } {};

Boite::Boite(string texte) :boite{ std::move(new UneBoite(texte)) } {};
Boite::Boite(const vector<string>& lignes) :boite{ std::move(new UneBoite(lignes)) } {};

Boite::Boite(const ComboVertical& cv) :boite{ std::move(cv.cloner()) } {};

Boite::Boite(const ComboHorizontal& ch) :boite{ std::move(ch.cloner()) } {};

unique_ptr<TypeBoite> Boite::cloner() const
{
	return boite->cloner();
};

int Boite::getHauteur() const { return boite->getHauteur(); };
int Boite::getLargeur() const { return boite->getLargeur(); };

std::unique_ptr<Iterateur_Boite<string>> Boite::enumerateur() const
{
	return boite->enumerateur();
};

const vector<string> Boite::getLignes() const
{
	return boite->getLignes();
}

std::ostream& operator<<(std::ostream& os, const Boite& bt)
{
	// cadre du débute de la boite
	os << '+';
	for (int i = 0; i < bt.getLargeur(); ++i) { os << '-'; }
	os << '+' << endl;
	//début du contenu de la boite
	int largeur = bt.getLargeur();
	int hauteur = bt.getHauteur();
	string ligne = "";
	unique_ptr<Iterateur_Boite<string>> iterateur = bt.enumerateur();
	while (iterateur->has_next())
	{
		ligne.clear();
		iterateur->next();
		ligne += '|';
		ligne += iterateur->current();
		/*
		int largeur_ligne = iterateur->current().length();
		if (largeur_ligne < largeur)
		{
			ligne += std::string(largeur - largeur_ligne, ' ');
		}
		*/
		ligne += '|';
		os << ligne << endl;;
	}
	// fin du contenu de la boite
	// cadre de la fin de la boite
	os << '+';
	for (int i = 0; i < bt.getLargeur(); ++i) { os << '-'; }
	os << '+';

	return os;
};
