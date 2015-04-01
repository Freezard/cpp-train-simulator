//-------------------------------------------------------------------
// Tagstation.h
// En t�gstation
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

	// L�gger till ett r�lsfordon till stationen
	void addRalsfordon(Ralsfordon *rfordon);

	// H�mtar ett r�lsfordon fr�n stationen
	// PRE: r�lsfordonet man vill h�mta m�ste finnas
	Ralsfordon* getRalsfordon(string typ);

	// Kontrollerar att alla r�lsfordon i listan finns p� stationen
	bool checkRalsfordon(list<string> rfordon);
};
#endif