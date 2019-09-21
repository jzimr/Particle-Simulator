#include "CircleParticle.h"

CircleParticle::CircleParticle(int speed, sf::Vector2f direction, int size, sf::Texture& texture)
	: Particle(speed, direction, new sf::CircleShape( size ))
{
	setTexture(texture);
}