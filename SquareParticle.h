#pragma once
#include "Particle.h"

class SquareParticle : public Particle
{
public:
	SquareParticle(ParticleType* type, int speed, sf::Vector2f direction);
};