#pragma once
#include "Agent.h"

class Enemy :
	public Agent
{
public:
	Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target);
	void start() override;

	bool getTargetInRange();

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	bool getIsAgressive() { return m_isAggressive; }
	bool setIsAggressive(bool value) { m_isAggressive = value; }
private:
	Actor* m_target;
	bool m_isAggressive;
};

