#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"

class CompositeFactory : public IEntityFactory {
 public:
    IEntity* CreateEntity(const JsonObject& entity);

    void AddFactory(IEntityFactory* factoryEntity);

    virtual ~CompositeFactory();

 private:
    std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_"
