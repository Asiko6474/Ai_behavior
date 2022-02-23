#include "Component.h"

Component::Component()
{
	m_owner = nullptr;
	m_started = false;
}



Component::Component(const char* name)
{
	m_started = false;
}

Component::~Component()
{
}

void Component::assignOwner(Actor* owner)
{
	if (!getOwner())
		return;

	m_owner = owner;
}

void Component::update(float deltaTime)
{
}

void Component::end()
{
}

void Component::draw()
{
}

void Component::onCollision(Actor* other)
{
}
