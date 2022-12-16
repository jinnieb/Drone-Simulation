#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class SpinDecorator : public CelebrationDecorator {
 public:
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  bool IsCompleted();
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
