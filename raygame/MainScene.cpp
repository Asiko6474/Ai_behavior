#include "MainScene.h"
#include "Sprite.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(200, 50, "Player");
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));
	MoveComponent* playerMove = player->addComponent<MoveComponent>();
	playerMove->setUpdateFacing(true);

	Enemy* enemy = new Enemy(100, 100, "Enemy", 100, 50, player);

	addActor(player);
	addActor(enemy);
};
