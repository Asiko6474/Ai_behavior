#include "InputComponent.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	//Get the direction for the individual axis
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	float bulletDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_LEFT) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_RIGHT);
	float bulletDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_UP) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_DOWN);
	
	//Return a new vector represenitng the move direction
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
	return MathLibrary::Vector2(bulletDirectionX, bulletDirectionY);

	
}

float InputComponent::removeHealth()
{
	float subtractHealth = RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_Q);

	return subtractHealth + 4;
}

void InputComponent::showCollider()
{
	if (m_collisionKey)
	{
		
	}
}
