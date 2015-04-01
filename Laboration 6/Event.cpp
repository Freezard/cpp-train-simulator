//-------------------------------------------------------------------
// Event.cpp
// Implementationer
// Mattias Majetic 2011-01-20
//-------------------------------------------------------------------

#include "Event.h"
#include "Tagcentral.h"
#include "Simulation.h"
#include "SimConst.h"

void AssembleEvent::processEvent(){
	if (tagcentral->tryAssemble(tag)){
		time += ASSEMBLE_TIME;
		theSim->scheduleEvent(new ReadyEvent(theSim, tagcentral, time, tag));
	}
	else{
		time += DELAY_TIME;
		theSim->scheduleEvent(new AssembleEvent(theSim, tagcentral, time, tag));
	}
}

void ReadyEvent::processEvent(){
	tagcentral->ready(tag);
	time += READY_TIME;
	theSim->scheduleEvent(new RunningEvent(theSim, tagcentral, time, tag));
}

void RunningEvent::processEvent(){
	tagcentral->running(tag);
	time += tag->getAnkomsttid() - tag->getAvgangstid();
	theSim->scheduleEvent(new ArrivedEvent(theSim, tagcentral, time, tag));
}

void ArrivedEvent::processEvent(){
	tagcentral->arrived(tag);
	time += DISASSEMBLE_TIME;
	theSim->scheduleEvent(new FinishedEvent(theSim, tagcentral, time, tag));
}

void FinishedEvent::processEvent(){
	tagcentral->finished(tag);
}