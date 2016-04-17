#include"typeboite.h"
#include"uneboite.h"

UneBoite::UneBoite() :TypeBoite("") {/*fait*/ };
UneBoite::UneBoite(string texte) : TypeBoite(texte){/*fait*/};

unique_ptr<TypeBoite> UneBoite::cloner() const
{
	return unique_ptr<TypeBoite>{new UneBoite};
};

std::unique_ptr<Iterateur_Boite<string>> UneBoite::enumerateur() const
{
	return std::make_unique<Iterateur_UneBoite>(this->lignes_boite_un);
};