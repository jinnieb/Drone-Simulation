#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

class IStrategy {
 public:
    virtual void Move(IEntity* entity, double dt) = 0;
    virtual bool IsCompleted() = 0;
 protected:
    // IGraph object to be used in the simulation.
    const IGraph* graph;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
