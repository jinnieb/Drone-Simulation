#ifndef UTILITY_DECORATOR_H_
#define UTILITY_DECORATOR_H_

#include <vector>

#include "IEntity.h"

class UtilityDecorator : public IEntity {
 public:
  UtilityDecorator(Drone* myDrone_) {
    this->myDrone = myDrone_;
  }

  Vector3 GetPosition() const {};

  Vector3 GetDirection() const {};

  Vector3 GetDestination() const {};

  JsonObject GetDetails() const {};

  std::string GetColor() const {};

  float GetSpeed() const {};

  bool GetAvailability() const {};

  std::string GetStrategyName() {};

  void SetAvailability(bool choice) {};

  void Update(double dt, std::vector<IEntity*> scheduler) {};

  void SetGraph(const IGraph* graph) {};

  void SetPosition(Vector3 pos_) {};

  void SetDirection(Vector3 dir_) {};

  void SetDestination(Vector3 des_) {};

  void SetStrategyName(std::string strategyName_) {};

  void Rotate(double angle) {};

  void Jump(double height) {};

 protected:
  IEntity *myDrone;
};  // close class

#endif  // UTILITY_DECORATOR_H_