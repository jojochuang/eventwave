#ifndef _START_EVENT_READER_H
#define _START_EVENT_READER_H

#include <boost/format.hpp>
#include "DummyServiceMapper.h"
#include "BinaryLogObject.h"

namespace StartEventReader_namespace {

  class StartEventReader : public mace::BinaryLogObject, public mace::PrintPrintable {
  protected:
    static mace::LogNode* rootLogNode;
    
  public:
    int node;
    uint64_t nodeTime;
    bool begin;
    static const std::string& type();
    
  public:
    
    StartEventReader(int n = 0, uint64_t time = 0, bool b = 0) : node(n), nodeTime(time), begin(b) {
      
    }
    
    void serialize(std::string& __str) const {
      mace::serialize(__str, &node);
      mace::serialize(__str, &nodeTime);
      mace::serialize(__str, &begin);
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      
      bytes += mace::deserialize(is, &node);
      bytes += mace::deserialize(is, &nodeTime);
      bytes += mace::deserialize(is, &begin);
      
      return bytes;
    }
    
    void sqlize(mace::LogNode* __node) const {
      int index = __node->nextIndex();
      
      if (index == 0) {
	std::ostringstream out;
	out << "CREATE TABLE " << __node->logName
	    << " (_id INT PRIMARY KEY, node INT, nodeTime INT8, begin INT);" 
	    << std::endl;
	Log::logSqlCreate(out.str(), __node);
      }
      std::ostringstream out;
      out << __node->logId << "\t" << index << "\t" << node << "\t" 
	  << nodeTime << "\t" << begin << std::endl;
      ASSERT(fwrite(out.str().c_str(), out.str().size(), 1, __node->file) > 0);
    }
    
    void print(std::ostream& __out) const {
      double printedTime = ((double)nodeTime) / 1000000;
      __out << (begin ? "Starting" : "Ending") << " event on node " << node 
	    << " at time " << boost::format("%.6f") % printedTime;
    }
    
    const std::string& getLogType() const {
      return type();
    }

    const std::string& getLogDescription() const {
      static const std::string desc = "StartEvent";
      return desc;
    }

    LogClass getLogClass() const {
      return STRUCTURE;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
  };
  
  void init() __attribute__((constructor));
}

#endif // _START_EVENT_READER_H
