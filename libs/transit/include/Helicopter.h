#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"
/**
 * @brief Represents a helicopter in a physical system.
 *
 * @details Drones move using euler integration based on a specified velocity and direction.
 */
class Helicopter : public IEntity {
 public:
  /**
  * @brief Constructor, Helicopter is created with a name
  *
  * @param a JsonObject
  */
  Helicopter(JsonObject& obj);
  /**
  * @brief Deconstructor
  */
  ~Helicopter() override = default;
  /**
  * @brief Get the helicopter position
  * 
  * @return position as a 3D Vector
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the helicopter direction
  * 
  * @return direction as a 3D Vector
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the helicopter destination
  * 
  * @return destination as a 3D Vector
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get information of helicopter
  * 
  * @return override information of helicopter as a JsonObject
  */
  JsonObject GetDetails() const override;
  /**
  * @brief Get speed of helicopter
  * 
  * @return speed as a float
  */
  float GetSpeed() const { return speed; }
  /**
  * @brief Set the helicopter's position
  *
  * @param a vector3(3D Vector) for position 
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the helicopter's direction
  *
  * @param a vector3(3D Vector) for direction 
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the helicopter's destination
  *
  * @param a vector3(3D Vector) for destination 
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Rotate helicopter
  *
  * @param a double for rotation angle
  */
  void Rotate(double angle);
  /**
  * @brief Update the helicopter's position
  *
  * @param a double for delta time
  * @param b vector of entity pointers
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Find a random value between two input values
  *
  * @param a float for minimum
  * @param b float for maximum
  * @return random float value
  */
  float Random(float Min, float Max);
  /**
  * @brief Set new destination with random values
  */
  void SetNewDestination();

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
  * @brief IStrategy pointer for strategy
  */
  IStrategy* strategy = NULL;
  /**
  * @brief float for speed
  */
  float speed;
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
