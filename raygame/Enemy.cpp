#include "Enemy.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "Transform2D.h"
#include "Sprite.h"
#include "InRangeDecision.h"
#include "WanderDecision.h"
#include "SeekDecision.h"
#include "IdleDecision.h"
#include "AggressiveDecision.h"
#include "DecisionComponent.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	AggressiveDecision* aggresive = new AggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggresive, seek);

	addComponent(new DecisionComponent(inRange));


	getTransform()->setScale({ 50,50 });
	addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* comp = new WanderComponent(1000, 100, 100);
	addComponent(comp);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(50);
	seekComponent->setTarget(m_target);
	addComponent(seekComponent);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	return distance <= 74;
}
