#ifndef __SIMPLE_LOG_OBJECT_H
#define __SIMPLE_LOG_OBJECT_H

#include "BinaryLogObject.h"
#include "Log.h"
#include "Printable.h"

namespace mace {

template<typename T>
class SimpleLogObject : public BinaryLogObject, public PrintPrintable {

protected:
  static LogNode* rootLogNode;
  const std::string& logType;
  const T& obj;
  
public:
  SimpleLogObject(const std::string& desc, const T& _obj) : logType(desc),
							    obj(_obj) {
  }
  
  const std::string& getLogType() const {
    return logType;
  }
  
  const std::string& getLogDescription() const {
    static const std::string desc = "Return Type";
    return desc;
  }
  
  LogClass getLogClass() const {
    return STRUCTURE;
  }
  
  void serialize(std::string& __str) const {
    // not meant to be serialized
  }
  
  int deserialize(std::istream& is) throw(mace::SerializationException) {
    // not meant to be deserialized
    return 0;
  }
  
  void print(std::ostream& __out) const {
    __out << "Return value: ";
    printItem(__out, &obj);
  }
  
  void sqlize(mace::LogNode* node) const {
    mace::sqlize(&obj, node);
  }
  
  LogNode*& getChildRoot() const { 
    return rootLogNode;
  }
};

template<typename T> T & logVal(T & a, log_id_t out, const std::string& logType) {
  Log::binaryLog(out, mace::SimpleLogObject<T>(logType, a));
  return a;
}

  
template<typename T> T const & logVal(T const & a, log_id_t out, const std::string& logType) {
  Log::binaryLog(out, mace::SimpleLogObject<T>(logType, a));
  return a;
}

}
#endif // __SIMPLE_LOG_OBJECT_H
