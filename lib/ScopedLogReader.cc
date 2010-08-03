#include "ScopedLogReader.h"
#include "ScopedStackExecution.h"
#include "DummyServiceMapper.h"

namespace ScopedLogReader_namespace {
  const std::string ScopedLogReader::type = "__SL";
  mace::LogNode* ScopedLogReader::rootLogNode = NULL;
  
  mace::BinaryLogObject* scopedLogFactory() {
    return new ScopedLogReader();
  }
  
  void init() {
    mace::DummyServiceMapper mapper;
    mapper.addFactory(ScopedLogReader::type, &scopedLogFactory);
  }
}

namespace mace {
  const std::string SSEReader::type = "__SSE";
  mace::LogNode* SSEReader::rootLogNode = NULL;
  
  BinaryLogObject* scopedStackExecutionFactory() {
    return new SSEReader();
  }
  
  void SSEReader::init() {
    DummyServiceMapper mapper;
    mapper.addFactory(SSEReader::type, &scopedStackExecutionFactory);
  }
}
