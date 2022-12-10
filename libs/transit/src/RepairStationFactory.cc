#include "RepairStationFactory.h"

IEntity* RepairFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("repair") == 0){
    std::cout << "Repair Station Created" << std::endl;
    return new Repair(entity);
  }
  return nullptr;
}