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
    this->UtilityDecorator::Update(dt, scheduler);
}

void DurabilityDecorator::SetGraph(const IGraph* graph) {
    this->UtilityDecorator::SetGraph(graph);
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
