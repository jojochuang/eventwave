#include "Pipeline.h"

uint8_t FlowPipeline::pipelineCount = 0;
mace::LogNode* FlowLog::rootLogNode = NULL;
uint64_t LogicalClockPipeline::maxId = 0;
mace::LogNode* LogicalClockPipeline::MessageId::rootLogNode = NULL;
