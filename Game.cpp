#include "Game.h"
#include "Constants.h"

using namespace Settings;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(WINDOW_X, WINDOW_Y), "Particle Simulator", sf::Style::Close)
{
	mWindow.setKeyRepeatEnabled(false);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);
		}

		render();
	}
}

void Game::processInput()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();


	}
}

void Game::update(sf::Time elapsedTime)
{
	for(Particle* particle : particles)
		particle->update(elapsedTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();

	for (Particle* particle : particles)
		mWindow.draw(*particle);
	
	mWindow.display();
}
