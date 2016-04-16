#pragma
#include"boite.h"
using namespace std;


Boite::Boite() :boite{ std::move(new UneBoite()) } {};

Boite::Boite(string texte) :boite{ std::move(new UneBoite(texte)) } {};

Boite::Boite(const TypeBoite& boite) :boite{ std::move(boite.cloner()) } { };


int Boite::getHauteur() const { return boite->getHauteur(); }
int Boite::getLargeur() const { return boite->getLargeur(); }

std::unique_ptr<Iterateur_Boite<string>> Boite::enumerateur()
{
	return boite->enumerateur();
};