#pragma once
#include "Particle.h"

class CircleParticle : public Particle
{
	CircleParticle(float speed, sf::Vector2f direction, sf::Vector2f size, sf::Texture texture);
};