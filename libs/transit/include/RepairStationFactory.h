#ifndef LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RepairStation.h"

#include <vector>

class RepairFactory : public IEntityFactory {
 public:
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_
