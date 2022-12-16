#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public IEntity {
 public:
  // Drones are created with a name
  Drone(JsonObject& obj);
  // Destructor
  ~Drone();

  float GetSpeed() const { return speed; }

  // Gets the drone position
  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  std::string GetColor() const { return color; }

  JsonObject GetDetails() const { return details; }

  // float GetHealth() const { return health; }

  bool GetAvailability() const { return available; }

  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the drone's position
  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetPosition(Vector3 pos_) { position = pos_; }

  void SetColor(std::string color_) { color = color_; }

  // Sets the drone's direction
  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  // void SetHealth(float heal) { health = heal; }

  // Rotates a drone
  void Rotate(double angle);

  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None";  // None means default color
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  // float health = 100.0;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
