#ifndef LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "Drone.h"
#include "RepairStation.h"
#include "math/vector3.h"

class UtilityDecorator : public IEntity {
 public:
  // update constuctor to take in a repair station vector
  UtilityDecorator(IEntity *myDrone_, std::vector<IEntity*> repairStations_) {
    this->myDrone = myDrone_;
    this->repairStations = repairStations_;
    this->durability = 100.0;
  }

  Vector3 GetPosition() const;

  Vector3 GetDirection() const;

  Vector3 GetDestination() const;

  JsonObject GetDetails() const;

  std::string GetColor() const;

  float GetSpeed() const;

  bool GetAvailability() const;

  std::string GetStrategyName();

  float GetDurability() { return durability; }

  void SetAvailability(bool choice);

  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetColor(std::string color_);

  void SetGraph(const IGraph* graph);

  void SetPosition(Vector3 pos_);

  void SetDurability(float durability_) { durability = durability_; }

  void SetRepairStations(std::vector<IEntity*> repairStations_) {
    repairStations = repairStations_;
  }

  void SetDirection(Vector3 dir_);

  void SetDestination(Vector3 des_);

  void SetStrategyName(std::string strategyName_);

  void Rotate(double angle);

  void Jump(double height);

 protected:
  IEntity *myDrone;
  // implement this once the repair station code is created
  std::vector<IEntity*> repairStations;
  float durability;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_
