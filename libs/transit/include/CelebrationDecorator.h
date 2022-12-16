#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"
 /**
 * @brief this class inhertis from the IStrategy class.
 **/
class CelebrationDecorator : public IStrategy {
 public:
  /**
  * @brief Constructor, set the time to 0.
  *
  * @param a An IStrategy pointer for strategy.
  */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
   /**
   * @brief Check if previous strategy has completed, if so, do current strategy movement (i.e., spin and/or jump)
   *
   * @param a An IEntity pointer for entity.
   * @param b A double value for delta time.
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Check if current strategy has completed. 
   *
   * @return A boolean value.
   */
  bool IsCompleted();

 protected:
   /**
   * @brief IStrategy that we want to add current decorator onto
   */
  IStrategy *strategy;
  /**
   * @brief time count check how long has the celebration has occurred
   */
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
