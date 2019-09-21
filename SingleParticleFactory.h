#pragma once
#include "ParticleFactory.h"
#include "TextureHolder.h"

class SingleParticleFactory : public ParticleFactory
{
public:
	SingleParticleFactory(TextureHolder<int>* mTextureHolder);

	std::vector<Particle*>	createParticles(int amount, sf::Vector2f where);
};