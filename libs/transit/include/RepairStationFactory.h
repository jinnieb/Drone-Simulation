#ifndef LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RepairStation.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class.
 */
class RepairFactory : public IEntityFactory {
 public:
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_REPAIRSTATIONFACTORY_H_
