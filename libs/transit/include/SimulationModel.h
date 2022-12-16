#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.
 * @details The model can communicate with the controller.
 */
class SimulationModel {
 public:
  /**
  * @brief Constructor, Simulation Model is created.
  *
  * @param a IController
  */
  SimulationModel(IController& controller);
  /**
  * @brief Set graph
  *
  * @param a IGraph pointer for graph 
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
  * @brief Creates an simulation entity
  *
  * @param a JsonObject
  */
  void CreateEntity(JsonObject& entity);
  /**
  * @brief Schedules a trip for an object in the scene
  *
  * @param a JsonObject for details
  */
  void ScheduleTrip(JsonObject& details);
  /**
  * @brief Updates the simulation
  *
  * @param a double for delta time
  */
  void Update(double dt);
  /**
  * @brief Adds a new entity type
  *
  * @param a IEntityFactory pointer for factory
  */
  void AddFactory(IEntityFactory* factory);

 protected:
  /**
  * @brief IController reference for controller
  */
  IController& controller;
  /**
  * @brief vector of IEntity pointers for entities
  */
  std::vector<IEntity*> entities;
  /**
  * @brief vector of IEntity pointers for scheduler
  */
  std::vector<IEntity*> scheduler;
  /**
  * @brief vector of IEntity pointers for repair stations
  */
  std::vector<IEntity*> repairStations;
  /**
  * @brief IGraph pointer for graph
  */
  const IGraph* graph;
  /**
  * @brief CompositeFactory pointer
  */
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
