#include "DurabilityDecorator.h"

void DurabilityDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    
    // if (this->GetDurability() <= 0) {
    //     delete this->myDrone;
    //     std::cout << "Drone has broken" << std::endl;
    //     return;
    //     // break drone or see if there is any other drone near by that can take the trip and schedule it and return
    // }
    this->myDrone->Update(dt, scheduler);

    // std::cout << "test3" << std::endl;
    // Vector3 pos = this->myDrone->GetPosition();
    // Vector3 dest = this->myDrone->GetDestination();

    // float dist = pos.Distance(dest);
    // float dmgTaken = dist * .1;
    // std::cout << dist << std::endl;
    // std::cout << this->GetDurability() << std::endl;

    // if (this->GetDurability() - dmgTaken > 0) { 
    //     this->myDrone->Update(dt, scheduler);
    //     std::cout << "test4" << std::endl;
    //     this->SetDurability(this->GetDurability() - dmgTaken);
    // }

    // // figure out how to locate repair stations
    // else { // locate nearest repair station and set its destination to that and go to it 
    //     std::cout << "test5" << std::endl;
    //     IEntity* nearestEntity = NULL;
    //     float minDis = std::numeric_limits<float>::max();
    //     for (auto entity : this->repairStations) {
    //         if (entity->GetAvailability()) {
    //             float disToEntity = this->myDrone->GetPosition().Distance(entity->GetPosition());
    //         if (disToEntity <= minDis) {
    //             minDis = disToEntity;
    //             nearestEntity = entity;
    //             }
    //         }
    //     }

    //     if (nearestEntity) {
    //         std::cout << "test6" << std::endl;
    //         Vector3 oldDestination = this->myDrone->GetDestination();
    //         Vector3 destination = nearestEntity->GetPosition();
    //         this->myDrone->SetDestination(destination); // set to repair station
    //         Vector3 newDest = this->myDrone->GetDestination();
    //         float newDist = pos.Distance(newDest);
    //         float newDmgTaken = newDist * .1;
    //         this->SetDurability(this->GetDurability() - newDmgTaken);
    //         this->myDrone->Update(dt, scheduler);

    //         if (newDist < 1) {
    //             this->SetDurability(100.0);
    //             // while (this->UtilityDecorator::GetDurability() <= 100) {
    //             //     if (this->UtilityDecorator::GetDurability() + (dt*10) > 100) {
    //             //         this->UtilityDecorator::SetDurability(100.0);
    //             //     }
    //             //     else {
    //             //         this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() + (dt*10));
    //             //     }
    //             // }
    //         }
            
    //         this->myDrone->SetDestination(oldDestination);
    //         this->myDrone->Update(dt, scheduler);
    //         this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - dmgTaken);
    //     }
    // }

    // if (this->UtilityDecorator::GetDurability() > 66) {
    //     this->UtilityDecorator::SetColor("green");
    // } 
    // else if (this->UtilityDecorator::GetDurability() > 33) {
    //     this->UtilityDecorator::SetColor("orange");
    // }
    // else {
    //     this->UtilityDecorator::SetColor("red");
    // }

}
