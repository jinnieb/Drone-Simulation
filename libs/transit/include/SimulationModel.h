#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
class SimulationModel {
 public:
  SimulationModel(IController& controller);

  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  void CreateEntity(JsonObject& entity);

  /// Schedules a trip for an object in the scene
  void ScheduleTrip(JsonObject& details);

  /// Updates the simulation
  void Update(double dt);

  // Adds a new entity type
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  std::vector<IEntity*> repairStations;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
