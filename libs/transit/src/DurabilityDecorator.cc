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
    else { // locate neared repair station and set its destination to that and go to it 
        this->UtilityDecorator::SetDestination(); // set to repair station
        Vector3 newDest = this->UtilityDecorator::GetDestination();
        float newDist = pos.Distance(dest);
        float newDmgTaken = dist * .7;
        this->UtilityDecorator::SetDurability(this->UtilityDecorator::GetDurability() - newDmgTaken);
        this->UtilityDecorator::Update(dt, scheduler);
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
