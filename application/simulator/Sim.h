#ifndef SIM_H
#define SIM_H

#include "SimCommon.h"

class Sim : public SimCommon {
  public:
    static void init(int nn);
    static void pathComplete(PathEndCause cause, bool isLive, bool isSafe,
                             uint32_t simSteps, uint32_t randSteps,
                             const mace::Printable* const randomUtil,
                             const mace::string& description);

    static void setCurrentNode(int currentNode);
};

#endif // SIM_H
