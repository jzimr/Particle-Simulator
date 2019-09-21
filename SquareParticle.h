#pragma once
#include "Particle.h"

class SquareParticle : public Particle
{
public:
	SquareParticle(int speed, sf::Vector2f direction, int size, sf::Texture& texture);
};