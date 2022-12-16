#include "DurabilityDecorator.h"

void DurabilityDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    if (this->UtilityDecorator::GetDurability() > 70) {
        this->UtilityDecorator::SetColor("green");
    } else if (this->UtilityDecorator::GetDurability() > 20) {
        this->UtilityDecorator::SetColor("orange");
    } else {
        this->UtilityDecorator::SetColor("red");
    }

    if (this->GetDurability() <= 0) {
        delete this->myDrone;
        std::cout << "Drone has broken" << std::endl;
        return;
        // break drone or see if there is any other drone
        // near by that can take the trip and schedule it and return
    }

    float dmgTaken = dt * .25;

    if (!this->myDrone->GetAvailability()) {
        for (auto repair : this->repairStations) {
            if (this->myDrone->GetPosition().
            Distance(repair->GetPosition()) < 10) {
                this->SetDurability(100);
                repair->SetAvailability(false);
            }
        }
        this->myDrone->Update(dt, scheduler);
        this->SetDurability(this->GetDurability() - dmgTaken);
        return;
    }

    // std::cout << this->GetDurability() << std::endl;
    if (this->myDrone->GetAvailability() && this->GetDurability() > 20) {
        this->myDrone->Update(dt, scheduler);
        return;
    } else if (this->myDrone->GetAvailability() &&
    this->GetDurability() < 20) {
        // figure out how to locate repair stations
        // locate nearest repair station and
        // set its destination to that and go to it
        IEntity* nearestEntity = NULL;
        float minDis = std::numeric_limits<float>::max();
        for (auto entity : this->repairStations) {
            if (!entity->GetAvailability()) {
                float disToEntity = this->myDrone->GetPosition().
                Distance(entity->GetPosition());
                if (disToEntity <= minDis) {
                    minDis = disToEntity;
                    nearestEntity = entity;
                }
            }
        }

        if (nearestEntity) {
            nearestEntity->SetAvailability(true);
            float distToRepair = this->myDrone->GetPosition().
            Distance(nearestEntity->GetPosition());
            this->myDrone->SetDestination(nearestEntity->GetPosition());
            this->myDrone->Update(dt, scheduler);
        }
    }
}
