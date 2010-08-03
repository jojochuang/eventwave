#include "ParamReader.h"
#include "DummyServiceMapper.h"

namespace ParamReader_namespace {
  const std::string ParamReader::type = "__P";
  mace::LogNode* ParamReader::rootLogNode = NULL;
  
  mace::BinaryLogObject* paramFactory() {
    return new ParamReader();
  }
  
  void init() {
    mace::DummyServiceMapper mapper;
    mapper.addFactory(ParamReader::type, &paramFactory);
  }
}
