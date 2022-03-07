#include "Agent.h"

void Agent::Start()
{
	m_moveComponent = addComponent<MoveComponent>();
}

void Agent::Update(float deltaTime)
{
	//Get all force being applied from steering behaviors
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}
	//clamp force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}
	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component)
		if (steeringComponent != nullptr)
			m_steeringComponents.addItem(steeringComponent);
}

float Agent::getMaxForce()
{
	return m_maxForce;
}

void Agent::setMaxForce(float maxForce)
{
	m_maxForce = maxForce;
}
