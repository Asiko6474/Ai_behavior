#include "MainScene.h"
#include "Sprite.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SeekComponent.h"
#include "WanderComponent.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
	Player* player = new Player(200, 50, "Player");
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));
	MoveComponent* playerMove = player->addComponent<MoveComponent>();

	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50,50 });
	agent->setMaxForce(200);
	agent->addComponent(new SpriteComponent("Images/enemy.png"));

	WanderComponent* comp = new WanderComponent(1000, 100, 100);
	agent->addComponent(comp);

	SeekComponent* seekComponent = new SeekComponent();
	seekComponent->setSteeringForce(500);
	seekComponent->setTarget(player);
	agent->addComponent(seekComponent);
	agent->addComponent<StateMachineComponent>();
	addActor(player);
	addActor(agent);
};
