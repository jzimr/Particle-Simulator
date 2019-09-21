#include "SingleParticleFactory.h"

using namespace Settings;

SingleParticleFactory::SingleParticleFactory(TextureHolder<int>* mTextureHolder)
	: ParticleFactory{ mTextureHolder }
{
}

std::vector<Particle*> SingleParticleFactory::createParticles(int amount)
{
	std::vector<Particle*> mParticles;
	Particle* particle;
	int randSpeed, randDirectionX, randDirectionY, randSize, randTexture, randShape;

	for (int i = 0; i < amount; i++)
	{
		randSpeed = getRand(1, Settings::MAX_SPEED);
		randDirectionX = getRand(0, 1000);
		randDirectionY = getRand(0, 1000);
		randSize = getRand(1, Settings::MAX_SIZE);
		randTexture = getRand(0, mTextureHolder->size() - 1);
		randShape = getRand(0, 1);

		if (randShape)
		{
			particle = new SquareParticle{
				randSpeed,
				sf::Vector2f(randDirectionX, randDirectionY),
				randSize,
				mTextureHolder->get(randTexture)
			};
		}
		else
		{
			particle = new CircleParticle{
				randSpeed,
				sf::Vector2f(randDirectionX, randDirectionY),
				randSize,
				mTextureHolder->get(randTexture)
			};
		}
		
		mParticles.push_back(particle);
	}


	return mParticles;
}