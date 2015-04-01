//-------------------------------------------------------------------
// DragandeFordon.h
// En typ av rälsfordon
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef DragandeFordon_H
#define DragandeFordon_H

#include "Ralsfordon.h"

class DragandeFordon : public Ralsfordon{
protected:
	int maxHast;
public:
	DragandeFordon(string id, string typ, int mh)
		:Ralsfordon(id, typ), maxHast(mh){}

	int getMaxHast() { return maxHast; }
};
#endif