#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <filesystem>
#include <iostream>
#include "SquareParticle.h"
#include "CircleParticle.h"
#include "TextureHolder.h"
#include "SingleParticleFactory.h"
#include "ClusterParticleFactory.h"

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
	std::vector<Particle*>		mParticles;			// Holds all mParticles
	TextureHolder<int>			mTextureHolder;		// Holds all textures
};