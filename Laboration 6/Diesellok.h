//-------------------------------------------------------------------
// Diesellok.h
// En typ av dragande fordon
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Diesellok_H
#define Diesellok_H

#include "DragandeFordon.h"

class Diesellok : public DragandeFordon{
protected:
	int forbrukning;
public:
	Diesellok(string id, int mh, int fb)
		:DragandeFordon(id, "Diesellok", mh), forbrukning(fb){}

	int getForbrukning() { return forbrukning; }
};
#endif