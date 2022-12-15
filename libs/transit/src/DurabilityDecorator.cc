#include "DurabilityDecorator.h"

void DurabilityDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    this->SetDurability(9);

    if (this->UtilityDecorator::GetDurability() > 70) {
        this->UtilityDecorator::SetColor("green");
    } 
    else if (this->UtilityDecorator::GetDurability() > 20) {
        this->UtilityDecorator::SetColor("orange");
    }
    else {
        this->UtilityDecorator::SetColor("red");
    }

    if (this->GetDurability() <= 0) {
        delete this->myDrone;
        std::cout << "Drone has broken" << std::endl;
        return;
        // break drone or see if there is any other drone near by that can take the trip and schedule it and return
    }

    // for (auto i: this->repairStations) {
    //     i->GetPosition().Print();
    // }

    std::cout << this->GetDurability() << std::endl;
    if (this->myDrone->GetAvailability()) {
        this->myDrone->Update(dt, scheduler);
        return;
    }

    float dmgTaken = dt * .25;

    if ((this->GetDurability() - dmgTaken) > 10) { 
        this->myDrone->Update(dt, scheduler);
        this->SetDurability(this->GetDurability() - dmgTaken);
        return;
    }

    // figure out how to locate repair stations
    else { // locate nearest repair station and set its destination to that and go to it 
        IEntity* nearestEntity = NULL;
        float minDis = std::numeric_limits<float>::max();
        for (auto entity : this->repairStations) {
            if (!entity->GetAvailability()) {
                float disToEntity = this->myDrone->GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
                minDis = disToEntity;
                nearestEntity = entity;
                }
            }
        }

        if (nearestEntity) {
            // std::cout << "test2" << std::endl;
            // Vector3 oldDestination = this->myDrone->GetDestination();
            // Vector3 repairStat = nearestEntity->GetPosition();
            // this->myDrone->SetDestination(repairStat); // set to repair station
            // Vector3 newDest = this->myDrone->GetDestination();
            // Vector3 pos = this->myDrone->GetPosition();
            // float distToRepair = pos.Distance(repairStat);
            // this->SetDurability(this->GetDurability() - dmgTaken);
            nearestEntity->GetPosition().Print();
            this->myDrone->SetDestination(nearestEntity->GetPosition());
            this->myDrone->GetDestination().Print();
            // dynamic_cast<Drone*>(this->myDrone)->GetNearestEntity(scheduler);
            this->myDrone->Update(dt, scheduler);

            // if (distToRepair < 1) {
            //     this->SetDurability(100.0);
            // }
            
            // this->myDrone->SetDestination(oldDestination);
            // this->myDrone->Update(dt, scheduler);
            // this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - dmgTaken);
        }
    }

}
