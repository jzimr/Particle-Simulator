#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <filesystem>
#include <iostream>
#include "SquareParticle.h"
#include "TextureHolder.h"

class Game
{
public:
					Game();
	void			run();


private:
	void			processInput();
	void			update(sf::Time elapsedTime);
	void			render();
	void			setupScene();
	void			loadTextures();

private:
	static const sf::Time		TimePerFrame;		// How many FPS?
	sf::RenderWindow			mWindow;
	std::vector<Particle*>		particles;			// Holds all particles
	TextureHolder<std::string> textureHolder;		// Holds all textures
};