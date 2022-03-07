#include "SteeringComponent.h"

SteeringComponent::SteeringComponent()
{
	m_target = nullptr;
}

SteeringComponent::SteeringComponent(Actor* actor)
{
	m_target = actor;
}

virtual MathLibrary::Vector2 SteeringComponent::calculateForce()
{
	return Vector2();
}

Actor* SteeringComponent::getTarget()
{
	return m_target;
}

void SteeringComponent::setTarget(Actor* actor)
{

}
