#ifndef _MATCHING_READER_H
#define _MATCHING_READER_H

#include "BinaryLogObject.h"
#include "Log.h"

namespace MatchingReader_namespace {

  class MatchingReader : public mace::BinaryLogObject, public mace::PrintPrintable {
  public:
    static const std::string type;
    log_id_t id;
    std::string selector;
    
    MatchingReader(log_id_t i = 0, const std::string& sel = "") : 
      id(i), selector(sel) {
    }

  protected:
    static mace::LogNode* rootLogNode;
    
  public:
    void sqlize(mace::LogNode* node) const {
      int index = node->nextIndex();
      
      if (index == 0) {
	std::ostringstream out;
	out << "CREATE TABLE " << node->logName
	    << " (_id INT PRIMARY KEY, id INT, selector TEXT);" 
	    << std::endl;
	Log::logSqlCreate(out.str(), node);
      }
      std::ostringstream out;
      out << node->logId << "\t" << index << "\t" << id << "\t" 
	  << selector << std::endl;
      ASSERT(fwrite(out.str().c_str(), out.str().size(), 1, node->file) > 0);
    }
    
    void serialize(std::string& __str) const {
      mace::serialize(__str, &id);
      mace::serialize(__str, &selector);
    }
    
    int deserialize(std::istream& is) throw(mace::SerializationException) {
      int bytes = 0;
      
      bytes += mace::deserialize(is, &id);
      bytes += mace::deserialize(is, &selector);
      
      return bytes;
    }
    
    void print(std::ostream& __out) const {
    }

    const std::string& getLogType() const {
      return type;
    }

    const std::string& getLogDescription() const {
      static const std::string desc = "Matching";
      return desc;
    }

    LogClass getLogClass() const {
      return MATCHING;
    }
    
    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }
  };
  
  void init();
}

#endif // _MATCHING_READER_H
