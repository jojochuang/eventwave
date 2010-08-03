#include "MethodMap.h"
#include "DummyServiceMapper.h"

namespace MethodMap_namespace {
  const std::string MethodMap::type = "__MM";
  mace::LogNode* MethodMap::rootLogNode = NULL;
  
  mace::BinaryLogObject* methodMapFactory() {
    return new MethodMap();
  }
  
  void init() {
//     mace::DummyServiceMapper mapper;
//     mapper.addFactory(MethodMap::type, &methodMapFactory);
  }
}
