#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Particle.h"
#include "SquareParticle.h"
#include "CircleParticle.h"	
#include "TextureHolder.h"
#include "Constants.h"

class ParticleFactory
{
public:
	// Factory method that will be overriden in subclasses, creating unique products (mParticles)
	virtual std::vector<Particle*>	createParticles(int amount) = 0;

protected:
	ParticleFactory(TextureHolder<int>* mTextureHolder);

	Particle* createRandomParticle();
	int getRand(int lowest, int highest);

protected:
	TextureHolder<int>* mTextureHolder;

private:
	ParticleFactory();
};
