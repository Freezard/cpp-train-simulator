//-------------------------------------------------------------------
// Tagcentral.cpp
// Implementationer
// Mattias Majetic 2011-01-25
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "Simulation.h"
#include "Ralsfordon.h"
#include "Diesellok.h"
#include "Ellok.h"
#include "Sovvagn.h"
#include "OppenGodsvagn.h"
#include "TacktGodsvagn.h"
#include "Sittvagn.h"
#include "SimConst.h"

Tagcentral::Tagcentral(Simulation *sim)
	:theSim(sim), lyckadeKorningar(0){

	byggStationer();
	byggRalsfordon();
	byggTag();
}

Tagcentral::~Tagcentral(){
	map<string, Tag*>::iterator it;
	map<string, Tagstation*>::iterator it2;

	for (it = taglista.begin();it != taglista.end();it++)
		delete (*it).second;

	for (it2 = tagstationer.begin();it2 != tagstationer.end();it2++)
		delete (*it2).second;
}

bool Tagcentral::tryAssemble(Tag *tag){
	int tid = theSim->getTime();
	string nr = tag->getNr();
	string ursprung = tag->getUrsprung();
	list<string> ingaendeRalsfordon = tag->getIngaendeRalsfordon();
	list<string>::iterator begin = ingaendeRalsfordon.begin(),
							end = ingaendeRalsfordon.end(), it;

	cout << "Tid " << tid << ": ";
	cout << "Tag " << nr << " fran " << ursprung <<
							" forsoker sattas ihop." << endl;
	
	if (tagstationer[ursprung]->checkRalsfordon(ingaendeRalsfordon)){
		for (it = begin;it != end;it++)
			tag->addRalsfordon(tagstationer[ursprung]->getRalsfordon(*it));

		tag->uppdateraTillstand(NOT_READY);
		cout << "Tid " << tid << ": ";
		cout << "Tag " << nr << " fran " << ursprung <<
								" ar ihopsatt." << endl;
		return true;
	}
	else{
		forsenadeTag[tag] += DELAY_TIME;
		tag->uppdateraAvgangstid(tag->getAvgangstid() + DELAY_TIME);
		tag->uppdateraAnkomsttid(tag->getAnkomsttid() + DELAY_TIME);

		cout << "Tid " << tid << ": ";
		cout << "Tag " << nr << " fran " << ursprung <<
			" saknar ralsfordon. Ny tid: " << tag->getAvgangstid() << endl;

		return false;
	} 
}

void Tagcentral::ready(Tag *tag){
	cout << "Tid " << theSim->getTime() << ": ";
	cout << "Tag " << tag->getNr() << " fran " << tag->getUrsprung() <<
										" ar redo att kora." << endl;

	tag->uppdateraTillstand(READY);
}

void Tagcentral::running(Tag *tag){
	cout << "Tid " << theSim->getTime() << ": ";
	cout << "Tag " << tag->getNr() << " fran " << tag->getUrsprung() <<
							" kor mot " << tag->getDestination() << endl;

	tag->uppdateraTillstand(RUNNING);
}

void Tagcentral::arrived(Tag *tag){
	cout << "Tid " << theSim->getTime() << ": ";
	cout << "Tag " << tag->getNr() << " fran " << tag->getUrsprung() <<
					" har anlant vid " << tag->getDestination() << endl;

	tag->uppdateraTillstand(ARRIVED);
}

void Tagcentral::finished(Tag *tag){
	string destination = tag->getDestination();
	list<Ralsfordon*> nuvarandeRalsfordon = tag->getNuvarandeRalsfordon();
	list<Ralsfordon*>::iterator begin = nuvarandeRalsfordon.begin(),
								end = nuvarandeRalsfordon.end(), it;

	for (it = begin;it != end;it++)
		tagstationer[destination]->addRalsfordon(*it);

	cout << "Tid " << theSim->getTime() << ": ";
	cout << "Tag " << tag->getNr() << " fran " << tag->getUrsprung() <<
		" har aterlamnat ralsfordon till " << destination << endl;

	tag->uppdateraTillstand(FINISHED);
	tag->clearRalsfordon();
	lyckadeKorningar++;
}

void Tagcentral::printTidtabell(){
	map<string, Tag*>::iterator begin = taglista.begin(),
		end = taglista.end(), it;

	for (it = begin;it != end;it++){
		Tag *tag = (*it).second;
		cout << tag->getNr() << " " << tag->getUrsprung() << " " <<
			tag->getDestination() << " " << tag->getAvgangstid() <<
			" " << tag->getAnkomsttid() << " " << textTillstand[tag->getTillstand()] << endl;
	}
}

void Tagcentral::printFordonpool(string station){
	list<Ralsfordon*> ralsfordon = tagstationer[station]->getAktuellaRalsfordon();
	if (ralsfordon.empty()){
		cout << "Stationen saknar ralsfordon." << endl;
		return;
	}

	list<Ralsfordon*>::iterator begin = ralsfordon.begin(),	end = ralsfordon.end(), it;

	for (it = begin;it != end;it++)
		(*it)->display();
}

