#pragma once
#include "Particle.h"

class CircleParticle : public Particle
{
public:
	CircleParticle(int speed, sf::Vector2f direction, int size, sf::Texture& texture);
};