#pragma once
#include "BooleanDecision.h"
class AggressiveDecision :
	public BooleanDecision
{
public:
	AggressiveDecision(Decision* left = nullptr, Decision* right = nullptr) : AggressiveDecision(left, right) {};
	bool checkCondition(Agent* agent, float deltaTime) override;
};
