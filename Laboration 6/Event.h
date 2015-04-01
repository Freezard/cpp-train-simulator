/*
  File:         Event.h
  Objective:    Definition of abstract class Event and derived concrete
                Event classes.
  Date:         2007 / �rjan Sterner
*/
#ifndef EVENT_H
#define EVENT_H

#include "Tag.h"
#include "Tagcentral.h"

// Forward declarations
class Simulation;
class Tagcentral;

class Event {
public:
    // Constructor requires time of event
    Event (unsigned int t) : time(t) { }
    virtual ~Event() {}

    // Process event by invoking this method
    virtual void processEvent()=0;

    // Get time for this event
    unsigned int getTime() const {
        return time;
    }

protected:
    // Time for this event
    unsigned int time;
};

// Used to compare two Events with respect to time
class EventComparison {
public:
    bool operator() (Event * left, Event * right) {
        return left->getTime() > right->getTime();
    }
};

//--- Derived Event-classes ----------------------------------------------------

// Kallas n�r ett t�g ska s�ttas isamman
class AssembleEvent : public Event {
public:
    AssembleEvent (Simulation *sim, Tagcentral *tagc, int time, Tag *tg)
    : Event(time),theSim(sim),tagcentral(tagc),tag(tg) { }

    virtual void processEvent();

protected:
    Tag *tag;
    Simulation *theSim;
    Tagcentral *tagcentral;
};

// Kallas n�r ett t�g �r redo att �ka
class ReadyEvent : public Event {
public:
    ReadyEvent (Simulation *sim, Tagcentral *tagc, int time, Tag *tg)
    : Event(time),theSim(sim),tagcentral(tagc),tag(tg) { }

    virtual void processEvent();

protected:
    Tag *tag;
    Simulation *theSim;
    Tagcentral *tagcentral;
};

// Kallas n�r ett t�g �ker
class RunningEvent : public Event {
public:
    RunningEvent (Simulation *sim, Tagcentral *tagc, int time, Tag *tg)
    : Event(time),theSim(sim),tagcentral(tagc),tag(tg) { }

    virtual void processEvent();

protected:
    Tag *tag;
    Simulation *theSim;
    Tagcentral *tagcentral;
};

// Kallas n�r ett t�g har ankommit
class ArrivedEvent : public Event {
public:
    ArrivedEvent (Simulation *sim, Tagcentral *tagc, int time, Tag *tg)
    : Event(time),theSim(sim),tagcentral(tagc),tag(tg) { }

    virtual void processEvent();

protected:
    Tag *tag;
    Simulation *theSim;
    Tagcentral *tagcentral;
};

// Kallas n�r ett t�g har plockats is�r
class FinishedEvent : public Event {
public:
    FinishedEvent (Simulation *sim, Tagcentral *tagc, int time, Tag *tg)
    : Event(time),theSim(sim),tagcentral(tagc),tag(tg) { }

    virtual void processEvent();

protected:
    Tag *tag;
    Simulation *theSim;
    Tagcentral *tagcentral;
};
#endif