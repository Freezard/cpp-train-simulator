//-------------------------------------------------------------------
// Simulation.cpp
// Implementationer
// Mattias Majetic 2011-01-20
//-------------------------------------------------------------------

#include "Simulation.h"
#include "Event.h"
#include "SimConst.h"

void Simulation::run(int mins){
	int korTill = currentTime + mins;
	if (korTill >= SIM_TIME)
		korTill = SIM_TIME;

    while(!eventQueue.empty()){
        Event * nextEvent = eventQueue.top();
		if (korTill >= nextEvent->getTime()){
			eventQueue.pop();
			currentTime = nextEvent->getTime();
			nextEvent->processEvent();
			delete nextEvent;
		}
		else{
			currentTime = korTill;
			break;
		}
    }
	currentTime = korTill;
}


void Simulation::scheduleEvent (Event * newEvent){
    eventQueue.push(newEvent);
}