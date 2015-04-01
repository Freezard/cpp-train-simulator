//-------------------------------------------------------------------
// Godsvagn.h
// En typ av rälsfordon
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef Godsvagn_H
#define Godsvagn_H

#include "Ralsfordon.h"

class Godsvagn : public Ralsfordon{
public:
	Godsvagn(string id, string typ)
		:Ralsfordon(id, typ){}
};
#endif