//-------------------------------------------------------------------
// TacktGodsvagn.h
// En typ av godsvagn
// Mattias Majetic 2011-01-16
//-------------------------------------------------------------------
#ifndef TacktGodsvagn_H
#define TacktGodsvagn_H

#include "Godsvagn.h"

class TacktGodsvagn : public Godsvagn{
protected:
	int lastvolym;
public:
	TacktGodsvagn(string id, int vol)
		:Godsvagn(id, "Täckt godsvagn"), lastvolym(vol){}

	int getLastvolym() { return lastvolym; }
};
#endif