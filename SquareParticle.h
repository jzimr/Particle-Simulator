#pragma once
#include "Particle.h"

class SquareParticle : public Particle
{
public:
	SquareParticle(float speed, sf::Vector2f direction, sf::Vector2f size, sf::Texture& texture);
};