#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class JumpDecorator : public CelebrationDecorator {
 public:
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  bool IsCompleted();
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
