#pragma once
#include "Particle.h"

class CircleParticle : public Particle
{
public:
	CircleParticle(ParticleType* type, int speed, sf::Vector2f direction);
};