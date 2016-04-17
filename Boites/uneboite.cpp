#include"typeboite.h"
#include"uneboite.h"

	UneBoite::UneBoite() :TypeBoite("")
	{

	};
	UneBoite::UneBoite(string texte) : TypeBoite(texte)
	{

	};

	unique_ptr<TypeBoite> UneBoite::cloner() const
	{
		return unique_ptr<TypeBoite>{new UneBoite};
	};

	std::unique_ptr<Iterateur_Boite<string>> UneBoite::enumerateur() const
	{
		return std::make_unique<Iterateur_UneBoite>(this->lignes);
	};

	string UneBoite::toString() const { return this->getTexte(); };