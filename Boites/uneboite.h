#ifndef UNEBOITE_H
#define UNEBOITE_H

class TypeBoite;

struct Iterateur_UneBoite : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_UneBoite(const std::vector<string> &liste) : courant{ liste.begin() }, fin{ liste.end() }, debut{ true } {};
	string current() const { return *courant; };
	bool has_next() const { return courant != fin && std::next(courant) != fin; };
	void next() { if (!debut) { ++courant; }debut = {}; };
};

class UneBoite : public TypeBoite
{
public:
	UneBoite();
	UneBoite(string texte);
	UneBoite(const vector<string>& lignes);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()const;

	//string getTexte() const; ok utiliser celui de la classe de basse

};



#endif