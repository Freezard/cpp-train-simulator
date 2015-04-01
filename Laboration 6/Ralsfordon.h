//-------------------------------------------------------------------
// Ralsfordon.h
// Ett rälsfordon
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#ifndef Ralsfordon_H
#define Ralsfordon_H

#include <string>
#include <iostream>
using namespace std;

class Ralsfordon{
protected:
	string id;
	string typ;
public:
	Ralsfordon(string i, string t)
		:id(i), typ(t){}

	virtual ~Ralsfordon(){}

	virtual void display(ostream &os=cout)
	{ os << "Id: " << id << " Typ: " << typ << endl; }

	string getId() { return id; }
	string getTyp() { return typ; }
};
#endif