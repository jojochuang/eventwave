#include "MatchingReader.h"
#include "DummyServiceMapper.h"

namespace MatchingReader_namespace {
  const std::string MatchingReader::type = "__M";
  mace::LogNode* MatchingReader::rootLogNode = NULL;
  
  mace::BinaryLogObject* matchingFactory() {
    return new MatchingReader();
  }
  
  void init() {
    mace::DummyServiceMapper mapper;
    mapper.addFactory(MatchingReader::type, &matchingFactory);
  }
}
