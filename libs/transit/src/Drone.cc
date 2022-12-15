#define _USE_MATH_DEFINES
#include "Drone.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

#include <cmath>
#include <limits>

Drone::Drone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Drone::~Drone() {
  // Delete dynamically allocated variables
}

void Drone::GetNearestEntity(std::vector<IEntity*> scheduler) {
  std::cout << "testing" << std::endl;
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }

  if(nearestEntity){
    std::cout << "testing2" << std::endl;
    nearestEntity->SetAvailability(false);  // set availability to the nearest entity
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();
    std::cout << "testing4" << std::endl;
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    std::string targetStrategyName = nearestEntity->GetStrategyName();
    std::cout << "testing3" << std::endl;
    if(targetStrategyName.compare("astar") == 0){
        toTargetDestStrategy = new AstarStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dfs") == 0){
        toTargetDestStrategy = new DfsStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dijkstra") == 0){
        toTargetDestStrategy = new DijkstraStrategy(nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
        toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
        toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } 
    std::cout << "testing5" << std::endl;
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler) {
  if (available) {
    GetNearestEntity(scheduler);
  }
  if(toTargetPosStrategy){
    toTargetPosStrategy->Move(this, dt);
    if(toTargetPosStrategy->IsCompleted()){
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
      color = "#fa0003"; // changes color to red when picked up
    }
  } else if (toTargetDestStrategy) {
    toTargetDestStrategy->Move(this, dt);
    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if(toTargetDestStrategy->IsCompleted()){
        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
        nearestEntity = NULL;
        color = "None"; // resets color when trip is complete
    }
  }
}

void Drone::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Drone::Jump(double height) {
  if(goUp){
    position.y += height;
    jumpHeight += height;
    if(jumpHeight > 5){
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if(jumpHeight < 0){
      goUp = true;
    }
  }
}
