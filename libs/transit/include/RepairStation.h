#ifndef LIBS_TRANSIT_INCLUDE_REPAIRSTATION_H_
#define LIBS_TRANSIT_INCLUDE_REPAIRSTATION_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

class Repair : public IEntity {
 public:
  Repair(JsonObject& obj);

  ~Repair() override = default;

  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  bool GetAvailability() const { return available; }

  JsonObject GetDetails() const override;

  float GetSpeed() const { return speed; }

  std::string GetStrategyName() {return strategyName;}

  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  void SetAvailability(bool choice) {available = choice;}

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName = "astar";
};

#endif  // LIBS_TRANSIT_INCLUDE_REPAIRSTATION_H_
