#pragma once
#include "ParticleFactory.h"
#include "TextureHolder.h"

class ClusterParticleFactory : public ParticleFactory
{
public:
	ClusterParticleFactory(TextureHolder<int>* mTextureHolder);

	std::vector<Particle*>	createParticles(int amount, sf::Vector2f where);
};