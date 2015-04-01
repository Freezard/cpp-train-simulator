//-------------------------------------------------------------------
// Ellok.h
// En typ av dragande fordon
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Ellok_H
#define Ellok_H

#include "DragandeFordon.h"

class Ellok : public DragandeFordon{
protected:
	int effekt;
public:
	Ellok(string id, int mh, int eff)
		:DragandeFordon(id, "Ellok", mh), effekt(eff){}

	int getEffekt() { return effekt; }
};
#endif