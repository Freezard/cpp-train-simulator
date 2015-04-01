//-------------------------------------------------------------------
// Main.cpp
// Huvudprogrammet
// Mattias Majetic 2011-01-22
//-------------------------------------------------------------------
#include <iostream>
#include <conio.h>
#include "Tagcentral.h"
#include "Simulation.h"
#include "SimConst.h"

int main(int argc, char* argv[]){
	Simulation *theSim = new Simulation(START_TIME);
	Tagcentral *tagcentral = new Tagcentral(theSim);

	char c;
	string s;
	do{
		cout << "Tid " << theSim->getTime() <<
			": 1. Fortsatt 2. Tidtabell 3. Fordonspool 4. Taginfo 5. Avsluta" << endl;
		c = _getch();
		switch (c){
			case '1': theSim->run(RUN_TIME); // Fortsätter simuleringen i x minuter
				break;
			case '2': tagcentral->printTidtabell();
				break;
			case '3': cout << "Ange station: ";
				getline(cin, s);
				tagcentral->printFordonpool(s);
				break;
			case '4': cout << "Ange tagnummer: ";
				getline(cin, s);
				tagcentral->printTaginfo(s);
				break;
		}
	} while (theSim->getTime() < SIM_TIME && c != '5');
	
	cout << "Avslutar simulatorn..." << endl << endl;
	tagcentral->printStatistik();

    delete theSim;
    delete tagcentral;
    std::system("pause");
    return 0;
}