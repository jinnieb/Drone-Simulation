#ifndef LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_

#include "UtilityDecorator.h"
/**
 * @brief this class inhertis from the UtilityDecorator class.
 */
class DurabilityDecorator : public UtilityDecorator {
 public:
  /**
  * @brief Decorator for durability
  **/
  DurabilityDecorator(IEntity* myDrone_, std::vector<IEntity*>
  repairStations_) :UtilityDecorator(myDrone_, repairStations_) {}
  /**
  * @brief Update the drone's durability
  *
  * @param a double for delta time
  * @param b vector of entity pointers
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_DURABILITYDECORATOR_H_
