#ifndef UNEBOITE
#define UNEBOITE

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
	UneBoite() {};
	UneBoite(string texte);

	unique_ptr<TypeBoite> cloner() const;

	std::unique_ptr<Iterateur_Boite<string>> enumerateur();

	string toString() const;

};



#endif