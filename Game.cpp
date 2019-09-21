#include "Game.h"
#include "Constants.h"

using namespace Settings;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(WINDOW_X, WINDOW_Y), "Particle Simulator", sf::Style::Close)
	, mTextureHolder{}
{
	mWindow.setKeyRepeatEnabled(false);
	loadTextures();
	setupScene();
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
	SingleParticleFactory factory(&mTextureHolder);


	mParticles = factory.createParticles(20);

	/*
		for (int i = 0; i < 20; i++)
{
	Particle* test = new CircleParticle(20, sf::Vector2f(20, 20), 15, mTextureHolder.get(0));
	mParticles.push_back(test);
}
	*/


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
		std::string name = p.path().filename().string();		//	E.g. "Player.txt", "Player.dat"
		std::string path = p.path().string();		//	E.g. "Player.txt"
		/*
		auto checkIfFType = name.find_first_of('.');
		name.erase(checkIfFType);							//	now = "Player"
		name.erase(std::remove(name.begin(), name.end(), '"'), name.end());		//	now = Player																										//	Get the path
		*/


		files.insert(std::make_pair(name, path));
	}

	int counter = 0;
	for (const auto& file : files)
	{
		std::cout << "Loaded file '" << file.second << "' with ID " << counter << '\n';
		mTextureHolder.load(counter, file.second);
		counter++;
	}
}
