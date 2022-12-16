#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

class IEntityFactory {
 public:
    virtual ~IEntityFactory() {}
    virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
