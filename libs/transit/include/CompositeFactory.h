#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"
 /**
 * @brief this class inhertis from the IEntityFactory class.
 **/
class CompositeFactory : public IEntityFactory {
 public:
   /**
    * @brief Constructor, Creates an entity based on the JsonObject
    *
    * @param a Json Object
    **/
    IEntity* CreateEntity(JsonObject& entity);
   /**
    * @brief Add factory to an input factory entity
    *
    * @param a IEntityFactory pointer
    **/
    void AddFactory(IEntityFactory* factoryEntity);
    /**
    * @brief Destructor
    **/
    virtual ~CompositeFactory();

 private:
    /**
    * @brief pointers of IEntity component factories as a vector
    **/
    std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_"
