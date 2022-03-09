#pragma once
#include "Component.h"
#include <raylib.h>
class Texture2D;

class SpriteComponent :
	public Component
{
public:
	/// <param name="texture">Sets the sprites image to be this texture</param>
	/// <param name="name">The name of the component instance</param>
	SpriteComponent(Texture2D* texture) { m_texture = texture; }

	/// <param name="path">The path of the texture to load</param>
	/// <param name="name"></param>
	SpriteComponent(const char* path) { m_texture = new Texture2D(RAYLIB_H::LoadTexture(path)); }

	~SpriteComponent() override;

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};

