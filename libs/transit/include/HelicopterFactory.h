#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class.
 */
class HelicopterFactory : public IEntityFactory {
 public:
    /**
    * @brief Destructor
    **/
    virtual ~HelicopterFactory() {}
    /**
    * @brief Constructor, Creates a helicopter entity based on the JsonObject
    *
    * @param a Json Object
    **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
