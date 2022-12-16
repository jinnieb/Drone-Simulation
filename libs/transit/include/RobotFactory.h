#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

class RobotFactory : public IEntityFactory {
 public:
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
