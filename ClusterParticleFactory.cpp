#include "ClusterParticleFactory.h"

using namespace Settings;

ClusterParticleFactory::ClusterParticleFactory(TextureHolder<int>* mTextureHolder)
	: ParticleFactory{ mTextureHolder }
{
}

std::vector<Particle*> ClusterParticleFactory::createParticles(int amount)
{
	std::vector<Particle*> mParticles;
	Particle* particleRoot;
	Particle* particleChild;
	int clusterSize;
	sf::Vector2f rootCenter, randOffsetDirection, newPoint;

	for (int i = 0; i < amount; i++)
	{
		clusterSize = getRand(2, MAX_CLUSTER_SIZE);
		particleRoot = createRandomParticle();		// parent
		rootCenter = sf::Vector2f(particleRoot->getWidth() / 2, particleRoot->getWidth() / 2);

		for (int i = 0; i < clusterSize; i++)
		{
			particleChild = createRandomParticle();

			randOffsetDirection = sf::Vector2f(getRand(0, 359), getRand(0, 359));
			newPoint = sf::Vector2f(rootCenter.x + cos(randOffsetDirection.x)*(rootCenter.x + particleChild->getWidth() / 2),
				rootCenter.y + sin(randOffsetDirection.y)*(rootCenter.y + particleChild->getWidth() / 2));

			particleRoot->attachChild(particleChild, newPoint);
		}
		mParticles.push_back(particleRoot);
	}

	return mParticles;
}