#ifndef UTILITY_DECORATOR_H_
#define UTILITY_DECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "Drone.h"
#include "math/vector3.h"

class UtilityDecorator : public IEntity {
 public:
  UtilityDecorator(Drone *myDrone_) {
    this->myDrone = myDrone_;
  }

  Vector3 GetPosition() const;

  Vector3 GetDirection() const;

  Vector3 GetDestination() const;

  JsonObject GetDetails() const;

  std::string GetColor() const;

  float GetSpeed() const;

  bool GetAvailability() const;

  std::string GetStrategyName();

  float GetDurability() { return durability; };

  void SetAvailability(bool choice);

  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetGraph(const IGraph* graph);

  void SetPosition(Vector3 pos_);

  void SetDurability(float durability_) { durability = durability_; };

  void SetDirection(Vector3 dir_);

  void SetDestination(Vector3 des_);

  void SetStrategyName(std::string strategyName_);

  void Rotate(double angle);

  void Jump(double height);

 protected:
  IEntity *myDrone;
  float durability;
};  // close class

#endif  // UTILITY_DECORATOR_H_