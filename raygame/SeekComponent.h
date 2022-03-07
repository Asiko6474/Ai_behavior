#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "MoveComponent.h"

class Actor;
class MoveComponent;

class SeekComponent 
	: public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;

	//Inherited from component class
	void update(float deltaTime) override;
	void getDesiredVelocity();
	void getSteeringForce();
	MathLibrary::Vector2 getCurrentVelocity() { return m_currentVelocity; }
	Actor* getAgent();
	Actor* getTarget();
	

private:
	
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2* m_steeringForce;
	Actor* m_agent;
	Actor* m_target;
};

