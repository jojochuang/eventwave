#ifndef _METHOD_MAP_H
#define _METHOD_MAP_H

#include "Log.h"
#include "BinaryLogObject.h"

namespace MethodMap_namespace {

  class MethodMap : public mace::BinaryLogObject, public mace::PrintPrintable {
  protected:
    static mace::LogNode* rootLogNode;
    
  public:
    std::string method;
    std::string prototype;
    static const std::string type;
    
  public:
    
    MethodMap(const std::string& m = "", const std::string& p = "") : method(m), prototype(p) {
      
    }
    
    void serialize(std::string& __str) const {
      mace::serialize(__str, &method);
      mace::serialize(__str, &prototype);
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      
      bytes += mace::deserialize(is, &method);
      bytes += mace::deserialize(is, &prototype);
      
      return bytes;
    }
    
    void sqlize(mace::LogNode* node) const {
      int index = node->nextIndex();
      
      if (index == 0) {
	std::ostringstream out;
	out << "CREATE TABLE " << node->logName
	    << " (_id INT PRIMARY KEY, method TEXT, prototype TEXT);" 
	    << std::endl;
	Log::logSqlCreate(out.str(), node);
      }
      std::ostringstream out;
      out << node->logId << "\t" << index << "\t" << method << "\t" 
	  << prototype << std::endl;
      ASSERT(fwrite(out.str().c_str(), out.str().size(), 1, node->file) > 0);
    }
    
    void print(std::ostream& __out) const {
    }
    
    const std::string& getLogType() const {
      return type;
    }

    const std::string& getLogDescription() const {
      static const std::string desc = "MethodMap";
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

#endif // _METHOD_MAP_H
