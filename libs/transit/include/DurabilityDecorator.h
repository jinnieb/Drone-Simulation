#ifndef DURABILITY_DECORATOR_H_
#define DURABILITY_DECORATOR_H_

#include "UtilityDecorator.h"

class DurabilityDecorator : public UtilityDecorator {
 public:
  DurabilityDecorator(IEntity* myDrone_, std::vector<IEntity*> repairStations_) : UtilityDecorator(myDrone_, repairStations_) {}

  void Update(double dt, std::vector<IEntity*> scheduler);

};  // close class

#endif  // DURABILITY_DECORATOR_H_