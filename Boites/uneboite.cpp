#include"typeboite.h"
#include"boite.h"
#include"uneboite.h"


UneBoite::UneBoite() :TypeBoite("") {/*fait*/ };
UneBoite::UneBoite(string texte) : TypeBoite(texte){/*fait*/};
UneBoite::UneBoite(const vector<string>& lignes) : TypeBoite(lignes) {};

unique_ptr<TypeBoite> UneBoite::cloner() const
{
	return unique_ptr<TypeBoite>{
		new UneBoite(getLignes())
	};
};

std::unique_ptr<Iterateur_Boite<string>> UneBoite::enumerateur() const
{
	return std::make_unique<Iterateur_UneBoite>(this->getLignes());
};
