#include "CircleParticle.h"

CircleParticle::CircleParticle(float speed, sf::Vector2f direction, sf::Vector2f size, sf::Texture texture)
	: Particle(speed, direction, new sf::RectangleShape{ size })
{
	setTexture(texture);
}