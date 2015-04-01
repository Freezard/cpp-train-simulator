//-------------------------------------------------------------------
// Tag.cpp
// Implementationer
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#include "Tag.h"

Tag::~Tag(){
	list<Ralsfordon*>::iterator begin = nuvarandeRalsfordon.begin(),
								end = nuvarandeRalsfordon.end(), it;

	for (it = begin;it != end;it++)
		delete *it;
}

string Tag::getNr() { return nr; }
string Tag::getUrsprung() { return ursprung; }
string Tag::getDestination() { return destination; }
int Tag::getAvgangstid() { return avgangstid; }
int Tag::getAnkomsttid() { return ankomsttid; }
Tillstand Tag::getTillstand() { return tillstand; }
list<string> Tag::getIngaendeRalsfordon() { return ingaendeRalsfordon; }
list<Ralsfordon*> Tag::getNuvarandeRalsfordon() { return nuvarandeRalsfordon; }
void Tag::clearRalsfordon() { nuvarandeRalsfordon.clear(); }

void Tag::uppdateraAvgangstid(int tid) { avgangstid = tid; }
void Tag::uppdateraAnkomsttid(int tid) { ankomsttid = tid; }
void Tag::uppdateraTillstand(Tillstand t){ tillstand = t; }

void Tag::addRalsfordon(Ralsfordon *r){
	nuvarandeRalsfordon.push_back(r);
}