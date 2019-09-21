#include "SquareParticle.h"

SquareParticle::SquareParticle(float speed, sf::Vector2f direction, float size, sf::Texture& texture)
	: Particle(speed, direction, new sf::RectangleShape{ sf::Vector2f(size, size) })
{
	setTexture(texture);
}