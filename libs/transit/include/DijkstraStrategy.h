#ifndef LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_

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
class DijkstraStrategy : public IStrategy {
 public:
    DijkstraStrategy(Vector3 position,
    Vector3 destination, const IGraph* graph);
    ~DijkstraStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();

 private:
    /**
    * @brief vector of vector for float vaule path
    */
    std::vector<std::vector<float>> path;
    /**
    * @brief integer for current index
    */
    int currentIndex;
    /**
    * @brief integer for the max index
    */
    int maxIndex;
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_DIJKSTRASTRATEGY_H_
