#pragma once
#include "Component.h"
#include <Vector2.h>

class MoveComponent;

class SteeringComponent :
	public Component
{
public:

	SteeringComponent();
	//Initializes target
	SteeringComponent(Actor* actor, float steeringForce) { m_target = actor; m_steeringForce = steeringForce; }
	//Override this in inherited classe and place the logic for the inherited steering behavior here
	virtual MathLibrary::Vector2 calculateForce() abstract;
	//gets the target actor this steering behavior is using to calculate force
	Actor* getTarget();
	//sets the target actor this steering behavior will be using to calculate force
	void setTarget(Actor* actor);
	void setSteeringFroce(float steeringForce){ m_steeringForce = steeringForce; }
private:
	float m_steeringForce = 0;
	Actor* m_target;
};

