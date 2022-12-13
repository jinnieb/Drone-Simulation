#include "DurabilityDecorator.h"

Vector3 DurabilityDecorator::GetPosition() const {
    return this->UtilityDecorator::GetPosition();
}

Vector3 DurabilityDecorator::GetDirection() const {
    return this->UtilityDecorator::GetDirection();
}

Vector3 DurabilityDecorator::GetDestination() const {
    return this->UtilityDecorator::GetDestination();
}

JsonObject DurabilityDecorator::GetDetails() const {
    return this->UtilityDecorator::GetDetails();
}

std::string DurabilityDecorator::GetColor() const {
    return this->UtilityDecorator::GetColor();
}

float DurabilityDecorator::GetSpeed() const {
    return this->UtilityDecorator::GetSpeed();
}

bool DurabilityDecorator::GetAvailability() const {
    return this->UtilityDecorator::GetAvailability();
}

std::string DurabilityDecorator::GetStrategyName() {
    return this->UtilityDecorator::GetStrategyName();
}

void DurabilityDecorator::SetAvailability(bool choice) {
    this->UtilityDecorator::SetAvailability(choice);
}

void DurabilityDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    if (this->UtilityDecorator::GetDurability() <= 0) {
        delete this->UtilityDecorator::myDrone;
        std::cout << "Drone has broken" << std::endl;
        return;
        // break drone or see if there is any other drone near by that can take the trip and schedule it and return
    }

    Vector3 pos = this->UtilityDecorator::GetPosition();
    Vector3 dest = this->UtilityDecorator::GetDestination();

    float dist = pos.Distance(dest);
    float dmgTaken = dist * .7;

    if (this->UtilityDecorator::GetDurability() - dmgTaken > 0) { 
        this->UtilityDecorator::Update(dt, scheduler);
        this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - dmgTaken);
    }

    // figure out how to locate repair stations
    else { // locate nearest repair station and set its destination to that and go to it 

        IEntity* nearestEntity = NULL;
        float minDis = std::numeric_limits<float>::max();
        for (auto entity : this->UtilityDecorator::repairStations) {
            if (entity->GetAvailability()) {
                float disToEntity = this->UtilityDecorator::GetPosition().Distance(entity->GetPosition());
            if (disToEntity <= minDis) {
                minDis = disToEntity;
                nearestEntity = entity;
                }
            }
        }

        if (nearestEntity) {
            Vector3 oldDestination = this->UtilityDecorator::GetDestination();
            Vector3 destination = nearestEntity->GetPosition();
            this->UtilityDecorator::SetDestination(destination); // set to repair station
            Vector3 newDest = this->UtilityDecorator::GetDestination();
            float newDist = pos.Distance(newDest);
            float newDmgTaken = newDist * .7;
            this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - newDmgTaken);
            this->UtilityDecorator::Update(dt, scheduler);

            if (newDist < 1) {
                this->UtilityDecorator::SetDurability(100.0);
                // while (this->UtilityDecorator::GetDurability() <= 100) {
                //     if (this->UtilityDecorator::GetDurability() + (dt*10) > 100) {
                //         this->UtilityDecorator::SetDurability(100.0);
                //     }
                //     else {
                //         this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() + (dt*10));
                //     }
                // }
            }
            
            this->UtilityDecorator::SetDestination(oldDestination);
            this->UtilityDecorator::Update(dt, scheduler);
            this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - dmgTaken);
        }
    }

    if (this->UtilityDecorator::GetDurability() > 66) {
        this->UtilityDecorator::SetColor("green");
    } 
    else if (this->UtilityDecorator::GetDurability() > 33) {
        this->UtilityDecorator::SetColor("orange");
    }
    else {
        this->UtilityDecorator::SetColor("red");
    }

}

void DurabilityDecorator::SetGraph(const IGraph* graph) {
    this->UtilityDecorator::SetGraph(graph);
}

void DurabilityDecorator::SetColor(std::string color_) {
    this->UtilityDecorator::SetColor(color_);
}

void DurabilityDecorator::SetPosition(Vector3 pos_) {
    this->UtilityDecorator::SetPosition(pos_);
}

void DurabilityDecorator::SetDirection(Vector3 dir_) {
    this->UtilityDecorator::SetDirection(dir_);
}

void DurabilityDecorator::SetDestination(Vector3 des_) {
    this->UtilityDecorator::SetDestination(des_);
}

void DurabilityDecorator::SetStrategyName(std::string strategyName_) {
    this->UtilityDecorator::SetStrategyName(strategyName_);
}

void DurabilityDecorator::Rotate(double angle) {
    this->UtilityDecorator::Rotate(angle);
}

void DurabilityDecorator::Jump(double height) {
    this->UtilityDecorator::Jump(height);
}
