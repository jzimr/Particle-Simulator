#include "ParticleFactory.h"

ParticleFactory::ParticleFactory()
{
	throw "Direct instantiation of 'Particle' class not allowed";
}

ParticleFactory::ParticleFactory(TextureHolder<int>* mTextureHolder)
	: mTextureHolder{ mTextureHolder }
{
	/* initialize random seed: */
	srand(time(NULL));
}

Particle* ParticleFactory::createRandomParticle(sf::Vector2f pos)
{
	Particle* particle;

	int randSpeed, randDirectionX, randDirectionY, randSize, randTexture, randShape;

	randSpeed = getRand(1, Settings::MAX_SPEED);
	randDirectionX = getRand(0, 1000); randDirectionX *= randDirectionX < 500 ? -1 : 1;
	randDirectionY = getRand(0, 1000); randDirectionY *= randDirectionY < 500 ? -1 : 1;
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
	particle->setPosition(pos);		// Spawn is center of screen
	return particle;
}

	int ParticleFactory::getRand(int start, int end)
	{
		if (start > end)
			throw "Start number cannot be lower than end number";

		return rand() % ((end - start) + 1) + start;
	}