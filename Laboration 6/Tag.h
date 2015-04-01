//-------------------------------------------------------------------
// Tag.h
// Ett tåg
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#ifndef Tag_H
#define Tag_H

#include "Ralsfordon.h"
#include <list>

static const enum Tillstand {NOT_ASSEMBLED, NOT_READY, READY, RUNNING, ARRIVED, FINISHED};
static const char *textTillstand[] =
	{"NOT_ASSEMBLED", "NOT_READY", "READY", "RUNNING", "ARRIVED", "FINISHED"};

class Tag{
private:
	string nr;
	string ursprung;
	string destination;
	int avgangstid;
	int ankomsttid;
	Tillstand tillstand;
	list<string> ingaendeRalsfordon; // Rälsfordon som tåget normalt använder
	list<Ralsfordon*> nuvarandeRalsfordon; // Rälsfordon som tåget består av just nu
public:
	Tag(string n, string urs, string dest, int avg, int ank, list<string> ingRals)
		:nr(n), ursprung(urs), destination(dest), avgangstid(avg),
		ankomsttid(ank), tillstand(NOT_ASSEMBLED), ingaendeRalsfordon(ingRals){}

	~Tag();
	string getNr();
	string getUrsprung();
	string getDestination();
	int getAvgangstid();
	int getAnkomsttid();
	Tillstand getTillstand();
	list<string> getIngaendeRalsfordon();
	list<Ralsfordon*> getNuvarandeRalsfordon();
	void clearRalsfordon();

	void uppdateraAvgangstid(int tid);
	void uppdateraAnkomsttid(int tid);
	void uppdateraTillstand(Tillstand t);
	void addRalsfordon(Ralsfordon *r);
};
#endif