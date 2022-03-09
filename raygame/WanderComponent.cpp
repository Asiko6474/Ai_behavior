#include "WanderComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Agent.h"
#include "MoveComponent.h"
#include <time.h>
#include <cmath>

WanderComponent::WanderComponent(float circleDistance, float circleRadius, float wanderForce) : SteeringComponent(nullptr, wanderForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	srand(time(NULL));
}

MathLibrary::Vector2 WanderComponent::calculateForce()
{
	//find the agent's position and heading
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	//Find the circle's position in front of the agent
	m_circlePos = ownerPosition + (heading * m_circleDistance);

	//Find a randum vector on the circle position to get a new random point on the circle
	float randNum = (rand() % 201);
	
	//Add the random vector to the circle position to get a raw random point on the circle
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2{ std::cos(randNum), std::sin(randNum) } * m_circleRadius;

	//seek to the random point
	m_target = randDirection + m_circlePos;

	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return force;
}
