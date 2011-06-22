#ifndef SIM_EVENT_WEIGHTED_H
#define SIM_EVENT_WEIGHTED_H

#include "SimEvent.h"
#include "SimulatorCommon.h"

/**
 * Modelchecker specific class for holding pending events, picking the next
 * event to execute, etc.
 */
class SimEventWeighted : public mace::PrintPrintable {
  private:
    static SimEventWeighted *_inst;
    int totalWeight; // current sum of all weights. Avoids runtime overhead
    SimEventWeighted() : totalWeight(0) { }

  protected:
    Event getNextEventInternal() {
      EventList& pendingEvents = SimEvent::getEvents();

      ASSERT(pendingEvents.size());

      EventList::iterator nextEventIterator =
          macemc::__SimulatorCommon__::randomUtil->randEvent(pendingEvents, totalWeight);

      Event nextEvent = nextEventIterator->second;
      totalWeight -= nextEventIterator->first;
      
      pendingEvents.erase(nextEventIterator); 
      
      return nextEvent;
    }

    void addEventInternal(int weight, const Event& ev) {
      EventList& pendingEvents = SimEvent::getEvents();
      pendingEvents.insert(std::make_pair(weight, ev));
      totalWeight += weight;
    }

    void removeEventInternal(EventList::iterator ev) {
      totalWeight -= ev->first;
      SimEvent::getEvents().erase(ev);
    }

    void print(std::ostream& out) const {
      EventList& pendingEvents = SimEvent::getEvents();
      out << "events(size=" << pendingEvents.size() << ", ";
      out << "totalWeight=" << totalWeight << ", " << std::endl;
      EventList::const_reverse_iterator e = pendingEvents.rbegin();
      //for (int i = 0; i < 30 && e != pendingEvents.end(); i++, e++) {
      for (; e != pendingEvents.rend(); ++e) {
        out << "( " << e->first << " -> " << e->second << " )" << std::endl;
      }
      out << ")";
    }
    
  public:
    /// Pick the next event to simulate in a Weighted-Random manner
    static Event getNextEvent() {
      return _inst->getNextEventInternal();
    }

    /// Add an event to the list
    static void addEvent(int weight, const Event& ev) {
      _inst->addEventInternal(weight, ev);
    }

    static void removeEvent(EventList::iterator ev) {
      _inst->removeEventInternal(ev);
    }
    
    static mace::Printable& PrintableInstance() {
      return *_inst;
    }
    
    static void SetInstance() {
      if (_inst != NULL) { delete _inst; }
      _inst = new SimEventWeighted();
    }
};

#endif // SIM_EVENT_WEIGHTED_H
