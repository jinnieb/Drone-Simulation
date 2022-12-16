#ifndef LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "Drone.h"
#include "RepairStation.h"
#include "math/vector3.h"

class UtilityDecorator : public IEntity {
 public:
  /**
  * @brief Constructor. Update constuctor to take in a repair station vector
  */
  UtilityDecorator(IEntity *myDrone_, std::vector<IEntity*> repairStations_) {
    this->myDrone = myDrone_;
    this->repairStations = repairStations_;
    this->durability = 100.0;
  }
  /**
  * @brief Get position
  **/
  Vector3 GetPosition() const;
  /**
  * @brief Get direction
  **/
  Vector3 GetDirection() const;
  /**
  * @brief Get destination
  **/
  Vector3 GetDestination() const;
  /**
  * @brief Get information
  **/
  JsonObject GetDetails() const;
  /**
  * @brief Get color
  **/
  std::string GetColor() const;
  /**
  * @brief Get speed
  **/
  float GetSpeed() const;
  /**
  * @brief Get availability
  **/
  bool GetAvailability() const;
  /**
  * @brief Get the name of strategy
  **/
  std::string GetStrategyName();
  /**
  * @brief Get durability
  *
  * @return float for durability
  **/
  float GetDurability() { return durability; }
  /**
  * @brief Set availability
  *
  * @param a boolean for availability
  */
  void SetAvailability(bool choice);
  /**
  * @brief Update position
  *
  * @param a double for delta time
  * @param b vector of entity pointers
  */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
  * @brief Set color
  *
  * @param a string for color
  */
  void SetColor(std::string color_);
  /**
  * @brief Set graph
  *
  * @param a IGraph pointer for graph
  */
  void SetGraph(const IGraph* graph);
  /**
  * @brief Set position
  *
  * @param a Vector3(3D Vector) for position
  */
  void SetPosition(Vector3 pos_);
  /**
  * @brief Set durability
  *
  * @param a float for durability
  */
  void SetDurability(float durability_) { durability = durability_; }
  /**
  * @brief Set repair stations
  *
  * @param a vector of IEntity pointers for repair stations
  */
  void SetRepairStations(std::vector<IEntity*> repairStations_) {
    repairStations = repairStations_;
  }
  /**
  * @brief Set direction
  *
  * @param a Vector3(3D Vector) for direction
  */
  void SetDirection(Vector3 dir_);
  /**
  * @brief Set destination
  *
  * @param a Vector3(3D Vector) for destination
  */
  void SetDestination(Vector3 des_);
  /**
  * @brief Set the name of strategy
  *
  * @param a string for strategy name
  */
  void SetStrategyName(std::string strategyName_);
  /**
  * @brief Rotate entity
  *
  * @param a double for rotation angle
  */
  void Rotate(double angle);
  /**
  * @brief Add height
  *
  * @param a double for height
  */
  void Jump(double height);

 protected:
 /**
  * @brief IEntity pointer for drone
  */
  IEntity *myDrone;
   /**
  * @brief vector of IEntity pointers for repair stations
  * @details implement this once the repair station code is created
  */
  std::vector<IEntity*> repairStations;
 /**
  * @brief float for durability
  */
  float durability;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_UTILITYDECORATOR_H_
