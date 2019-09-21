#include "ParticleFactory.h"

ParticleFactory::ParticleFactory()
{
	throw "Direct instantiation of 'Particle' class not allowed";
}

ParticleFactory::ParticleFactory(TextureHolder<int>* mTextureHolder)
	: mTextureHolder{mTextureHolder}
{
	/* initialize random seed: */
	srand(time(NULL));
}

int ParticleFactory::getRand(int start, int end)
{
	if (start > end)
		throw "Start number cannot be lower than end number";

	return rand() % ((end - start)+1) + start;
}