#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

MathLibrary::Vector2 SeekComponent::calculateForce()
{
	if (!getTarget())
		return { 0, 0 };

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();

	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity 

	return MathLibrary::Vector2();
}

void SeekComponent::update(float deltaTime)
{

	/*MathLibrary::Vector2 moveDirection = (m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition());
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);*/

	
	
}

void SeekComponent::getDesiredVelocity()
{

	MathLibrary::Vector2 V1 = (getAgent()->getTransform()->getLocalPosition(), getTarget()->getTransform()->getLocalPosition());
	m_desiredVelocity = V1.getNormalized() * 200;
}

void SeekComponent::getSteeringForce()
{
	m_steeringForce = getDesiredVelocity() - getCurrentVelocity();
}

Actor* SeekComponent::getAgent()
{
	return m_agent;
}

Actor* SeekComponent::getTarget()
{
	return m_target;
}




