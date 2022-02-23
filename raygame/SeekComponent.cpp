#include "SeekComponent.h"
#include "Actor.h"
#include "Transform2D.h"

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




