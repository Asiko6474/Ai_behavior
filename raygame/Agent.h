#pragma once
#include "Actor.h"
#include <Vector2.h>
#include "ActorArray.h"

class SteeringComponent;
class MoveComponent;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed);
	void Start();//initializes move component

	void Update(float deltaTime);//gets the sum of all forces being acted on the agent and applies it to its velocity.

	virtual void onAddComponent(Component* component);//used to add new steering component to the steering components array

	float getMaxForce();

	void setMaxForce(float maxForce);

	MoveComponent* getMoveComponent() { return m_moveComponent; }

private:
	
	DynamicArray<SteeringComponent*> m_steeringComponents;//an array containing all steering compnents attached to the agent
	
	float m_maxForce;//the force vector should not be allowed to have a magnitude greater than this value.
	
	float m_maxspeed;//the velocity vector should not be allowed to have a magnitude greater than this value.
	
	MoveComponent* m_moveComponent;//stores the move component attached to the agent in order to get access to its velocity
	
	MathLibrary::Vector2 m_force;//the force current being applied to this agent
};

