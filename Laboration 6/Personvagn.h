//-------------------------------------------------------------------
// Personvagn.h
// En typ av rälsfordon
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Personvagn_H
#define Personvagn_H

#include "Ralsfordon.h"

class Personvagn : public Ralsfordon{
protected:
	int sittplatser;
	bool internet;
public:
		Personvagn(string id, string typ, int platser, bool inet)
			:Ralsfordon(id, typ), sittplatser(platser), internet(inet){}

		int getSittplatser() { return sittplatser; }
		bool getInternet() { return internet; }
};
#endif