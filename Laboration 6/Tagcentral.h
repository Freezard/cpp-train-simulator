//-------------------------------------------------------------------
// Tagcentral.h
// En t�gcentral som styr t�g mellan stationer
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#ifndef Tagcentral_H
#define Tagcentral_H

#include "Tagstation.h"
#include "Tag.h"
#include <map>

class Simulation;

class Tagcentral{
public:
   Tagcentral(Simulation *sim);
   ~Tagcentral();

   void byggStationer(); // L�ser in stationer fr�n textfil
   void byggRalsfordon(); // L�ser in r�lsfordon fr�n textfil
   void byggTag(); // L�ser in t�g fr�n textfil

   bool tryAssemble(Tag *tag); // F�rs�ker s�tta ihop ett t�g
   void ready(Tag *tag); // Utf�rs n�r ett t�g �r redo att �ka
   void running(Tag *tag); // Utf�rs n�r ett t�g �ker
   void arrived(Tag *tag); // Utf�rs n�r ett t�g har ankommit
   void finished(Tag *tag); // Utf�rs n�r ett t�g har tagits is�r

   void printTidtabell();
   void printFordonpool(string station); // PRE: stationen m�ste finnas
   void printTaginfo(string nr); // PRE: t�get m�ste finnas
   void printStatistik(); // Skriver ut antal lyckade t�gk�rningar,
						  // f�rsenade t�g och t�g som aldrig l�mnade
						  // sin avg�ngsstation
private:
   Simulation *theSim;
   map<string, Tagstation*> tagstationer;
   map<string, Tag*> taglista;
   map<Tag*, int> forsenadeTag;
   int lyckadeKorningar;
};

#endif