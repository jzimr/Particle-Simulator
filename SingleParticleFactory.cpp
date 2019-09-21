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

	for (int i = 0; i < amount; i++)
	{
		particle = createRandomParticle();
		mParticles.push_back(particle);
	}


	return mParticles;
}