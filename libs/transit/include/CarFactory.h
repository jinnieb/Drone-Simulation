#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>
/**
 * @brief this class inhertis from the IEntityFactory class.
 */
class CarFactory : public IEntityFactory {
 public:
    /**
    * @brief Destructor
    **/
    virtual ~CarFactory() {}
    /**
    * @brief Constructor, Creates a car entity based on the JsonObject
    *
    * @param a Json Object
    **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
