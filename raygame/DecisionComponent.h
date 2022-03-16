#pragma once
#include "Component.h"

class Decision;

class DecisionComponent :
	public Component
{
public:
	DecisionComponent(Decision* root) { m_root = root; }
	virtual void start() override;
	void update(float deltaTime) override;

private:
	Decision* m_root;
	Agent* m_owner;
};

