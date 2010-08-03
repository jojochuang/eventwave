#ifndef _DUMMY_SERVICE_MAPPER_H
#define _DUMMY_SERVICE_MAPPER_H

#include "m_map.h"
#include "BinaryLogObject.h"
#include "ScopedLogReader.h"
#include "ScopedStackExecution.h"
#include "Accumulator.h"
#include "StringLogReader.h"
#include "ParamReader.h"
#include "MethodMap.h"

/** 
 * \file DummyServiceMapper.h
 * \brief defines the DummyServiceMapper class
 */


namespace mace {
  /** 
   * \brief Used for binary logging, this class allows associations between a
   * log type (string) and an object which can deserialize the string.
   */
  typedef BinaryLogObject* (*BinaryLogFactory)();
  
  class DummyServiceMapper{
  private:
    bool doInit() {
      ScopedLogReader_namespace::init();
      SSEReader::init();
      AccumulatorLogObject::init();
      StringLogReader_namespace::init();
      ParamReader_namespace::init();
      MethodMap_namespace::init();
      return true;
    }
    
  public:
   static map<std::string, BinaryLogFactory, SoftState>& mapper() {
	static map<std::string, BinaryLogFactory, SoftState>* m = new map<std::string, BinaryLogFactory, SoftState>();
	return *m;
   } //; ///< stores the set of binary log objects
   void addFactory(const std::string& type, BinaryLogFactory fac) { 
     mapper()[type] = fac; 
   } ///< adds a mapping between the type (key) and the object (obj)
   /// Returns an object pointer for a given key 
   BinaryLogFactory getFactory(const std::string& key) {
     static bool inited __attribute__((unused)) = doInit();
     return mapper()[key]; 
    }
  };
}

#endif // _DUMMY_SERVICE_MAPPER_H
