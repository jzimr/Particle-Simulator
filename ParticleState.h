#pragma once
#include <SFML/Graphics.hpp>

/*
We only need to store the direction, as this is the only value prone to change
after an object has been created
*/
struct ParticleState
{
	sf::Vector2f position;
	sf::Vector2f direction;
};
