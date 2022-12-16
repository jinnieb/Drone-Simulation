#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"

/**
 * @brief Represents a car in a physical system.
 *
 * @details Car moves using euler integration based on a specified velocity and direction.
 */
class Car : public IEntity {
 public:
  /**
  * @brief Constructor, Cars are created with a name
  *
  * @param a JsonObject
  */
  Car(JsonObject& obj);
  /**
  * @brief Deconstructor
  */
  ~Car() override = default;
  /**
  * @brief Get the car position
  * 
  * @return position as a 3D Vector
  */
  Vector3 GetPosition() const { return position; }
  /**
  * @brief Get the car direction
  * 
  * @return direction as a 3D Vector
  */
  Vector3 GetDirection() const { return direction; }
  /**
  * @brief Get the car destination
  * 
  * @return destination as a 3D Vector
  */
  Vector3 GetDestination() const { return destination; }
  /**
  * @brief Get information of car
  * 
  * @return override information of car as a JsonObject
  */
  JsonObject GetDetails() const override;
  /**
  * @brief Get speed of car
  * 
  * @return speed as a float
  */
  float GetSpeed() const { return speed; }
  /**
  * @brief Set the car's position
  *
  * @param a vector3(3D Vector) for position 
  */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
  * @brief Set the car's direction
  *
  * @param a vector3(3D Vector) for direction 
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
  * @brief Set the car's destination
  *
  * @param a vector3(3D Vector) for destination 
  */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
  * @brief Rotate car
  *
  * @param a double for rotation angle
  */
  void Rotate(double angle);
  /**
  * @brief Update the car's position
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

#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