void Tagcentral::printTaginfo(string nr){
	list<Ralsfordon*> ralsfordon = taglista[nr]->getNuvarandeRalsfordon();
	if (ralsfordon.empty()){
		cout << "Taget saknar ralsfordon." << endl;
		return;
	}

	list<Ralsfordon*>::iterator begin = ralsfordon.begin(), end = ralsfordon.end(), it;

	for (it = begin;it != end;it++)
		(*it)->display();
}

void Tagcentral::printStatistik(){
	map<Tag*, int>::iterator begin = forsenadeTag.begin(),
							end = forsenadeTag.end(), it;
	map<string, Tag*>::iterator tag;

	cout << "Lyckade tagkorningar: " << lyckadeKorningar << endl << endl;

	for (it = begin;it != end;it++)
		cout << "Tag " << it->first->getNr() << " forsenad " << it->second
		<< " minuter." << endl;
	
	cout << endl;

	for (tag = taglista.begin();tag != taglista.end();tag++){
		Tillstand tillstand = (*tag).second->getTillstand();
		if (tillstand == NOT_ASSEMBLED || tillstand == NOT_READY || 
										  tillstand == READY)
			cout << "Tag " << (*tag).second->getNr() <<
					" lamnade aldrig sin station." << endl;
	}
}

void Tagcentral::byggStationer(){
	string namn;
	ifstream file("Stationer.txt");

	if (file.is_open()){
		while (file.good()){
			getline(file, namn);
			tagstationer[namn] = new Tagstation(namn);
		}
		file.close();
	}
}

void Tagcentral::byggRalsfordon(){
	string typ;
	string id;
	string station;
	int attr1;
	int attr2;
	int attr3;
	string attr4;
	bool attr5;
	Ralsfordon *rfordon;

	ifstream file("Ralsfordon.txt");
	if (file.is_open()){
		while (file.good()){
			getline(file, typ);
			getline(file, id);
			getline(file, station);

			if (typ == "Sovvagn"){
				file >> attr1, file >> attr2, file >> attr3, file >> attr4;
				if (attr4 == "Ja" || attr4 == "ja")
					attr5 = true;
				else attr5 = false;

				rfordon = new Sovvagn(id, attr1, attr2, attr3, attr5);
			}
			else if (typ == "Sittvagn"){
				file >> attr1, file >> attr4;
				if (attr4 == "Ja" || attr4 == "ja")
					attr5 = true;
				else attr5 = false;

				rfordon = new Sittvagn(id, attr1, attr5);
			}
			else if (typ == "Öppen Godsvagn"){
				file >> attr1, file >> attr2;
				rfordon = new OppenGodsvagn(id, attr1, attr2);
			}
			else if (typ == "Täckt Godsvagn"){
				file >> attr1;
				rfordon = new TacktGodsvagn(id, attr1);
			}
			else if (typ == "Ellok"){
				file >> attr1, file >> attr2;
				rfordon = new Ellok(id, attr1, attr2);
			}
			else if (typ == "Diesellok"){
				file >> attr1, file >> attr2;
				rfordon = new Diesellok(id, attr1, attr2);
			}

			tagstationer[station]->addRalsfordon(rfordon);

			getline(file, typ); // Hoppa över blank rad i textfilen
			getline(file, typ); // Pga mix av getline och >>
		}
		file.close();
	}
}

void Tagcentral::byggTag(){
	string nr;
	string ursprung;
	string destination;
	string avg;
	string ank;
	list<string> ralsfordon;
	string fordon;
	Tag *tag;

	ifstream file("Tag.txt");
	if (file.is_open()){
		while (file.good()){
			getline(file, nr);
			getline(file, ursprung);
			getline(file, destination);
			getline(file, avg);
			getline(file, ank);

			// Lägg till rälsfordon som tåget ska bestå av, stoppa vid blank rad
			while (getline(file, fordon) && fordon != ""){
				ralsfordon.push_back(fordon);
			}

			// Konverterar HH:MM till simulatortid
			int avgang = (avg.at(0) - '0') * 600 + (avg.at(1) - '0') * 60
				+ (avg.at(3) - '0') * 10 + (avg.at(4) - '0');

			int ankomst = (ank.at(0) - '0') * 600 + (ank.at(1) - '0') * 60
				+ (ank.at(3) - '0') * 10 + (ank.at(4) - '0');
			
			tag = new Tag(nr, ursprung, destination, avgang, ankomst, ralsfordon);

			if (theSim->getTime() <= avgang - PREPARE_TIME){
				taglista[nr] = tag; // Lägg till tåget i tåglistan
				theSim->scheduleEvent(new AssembleEvent(theSim, this, avgang - PREPARE_TIME, tag));
			}
			
			ralsfordon.clear();
		}
	}
}