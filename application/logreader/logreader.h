#ifndef H_LOGREADER
#define H_LOGREADER

#include <iostream>
#include <fstream>
#include "m_map.h"
#include "DummyServiceMapper.h"

// Parse modes define the different ways in which the log reader can parse binary 
// log data. They must be declared as numbers > 0, although continuity in the 
// numbering of parse modes isn't necessary.

#define PARSE_MODE_NORMAL 0
#define PARSE_MODE_SQL 1

using mace::Serializable;
using mace::BinaryLogObject;
using mace::DummyServiceMapper;
using mace::SerializationException;

typedef mace::map<log_id_t, std::string> SelectorMap;

typedef struct log_info {
  double timestamp;
  unsigned int tid;
  std::string log_type;
  std::string selector;
} LogInfo;

void printUsage();
std::string sqlSanitize(std::string &s);

int outputSHeader(std::ostream &outs);
int outputDumpHeader(std::ostream &outs);
int outputSLog(std::istream &ifs, std::ostream &outStream, LogInfo &info);
int outputDumpLog(std::istream &ifs, std::ostream &outStream, LogInfo &info, 
  BinaryLogObject *obj);

int outputBinaryLog(std::istream &ifs, 
                    std::ostream &sOutputStream, 
                    std::ostream &dumpOutputStream, 
                    DummyServiceMapper &dummyServiceMapper, 
                    SelectorMap &selectors);


#endif
