#include"uneboite.h"
#include"typeboite.h"

	UneBoite::UneBoite() 
	{

	};
	UneBoite::UneBoite(string texte) : TypeBoite(texte)
	{

	};

	unique_ptr<TypeBoite> UneBoite::cloner() const
	{
		return unique_ptr<TypeBoite>{new UneBoite};
	};

	std::unique_ptr<Iterateur_Boite<string>> UneBoite::enumerateur()
	{
		return std::make_unique<Iterateur_UneBoite>(this->lignes);
	};

	string UneBoite::toString() const { return this->getTexte(); };