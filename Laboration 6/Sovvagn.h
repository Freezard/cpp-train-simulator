//-------------------------------------------------------------------
// Sovvagn.h
// En typ av personvagn
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Sovvagn_H
#define Sovvagn_H

#include "Personvagn.h"

class Sovvagn : public Personvagn{
protected:
	int kupeer;
	int baddar;
public:
	Sovvagn(string id, int kup, int bad, int platser, bool inet)
		:Personvagn(id, "Sovvagn", platser, inet), kupeer(kup), baddar(bad){}

	int getKupeer() { return kupeer; }
	int getBaddar() { return baddar; }
};
#endif