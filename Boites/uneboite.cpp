#include"typeboite.h"
#include"uneboite.h"

UneBoite::UneBoite() :TypeBoite("") {/*fait*/ };
UneBoite::UneBoite(string texte) : TypeBoite(texte){/*fait*/};
UneBoite::UneBoite(const vector<string>& lignes) : TypeBoite(lignes) {};

unique_ptr<TypeBoite> UneBoite::cloner() const
{
	return unique_ptr<TypeBoite>{new UneBoite(lignes_boite_un)};
};

std::unique_ptr<Iterateur_Boite<string>> UneBoite::enumerateur() const
{
	return std::make_unique<Iterateur_UneBoite>(lignes_boite_un);
};