//-------------------------------------------------------------------
// Sittvagn.h
// En typ av personvagn
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Sittvagn_H
#define Sittvagn_H

#include "Personvagn.h"

class Sittvagn : public Personvagn{
public:
	Sittvagn(string id, int platser, bool inet)
		:Personvagn(id, "Sittvagn", platser, inet){}
};
#endif