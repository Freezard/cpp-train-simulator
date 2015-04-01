//-------------------------------------------------------------------
// OppenGodsvagn.h
// En typ av godsvagn
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef OppenGodsvagn_H
#define OppenGodsvagn_H

#include "Godsvagn.h"

class OppenGodsvagn : public Godsvagn{
protected:
	int lastkapacitet;
	int lastyta;
public:
	OppenGodsvagn(string id, int kap, int yta)
		:Godsvagn(id, "Öppen godsvagn"), lastkapacitet(kap), lastyta(yta){}

	int getLastkapacitet() { return lastkapacitet; }
	int getLastyta() { return lastyta; }
};
#endif