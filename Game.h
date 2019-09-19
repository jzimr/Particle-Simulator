#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Particle.h"

class Game
{
public:
					Game();
	void			run();


private:
	void			processInput();
	void			update(sf::Time elapsedTime);
	void			render();

private:
	static const sf::Time		TimePerFrame;		// How many FPS?
	sf::RenderWindow			mWindow;
	std::vector<Particle*>		particles;			// Holds all particles
};