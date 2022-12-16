#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/**
 * @brief Abstract controller class used in the Transit Service.
 * @details Uses the Model View.
 */
class IEntity {
 public:
  /**
  * @brief Constructor
  **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
  * @brief Destructor
  **/
  virtual ~IEntity() {}
  /**
  * @brief Get ID
  *
  * @return int for id
  */
  virtual int GetId() const { return id; }
  /**
  * @brief Get position
  **/
  virtual Vector3 GetPosition() const = 0;
  /**
  * @brief Get direction
  **/
  virtual Vector3 GetDirection() const = 0;
  /**
  * @brief Get destination
  **/
  virtual Vector3 GetDestination() const = 0;
  /**
  * @brief Get information
  **/
  virtual JsonObject GetDetails() const = 0;
  /**
  * @brief Get color
  *
  * @return a string "None" is a default value
  */
  virtual std::string GetColor() const { return "None"; }
  /**
  * @brief Get speed
  **/
  virtual float GetSpeed() const = 0;
  /**
  * @brief Get availability
  **/
  virtual bool GetAvailability() const {}
  /**
  * @brief Get the name of strategy
  **/
  virtual std::string GetStrategyName() {}
  /**
  * @brief Set availability
  *
  * @param a boolean for availability
  */
  virtual void SetAvailability(bool choice) {}
  /**
  * @brief Update position
  *
  * @param a double for delta time
  * @param b vector of entity pointers
  */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
  * @brief Set color
  *
  * @param a string for color
  */
  virtual void SetColor(std::string color_) {}
  /**
  * @brief Set graph
  *
  * @param a IGraph pointer for graph
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
  * @brief Set position
  *
  * @param a Vector3(3D Vector) for position
  */
  virtual void SetPosition(Vector3 pos_) {}
  /**
  * @brief Set direction
  *
  * @param a Vector3(3D Vector) for direction
  */
  virtual void SetDirection(Vector3 dir_) {}
  /**
  * @brief Set destination
  *
  * @param a Vector3(3D Vector) for destination
  */
  virtual void SetDestination(Vector3 des_) {}
  /**
  * @brief Set the name of strategy
  *
  * @param a string for strategy name
  */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
  * @brief Rotate entity
  *
  * @param a double for rotation angle
  */
  virtual void Rotate(double angle) {}
  /**
  * @brief Add height
  *
  * @param a double for height
  */
  virtual void Jump(double height) {}

 protected:
  /**
  * @brief integer for entity id
  */
  int id;
  /**
  * @brief IGraph pointer for graph
  */
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
