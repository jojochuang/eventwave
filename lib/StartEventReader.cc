#include "StartEventReader.h"
#include "DummyServiceMapper.h"

namespace StartEventReader_namespace {
  const std::string& StartEventReader::type() {
    static const std::string* type = new std::string("__SE");
    return *type;
  }
  mace::LogNode* StartEventReader::rootLogNode = NULL;
  
  mace::BinaryLogObject* startEventFactory() {
    return new StartEventReader();
  }
  
  void init() {
    mace::DummyServiceMapper mapper;
    mapper.addFactory(StartEventReader::type(), &startEventFactory);
  }
}
