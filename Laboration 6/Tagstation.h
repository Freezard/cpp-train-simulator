//-------------------------------------------------------------------
// Tagstation.h
// En tågstation
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#ifndef Tagstation_H
#define Tagstation_H

#include "Ralsfordon.h"
#include <list>

class Tagstation{
private:
	string namn;
	list<Ralsfordon*> aktuellaRalsfordon;
public:
	Tagstation(string n)
		:namn(n){}

	~Tagstation();

	list<Ralsfordon*> getAktuellaRalsfordon() { return aktuellaRalsfordon; }

	// Lägger till ett rälsfordon till stationen
	void addRalsfordon(Ralsfordon *rfordon);

	// Hämtar ett rälsfordon från stationen
	// PRE: rälsfordonet man vill hämta måste finnas
	Ralsfordon* getRalsfordon(string typ);

	// Kontrollerar att alla rälsfordon i listan finns på stationen
	bool checkRalsfordon(list<string> rfordon);
};
#endif