#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief Represents a drone in a physical system.
 *
 * @details  Drones move using euler integration based on a specified velocity and direction.
 */
class Drone : public IEntity {
 public:
 /**
  * @brief Constructor, Drones are created with a name
  *
  * @param a JsonObject
  */
  Drone(JsonObject& obj);
  /**
  * @brief Deconstructor
  */
  ~Drone();
  /**
  * @brief Get speed of drone
  * 
  * @return speed as a float
  */
  float GetSpeed() const { return speed; }
  /**
  * @brief Get the drone position
  * 
  * @return position as a 3D Vector
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the drone direction
  * 
  * @return position as a 3D Vector
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the drone destination
  * 
  * @return destination as a 3D Vector
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the drone color
  * 
  * @return color as a string
  */
  std::string GetColor() const { return color; }
  /**
  * @brief Get information of drone
  * 
  * @return information of drone as a Json
  */
  JsonObject GetDetails() const { return details; }

  // float GetHealth() const { return health; }

  /**
  * @brief Get the availability of drone
  * 
  * @return availability as a boolean
  */
  bool GetAvailability() const { return available; }
  /**
  * @brief Find the nearest entity
  *
  * @param a vector of entity pointers
  */
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
  * @brief Update the drone's position
  *
  * @param a double for delta time
  * @param b vector of entity pointers
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Set the drone's position
  *
  * @param a vector3(3D Vector) for position 
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the drone's color
  *
  * @param a string for color
  */
  void SetColor(std::string color_) { color = color_; }
  /**
  * @brief Sets the drone's direction
  *
  * @param a vector3(3D Vector) for direction
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Sets the drone's destination
  *
  * @param a vector3(3D Vector) for destination
  */
  void SetDestination(Vector3 des_) { destination = des_; }

  // void SetHealth(float heal) { health = heal; }

  /**
  * @brief Rotate drone
  *
  * @param a double for rotation angle
  */
  void Rotate(double angle);
  /**
  * @brief Add height to drone
  *
  * @param a double for height
  */
  void Jump(double height);

  /**
  * @brief Removing the copy constructor and assignment operator  so that Helicopter cannot be coppied.
  *
  * @param a Drone
  */
  Drone(const Drone& drone) = delete;
  /**
  * @brief Removing the copy constructor and assignment operator  so that Helicopter cannot be coppied.
  *
  * @param a Drone
  * @return Drone address
  */
  Drone& operator=(const Drone& drone) = delete;

 private:
  /**
  * @brief JsonObject for detail information
  */
  JsonObject details;
  /**
  * @brief Vector3(3D Vector) for position
  */
  Vector3 position;
  /**
  * @brief Vector3(3D Vector) for direction
  */
  Vector3 direction;
  /**
  * @brief string for color. Set "None" as a default.
  */
  std::string color = "None";  // None means default color
  /**
  * @brief float for jump height. Set 0 as a default.
  */
  float jumpHeight = 0;
  /**
  * @brief boolean for help to jump
  */
  bool goUp = true;  // jump helper
  /**
  * @brief Vector3(3D Vector) for destination
  */
  Vector3 destination;
  /**
  * @brief float for speed
  */
  float speed;
  /**
  * @brief boolean for availablity
  */
  bool available;
  /**
  * @brief boolean for pick up status
  */
  bool pickedUp;

  // float health = 100.0;

  /**
  * @brief string for strategy name
  */
  std::string strategyName;
  /**
  * @brief IEntity pointer for the nearest entity
  */
  IEntity* nearestEntity = NULL;
  /**
  * @brief IStrategy pointer of strategy for a target position
  */
  IStrategy* toTargetPosStrategy = NULL;
  /**
  * @brief IStrategy pointer of strategy for a target destination
  */
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
