#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Transform2D.h"

class SeekComponent 
	: public Component
{
public:
	SeekComponent(const char* name = "SeekComponent") : Component::Component(name) {}

	//Inherited from component class
	void update(float deltaTime) override;

private:
	MathLibrary::Vector2 m_velocity;
	float m_maxSpeed;



};

