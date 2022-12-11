#include "UtilityDecorator.h"

Vector3 UtilityDecorator::GetPosition() const {
    return this->myDrone->GetPosition();
}

Vector3 UtilityDecorator::GetDirection() const {
    return this->myDrone->GetDirection();
}

Vector3 UtilityDecorator::GetDestination() const {
    return this->myDrone->GetDestination();
}

JsonObject UtilityDecorator::GetDetails() const {
    return this->myDrone->GetDetails();
}

std::string UtilityDecorator::GetColor() const {
    return this->myDrone->GetColor();
}

float UtilityDecorator::GetSpeed() const {
    return this->myDrone->GetSpeed();
}

bool UtilityDecorator::GetAvailability() const {
    return this->myDrone->GetAvailability();
}

std::string UtilityDecorator::GetStrategyName() {
    return this->myDrone->GetStrategyName();
}

void UtilityDecorator::SetAvailability(bool choice) {
    this->myDrone->SetAvailability(choice);
}

void UtilityDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    this->myDrone->Update(dt, scheduler);
}

void UtilityDecorator::SetGraph(const IGraph* graph) {
    this->myDrone->SetGraph(graph);
}

void UtilityDecorator::SetPosition(Vector3 pos_) {
    this->myDrone->SetPosition(pos_);
}

void UtilityDecorator::SetDirection(Vector3 dir_) {
    this->myDrone->SetDirection(dir_);
}

void UtilityDecorator::SetDestination(Vector3 des_) {
    this->myDrone->SetDestination(des_);
}

void UtilityDecorator::SetStrategyName(std::string strategyName_) {
    this->myDrone->SetStrategyName(strategyName_);
}

void UtilityDecorator::Rotate(double angle) {
    this->myDrone->Rotate(angle);
}

void UtilityDecorator::Jump(double height) {
    this->myDrone->Jump(height);
}
