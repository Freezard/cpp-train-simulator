/*
  File:         Simulation.h
  Objective:    Definition of class Simulation, a framework for
                discrete event-driven simulation
  Date:         2007 / Örjan Sterner
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include <queue>
#include <vector>
#include "Event.h"

using std::priority_queue;
using std::vector;

class Simulation {
public:
    Simulation (int start)
		:eventQueue(), currentTime(start){ }

    void scheduleEvent (Event * newEvent);

    int getTime() const { return currentTime; }

	// Kör simulatorn i ett visst antal minuter
    void run(int mins);

private:
    int currentTime;

     /* The event queue. Always sorted with respect to the times
        for the events. The event with the 'smallest' time is always
        placed first in queue and will be processed next. */

    priority_queue<Event*, vector<Event*>, EventComparison> eventQueue;
};
#endif
