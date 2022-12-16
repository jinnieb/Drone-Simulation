#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class.
 */
class DroneFactory : public IEntityFactory {
 public:
    /**
    * @brief Destructor
    **/
    virtual ~DroneFactory() {}
    /**
    * @brief Constructor, Creates a drone entity based on the JsonObject
    *
    * @param a Json Object
    **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
