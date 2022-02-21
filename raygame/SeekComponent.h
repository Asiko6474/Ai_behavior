#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "MoveComponent.h"

class Actor;
class SeekComponent 
	: public Component
{
public:
	SeekComponent(const char* name = "SeekComponent") : Component::Component(name) {}

	//Inherited from component class
	void update(float deltaTime) override;
	void getDesiredVelocity();
	Actor* getAgent();
	Actor* getTarget();
	

private:
	
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2* m_steeringForce;
	Actor* m_agent;
	Actor* m_target;
};

