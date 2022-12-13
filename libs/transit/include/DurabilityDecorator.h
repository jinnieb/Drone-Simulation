#ifndef DURABILITY_DECORATOR_H_
#define DURABILITY_DECORATOR_H_

#include "UtilityDecorator.h"

class DurabilityDecorator : public UtilityDecorator {
 public:
  DurabilityDecorator(Drone* myDrone_, std::vector<Repair*> *repairStations_) : UtilityDecorator(myDrone_, repairStations_) {}

  Vector3 GetPosition() const;

  Vector3 GetDirection() const;

  Vector3 GetDestination() const;

  JsonObject GetDetails() const;

  std::string GetColor() const;

  float GetSpeed() const;

  bool GetAvailability() const;

  std::string GetStrategyName();

  void SetAvailability(bool choice);

  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetColor(std::string color_);

  void SetGraph(const IGraph* graph);

  void SetPosition(Vector3 pos_);

  void SetDirection(Vector3 dir_);

  void SetDestination(Vector3 des_);

  void SetStrategyName(std::string strategyName_);

  void Rotate(double angle);

  void Jump(double height);

};  // close class

#endif  // DURABILITY_DECORATOR_H_