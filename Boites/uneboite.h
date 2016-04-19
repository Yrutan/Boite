#ifndef UNEBOITE_H
#define UNEBOITE_H

class TypeBoite;
class Boite;

struct Iterateur_UneBoite : Iterateur_Boite<string>
{
private:
	std::vector<string>::const_iterator courant, fin;
	bool debut;
public:
	Iterateur_UneBoite(const vector<string>& lignes) 
		: courant{ lignes.begin() }, fin{ lignes.end() }, debut{ true } {};
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
	UneBoite(std::unique_ptr<TypeBoite>& boite);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur()const;
};



#endif