#ifndef _STRING_LOG_READER_H
#define _STRING_LOG_READER_H

#include "BinaryLogObject.h"

namespace StringLogReader_namespace {

class StringLogReader : public mace::BinaryLogObject, public mace::PrintPrintable {
public:
  std::string text;
  static const std::string type;
    
  StringLogReader(const std::string& str = "") : text(str){
  }
  
protected:
  static mace::LogNode* rootLogNode;

public:
  void serialize(std::string& __str) const {
  }
    
  int deserialize(std::istream& is) throw(mace::SerializationException) {
    is.seekg(-4, std::ios::cur);
    mace::deserialize(is, &text);
    return text.size();
  }
    
  void print(std::ostream& __out) const {
    __out << text;
  }
    
  const std::string& getLogType() const {
    return type;
  }
    
  const std::string& getLogDescription() const {
    static const std::string desc = "String";
    return desc;
  }
    
  LogClass getLogClass() const {
    return STRING;
  }

  mace::LogNode*& getChildRoot() const {
    return rootLogNode;
  }
};
  
  void init();
}

#endif // _STRING_LOG_READER_H
