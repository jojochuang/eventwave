#include "StringLogReader.h"
#include "DummyServiceMapper.h"

namespace StringLogReader_namespace {
  const std::string StringLogReader::type = "S";
  mace::LogNode* StringLogReader::rootLogNode = NULL;
  
  mace::BinaryLogObject* stringLogFactory() {
    return new StringLogReader();
  }
  
  void init() {
    mace::DummyServiceMapper mapper;
    mapper.addFactory(StringLogReader::type, &stringLogFactory);
  }
}
