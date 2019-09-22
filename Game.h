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
#include "Particle.h"
class ParticleCareTaker;

class Game
{
public:
					Game();
	void			run();


private:
	void			createSnapshots();
	void			loadLastSnapshots();
	void			processInput();
	void			update(sf::Time elapsedTime);
	void			render();
	void			setupScene();
	void			loadTextures();

private:
	static const sf::Time		TimePerFrame;		// How many FPS?
	sf::Clock					clockMemento;		// counts time for memento snapshots
	sf::RenderWindow			mWindow;
	ParticleFactory*			mFactory;
	std::vector<Particle*>		mParticles;			// Holds all mParticles
	std::map<int, ParticleCareTaker> mHistory; // k: Particle ID, v: caretaker objects
	TextureHolder<int>			mTextureHolder;		// Holds all textures
	bool						gamePaused;
	float 						savedClockTime;
};