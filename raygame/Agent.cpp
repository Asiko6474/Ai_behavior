#include "Agent.h"
#include "MoveComponent.h"
#include "SteeringComponent.h"

Agent::Agent(float x, float y, const char* name, float maxForce, float maxSpeed)
{
	setMaxForce(maxForce);
	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(maxSpeed);
}

void Agent::Start()
{
	Actor::start();

	m_moveComponent->setUpdateFacing(true);
}

void Agent::Update(float deltaTime)
{
	Actor::update(deltaTime);
	//Get all force being applied from steering behaviours
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
	{
		m_force = m_force + m_steeringComponents[i]->calculateForce();
	}

	//Clamp force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* component)
{
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(component);
	if (steeringComponent)
		m_steeringComponents.add(steeringComponent);
}

float Agent::getMaxForce()
{
	return m_maxForce;
}

void Agent::setMaxForce(float maxForce)
{
	m_maxForce = maxForce;
}
