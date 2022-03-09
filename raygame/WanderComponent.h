#pragma once
#include "SteeringComponent.h"

class WanderComponent :
	public SteeringComponent
{
public:
	WanderComponent(float circleDistance, float circleRadius, float wanderForce);
	MathLibrary::Vector2 calculateForce() override;

private: 
	float m_circleDistance = 0;
	float m_circleRadius = 0;
	float m_wanderAngle = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePos;
	/*So this is just some notes on how to get a wonder code working.*/

	//Vector2 randPos = (cos(randNum), sin(randNum));
	//Vector2 circlepos = position + circleoffset;
	//Vector2 randPos = (randNum1, randNum2).normalize() * CircleRadious;


	
};

