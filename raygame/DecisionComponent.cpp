#include "DecisionComponent.h"
#include "Decision.h"
#include "Agent.h"

void DecisionComponent::start()
{
	m_Owner = dynamic_cast<Agent*>(getOwner());
}

void DecisionComponent::update(float deltaTime)
{
	if (m_Owner)
		m_root->makeDecision(m_Owner, deltaTime);
	else
		throw std::exception("Decision component can only be attached to agents.");
}
