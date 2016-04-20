#ifndef UNEBOITE_H
#define UNEBOITE_H

class TypeBoite;
class Boite;

struct Iterateur_UneBoite : Iterateur_Boite<string>
{
private:
	std::vector<string> lignes;
	std::vector<string>::const_iterator courant, fin;
	bool debut;
	int largeur;
public:
	Iterateur_UneBoite(const vector<string>& lignes) 
		: debut{ true } 
	{
		largeur = 0;
		for each (string ligne in lignes)
		{
			this->lignes.push_back(ligne);
			if (ligne.length() > largeur)
			{
				largeur = ligne.length();
			}
		}
		courant = this->lignes.begin();
		fin = this->lignes.end();
		
		
	};
	string current() const 
	{ 
		string sortie = "";
		sortie += *courant;
		sortie += std::string(largeur - sortie.length(), ' ');
		return sortie;
	};
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
};



#endif