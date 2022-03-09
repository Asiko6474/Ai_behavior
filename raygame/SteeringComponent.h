#pragma once
#include "Component.h"
#include <Vector2.h>

class Agent;
class MoveComponent;

class SteeringComponent :
	public Component
{
public:

	SteeringComponent() { m_target = nullptr; m_steeringForce = 0; }
	
	SteeringComponent(Actor* actor, float steeringForce) { m_target = actor; m_steeringForce = steeringForce; }//Initializes target
	
	virtual MathLibrary::Vector2 calculateForce() = 0;//Override this in inherited classe and place the logic for the inherited steering behavior here
	
	Actor* getTarget() {return m_target; }//gets the target actor this steering behavior is using to calculate force
	
	void setTarget(Actor* target) {m_target = target;}//sets the target actor this steering behavior will be using to calculate force

	void setSteeringForce(float steeringForce){ m_steeringForce = steeringForce; }
	float getSteeringForce() { return m_steeringForce; }

	Agent* getAgent() { return (Agent*)getOwner(); }

private:
	float m_steeringForce = 0;
	Actor* m_target = nullptr;
};

