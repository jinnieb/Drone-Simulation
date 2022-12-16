#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief Represents a robot in a physical system.
 *
 * @details Robot moves using euler integration based on a specified velocity and direction.
 */
class Robot : public IEntity {
 public:
  /**
  * @brief Constructor, Robot is created with a name
  *
  * @param a JsonObject
  */
  Robot(JsonObject& obj);
  /**
  * @brief Deconstructor
  */
  ~Robot() override = default;
  /**
  * @brief Get the robot position
  * 
  * @return position as a 3D Vector
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the robot direction
  * 
  * @return direction as a 3D Vector
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the robot destination
  * 
  * @return destination as a 3D Vector
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get the robot availablity
  * 
  * @return availablity as a boolean
  */
  bool GetAvailability() const { return available; }
  /**
  * @brief Get the robot information
  * 
  * @return override the robot information as a JsonObject
  */
  JsonObject GetDetails() const override;
  /**
  * @brief Get speed of robot
  * 
  * @return speed as a float
  */
  float GetSpeed() const { return speed; }
  /**
  * @brief Get strategy name used by the robot
  * 
  * @return strategy name as a string
  */
  std::string GetStrategyName() {return strategyName;}
  /**
  * @brief Set the availability of robot
  *
  * @param a boolean for availability
  */
  void SetAvailability(bool choice);
  /**
  * @brief Set the robot's position
  *
  * @param a vector3(3D Vector) for position
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the robot's direction
  *
  * @param a vector3(3D Vector) for direction
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the robot's destination
  *
  * @param a vector3(3D Vector) for destination
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Set the robot's strategy name
  *
  * @param a string for strategy name
  */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
  * @brief Rotate robot
  *
  * @param a double for rotation angle
  */
  void Rotate(double angle);

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
  * @brief string for strategy name
  */
  std::string strategyName;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_
