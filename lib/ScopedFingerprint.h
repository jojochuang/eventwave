#ifndef _SCOPED_FINGERPRINT_H
#define _SCOPED_FINGERPRINT_H

#include "mstring.h"
#include "ScopedStackExecution.h"

/**
 * \file ScopedFingerprint.h
 * \brief declares mace::ScopedFingerprint
 */

namespace mace {

/**
 * \addtogroup Scoped
 * \brief The scoped tools all take advantage of begin and end behaviors in the constructor and destructor of objects.
 * @{
 */

/**
 * \brief Used to compute a fingerprint of the call path of an event.
 *
 * Used in the simulator to tell what event fired for time-based estimation.
 * May have other uses, such as getting a stack trace.  
 *
 * \todo Consider disabling ScopedFingerprint for deployment executions.
 */
class ScopedFingerprint {
  private:
  
  public:
    /// Place a scoped fingerprint object after the lock or ScopedLock object, and before each ScopedStackExecution object.
    /**
     * Must be placed before \e every ScopedStackExecution object or it might miss events or being cleared.
     */
    ScopedFingerprint(const std::string& selectorId) {
      ThreadSpecific *t = ThreadSpecific::init();

      if (ScopedStackExecution::getStackDepth() == 0) {
        t->clearFingerprint();
      }
      t->addFingerprint(selectorId + "(");
    }
    ~ScopedFingerprint() {
      ThreadSpecific *t = ThreadSpecific::init();
      t->addFingerprint(")");
    }

    /// returns the current fingerprint 
    /**
     * It is thread-safe function
     */
    string& getFingerprint() {
      ThreadSpecific *t = ThreadSpecific::init();
      return t->getFingerprint();
    }


  private:  
    class ThreadSpecific {

    public:
      ThreadSpecific();
      ~ThreadSpecific();
      static ThreadSpecific* init();
      static uint32_t getVtid();
      void clearFingerprint();
      void addFingerprint(const string& s);
      string& getFingerprint();

    private:
      static void initKey();

    private:
      static pthread_key_t pkey;
      static pthread_once_t keyOnce;
      static unsigned int count;
      uint32_t vtid;
      string fingerprint;
  };
};



/**
 * @}
 */

}

#endif //_SCOPED_FINGERPRINT_H
