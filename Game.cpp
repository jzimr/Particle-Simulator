#include "Game.h"
#include "Constants.h"

using namespace Settings;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(WINDOW_X, WINDOW_Y), "Particle Simulator", sf::Style::Close)
	, mTextureHolder{}
	, gamePaused{ false }
	, mHistory{}
{
	mWindow.setKeyRepeatEnabled(false);
	loadTextures();
	setupScene();
}

void Game::run()
{
	sf::Clock clockGameLoop;
	clockMemento.restart();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		// for Memento pattern
		if (clockMemento.getElapsedTime().asSeconds() + savedClockTime >= 1.0f && !gamePaused)
		{
			if (savedClockTime > 0.00001f)
				savedClockTime = 0.0f;

			createSnapshots();
			clockMemento.restart();
		}

		// for Game loop
		sf::Time elapsedTime = clockGameLoop.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			if (!gamePaused)
				update(TimePerFrame);
		}

		render();
	}
}

void Game::createSnapshots()
{
	int particleId;

	for (auto& particle : mParticles)
	{
		particleId = particle->getId();
		// create new history if particle has none yet
		if (mHistory.find(particleId) == mHistory.end())
			mHistory[particleId] = ParticleCareTaker(particle);

		mHistory[particleId].createSnapshot();
	}
}

void Game::loadLastSnapshots()
{
	int particleId;
	std::map<int, ParticleCareTaker>::iterator it;
	std::vector<Particle*> toDelete; // k: particle, v: delete history too?

	for (auto& particle : mParticles)
	{
		particleId = particle->getId();
		it = mHistory.find(particleId);
		// if does not have Caretaker, delete particle
		if (it == mHistory.end())
			toDelete.push_back(particle);
		// if does not have any more history in Caretaker, delete caretaker & particle
		else if (!it->second.hasHistory())
		{
			toDelete.push_back(particle);
			mHistory.erase(it);
		}
		// if has caretaker & history
		else if (it->second.hasHistory())
			it->second.undo();
	}

	// delete all particles that do not have any history
	for (auto& particle : toDelete)
	{
		std::vector<Particle*>::iterator it2 = std::find(mParticles.begin(), mParticles.end(), particle);
		if (it2 != mParticles.end())
		{
			delete particle;
			particle = nullptr;
			mParticles.erase(it2);
		}
	}

}

void Game::processInput()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			// get mouse position to world coordinates
			sf::Vector2i mousepos = sf::Mouse::getPosition(mWindow);
			sf::Vector2f converted = mWindow.mapPixelToCoords(mousepos);

			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mFactory = new SingleParticleFactory(&mTextureHolder);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
				mFactory = new ClusterParticleFactory(&mTextureHolder);

			// create new particles based on which mouse button was clicked
			std::vector<Particle*> newParticles = mFactory->createParticles(10, converted);
			mParticles.insert(mParticles.end(), newParticles.begin(), newParticles.end());
		}
		if (event.type == sf::Event::KeyPressed)
		{
			// "undo" command that goes back to the particles' last state
			if (event.key.code == sf::Keyboard::Z)
			{
				std::cout << "Reverting to last saved state\n";
				loadLastSnapshots();
				clockMemento.restart();
			}
			// "pause" command to pause all movement
			if (event.key.code == sf::Keyboard::Space)
			{

				if (gamePaused)
				{
					clockMemento.restart();
					gamePaused = false;
				}
				else
				{
					savedClockTime = clockMemento.getElapsedTime().asSeconds();
					gamePaused = true;
				}
			}
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	for (Particle* particle : mParticles)
		particle->update(elapsedTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();

	for (Particle* particle : mParticles)
		mWindow.draw(*particle);

	mWindow.display();
}

void Game::setupScene()
{
}

void Game::loadTextures()
{
	// get files from folder first 
	std::map<std::string, std::string> files;
	std::string folderPath = "Media";

	//	For each file in folder
	for (auto & p : std::experimental::filesystem::directory_iterator(folderPath))
	{
		if (!std::experimental::filesystem::is_regular_file(p))		//	Check if not directory, stream, etc.
			continue;

		///	Get the m_entity name
		std::string name = p.path().filename().string();
		std::string path = p.path().string();


		files.insert(std::make_pair(name, path));
	}

	if (files.size() == 0)
	{
		throw "Did not find any textures.\n Please put at least 1 texture into 'media' folder";
	}

	int counter = 0;
	for (const auto& file : files)
	{
		std::cout << "Loaded file '" << file.second << "' with ID " << counter << '\n';
		mTextureHolder.load(counter, file.second);
		counter++;
	}
}
