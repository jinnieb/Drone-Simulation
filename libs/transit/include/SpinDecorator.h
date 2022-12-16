#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

class SpinDecorator : public CelebrationDecorator {
 public:
  /**
  * @brief Decorator for spin
  **/
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
  * @brief boolean for spin status 
  **/
  bool IsCompleted();
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
