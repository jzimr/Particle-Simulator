#include "SquareParticle.h"

SquareParticle::SquareParticle(int speed, sf::Vector2f direction, int size, sf::Texture& texture)
	: Particle(speed, direction, new sf::RectangleShape{ sf::Vector2f(size, size) })
{
	setTexture(texture);
}