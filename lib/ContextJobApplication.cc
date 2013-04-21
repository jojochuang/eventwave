#include "HeadEventDispatch.h"

namespace mace{
  void sampleLatency(bool flag){
    HeadEventDispatch::sampleLatency(true);
  }

  double getAverageLatency(){
    return HeadEventDispatch::getAverageLatency();
  }
  void finishHeadThread(){
    HeadEventDispatch::haltAndWait();
    HeadEventDispatch::haltAndWaitCommit();
  }

}
