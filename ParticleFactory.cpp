#include "ParticleFactory.h"
typedef ParticleType::ShapeType ShapeType;

ParticleFactory::ParticleFactory()
{
	throw "Direct instantiation of 'Particle' class not allowed";
}

ParticleType* ParticleFactory::getParticleInCache(ParticleType::ShapeType ShapeType, int size, sf::Texture & texture)
{
	for (ParticleType* pType : mParticleTypes)
	{
		if (pType->isEqualTo(ShapeType, size, texture))
			return pType;
	}
	return nullptr;
}

Particle* ParticleFactory::createNewParticle(ShapeType shape, ParticleType* type, int speed, sf::Vector2f direction)
{
	switch (shape)
	{
	case ShapeType::Square:
		return new SquareParticle(type, speed, direction);
	case ShapeType::Circle:
		return new CircleParticle(type, speed, direction);
	default:
		return nullptr;
	}
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
	ParticleType* particleType;

	int randSpeed, randDirectionX, randDirectionY, randSize, randTexture, randShape;

	randSpeed = getRand(1, Settings::MAX_SPEED);
	randDirectionX = getRand(0, 1000); randDirectionX *= randDirectionX < 500 ? -1 : 1;
	randDirectionY = getRand(0, 1000); randDirectionY *= randDirectionY < 500 ? -1 : 1;
	randSize = getRand(1, Settings::MAX_SIZE);
	randTexture = getRand(0, mTextureHolder->size() - 1);
	randShape = getRand(0, ParticleType::SHAPE_COUNT-1);

	// flyweight: check if particle in cache
	particleType = getParticleInCache((ShapeType)randShape, randSize, mTextureHolder->get(randTexture));
	// particle is not in cache, create new one
	if (particleType == nullptr)
	{
		particleType = new ParticleType((ShapeType)randShape, randSize, mTextureHolder->get(randTexture));
		mParticleTypes.push_back(particleType);
	}
	particle = createNewParticle((ShapeType)randShape, particleType, randSpeed, sf::Vector2f(randDirectionX, randDirectionY));

	particle->setPosition(pos);		// Spawn is center of screen
	return particle;
}

int ParticleFactory::getRand(int start, int end)
{
	if (start > end)
		throw "Start number cannot be lower than end number";

	return rand() % ((end - start) + 1) + start;
}

std::vector<ParticleType*> ParticleFactory::mParticleTypes;