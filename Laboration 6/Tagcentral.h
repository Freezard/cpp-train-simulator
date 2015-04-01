//-------------------------------------------------------------------
// Tagcentral.h
// En tågcentral som styr tåg mellan stationer
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

   void byggStationer(); // Läser in stationer från textfil
   void byggRalsfordon(); // Läser in rälsfordon från textfil
   void byggTag(); // Läser in tåg från textfil

   bool tryAssemble(Tag *tag); // Försöker sätta ihop ett tåg
   void ready(Tag *tag); // Utförs när ett tåg är redo att åka
   void running(Tag *tag); // Utförs när ett tåg åker
   void arrived(Tag *tag); // Utförs när ett tåg har ankommit
   void finished(Tag *tag); // Utförs när ett tåg har tagits isär

   void printTidtabell();
   void printFordonpool(string station); // PRE: stationen måste finnas
   void printTaginfo(string nr); // PRE: tåget måste finnas
   void printStatistik(); // Skriver ut antal lyckade tågkörningar,
						  // försenade tåg och tåg som aldrig lämnade
						  // sin avgångsstation
private:
   Simulation *theSim;
   map<string, Tagstation*> tagstationer;
   map<string, Tag*> taglista;
   map<Tag*, int> forsenadeTag;
   int lyckadeKorningar;
};

#endif