#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>

class HelicopterFactory : public IEntityFactory {
  public:
    virtual ~HelicopterFactory() {}
    IEntity* CreateEntity(JsonObject& entity);
};

#endif