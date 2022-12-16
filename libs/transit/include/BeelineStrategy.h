#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
    BeelineStrategy(Vector3 position, Vector3 destination);
    ~BeelineStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();

 private:
    /**
    * @brief Vector3(3D Vector) for position
    */
    Vector3 position;
    /**
    * @brief Vector3(3D Vector) for destination
    */
    Vector3 destination;
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
