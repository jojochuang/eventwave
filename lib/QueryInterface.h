#ifndef _QUERY_INTERFACE_H
#define _QUERY_INTERFACE_H

#include "BinaryLogObject.h"
#include "mvector.h"

class QueryInterface;

class OutputIterator {
public:
  virtual std::string getNext() = 0;
  virtual ~OutputIterator() { }
};

typedef OutputIterator* (*QueryHandler)(QueryInterface& q, const std::string& args);

class Mdb;

class BinaryLogIter {
  friend class Mdb;
  
protected:
  int index;
  mace::vector<uint64_t>* indexList;
  mace::BinaryLogObject* obj;
  std::string logType;
  std::ifstream* in;
  
  // only Mdb should be able to instantiate these
  BinaryLogIter();
  BinaryLogIter(const std::string& type, std::ifstream* ifs);
  
public:
  virtual ~BinaryLogIter() {}
  virtual mace::BinaryLogObject* getNext();
  mace::BinaryLogObject* getObj() {
    return obj;
  }
  virtual void reset();
};

class QueryInterface {

public:
  virtual ~QueryInterface() { }
  virtual void registerQuery(const std::string& name, 
			     const std::string& params,
			     const std::string& queryBody,
			     QueryHandler callback) = 0;
  virtual BinaryLogIter iterator(const std::string& logType) = 0;
};

#endif // _QUERY_INTERFACE_H
