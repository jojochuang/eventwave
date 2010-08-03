#ifndef _PARAM_READER_H
#define _PARAM_READER_H

#include "BinaryLogObject.h"
#include "params.h"

namespace ParamReader_namespace {
  typedef params::StringMap ParamReaderMap;
  
  class ParamReader : public mace::BinaryLogObject, public mace::PrintPrintable {
  public:
    static const std::string type;
    ParamReaderMap paramMap;
    
    ParamReader() {
    }
    
    ParamReader(const params::StringMap& m) {
      paramMap = m;
    }

  protected:
    static mace::LogNode* rootLogNode;

  public:
    void serialize(std::string& __str) const {
      uint64_t size = paramMap.size();
      
      mace::serialize(__str, &size);
      
      for (ParamReaderMap::const_iterator i = paramMap.begin(); 
	   i != paramMap.end(); i++) {
	mace::serialize(__str, &i->first);
	mace::serialize(__str, &i->second);
      }
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      uint64_t size;
      int ret = 0;
      
      ret += mace::deserialize(is, &size);
      
      for (uint64_t i = 0; i < size; i++) {
	std::string key, value;
	
	ret += mace::deserialize(is, &key);
	ret += mace::deserialize(is, &value);
	paramMap[key] = value;
      }
      return ret;
    }
    
    void print(std::ostream& __out) const {
      for (ParamReaderMap::const_iterator i = paramMap.begin();
	   i != paramMap.end(); i++) {
	__out << std::endl << i->first << " = " << i->second;
      }
    }
    
    void sqlize(mace::LogNode* node) const {
      paramMap.sqlize(node);
    }
    
    const std::string& getLogType() const {
      return type;
    }

    const std::string& getLogDescription() const {
      static const std::string desc = "Param";
      return desc;
    }

    LogClass getLogClass() const {
      return PARAM;
    }

    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
  };
  
  void init();
}

#endif // _PARAM_READER_H
