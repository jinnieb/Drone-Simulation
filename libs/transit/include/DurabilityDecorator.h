#ifndef LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_

#include "UtilityDecorator.h"

class DurabilityDecorator : public UtilityDecorator {
 public:
  DurabilityDecorator(IEntity* myDrone_, std::vector<IEntity*>
  repairStations_) :UtilityDecorator(myDrone_, repairStations_) {}

  void Update(double dt, std::vector<IEntity*> scheduler);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_
