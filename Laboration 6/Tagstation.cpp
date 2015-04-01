//-------------------------------------------------------------------
// Tagstation.cpp
// Implementationer
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#include "Tagstation.h"

Tagstation::~Tagstation(){
	list<Ralsfordon*>::iterator begin = aktuellaRalsfordon.begin(),
								end = aktuellaRalsfordon.end(), it;

	for (it = begin;it != end;it++)
		delete *it;
}

void Tagstation::addRalsfordon(Ralsfordon *rfordon){
	aktuellaRalsfordon.push_back(rfordon);
}

Ralsfordon* Tagstation::getRalsfordon(string typ){
	list<Ralsfordon*>::iterator begin = aktuellaRalsfordon.begin(),
								end = aktuellaRalsfordon.end(), it;

	for (it = begin;it != end;it++)
		if ((*it)->getTyp() == typ){
			Ralsfordon *rfordon = *it;
			aktuellaRalsfordon.erase(it);
			return rfordon;
		}
}

bool Tagstation::checkRalsfordon(list<string> rfordon){
	list<Ralsfordon*> temp(aktuellaRalsfordon);
	list<Ralsfordon*>::iterator it;
	list<string>::iterator begin = rfordon.begin(),
							end = rfordon.end(), typ;
	int hittadeFordon = 0;

	for (typ = begin;typ != end;typ++)
		for (it = temp.begin();it != temp.end();it++)
			if (*typ == (*it)->getTyp()){
				temp.remove(*it);
				hittadeFordon++;
				break;
			}

	if (hittadeFordon == rfordon.size())
		return true;
	else return false;
}