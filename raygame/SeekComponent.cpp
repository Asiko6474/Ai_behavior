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

	m_desiredVelocity = (getAgent()->getTransform()->getLocalPosition(), getTarget()->getTransform()->getLocalPosition());
}

Actor* SeekComponent::getAgent()
{
	return m_agent;
}

Actor* SeekComponent::getTarget()
{
	return m_target;
}




