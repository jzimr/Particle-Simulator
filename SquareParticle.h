#pragma once
#include "Particle.h"

class SquareParticle : public Particle
{
public:
	SquareParticle(float speed, sf::Vector2f direction, float size, sf::Texture& texture);
};