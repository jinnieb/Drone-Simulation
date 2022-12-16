#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class.
 */
class RobotFactory : public IEntityFactory {
 public:
    /**
    * @brief Constructor, Creates a robot entity based on the JsonObject
    *
    * @param a Json Object
    **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
