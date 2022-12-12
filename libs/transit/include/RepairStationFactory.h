#ifndef REPAIR_FACTORY_H_
#define REPAIR_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RepairStation.h"

#include <vector>

class RepairFactory : public IEntityFactory {
  public:
    IEntity* CreateEntity(JsonObject& entity);
};

#endif