#include "ParticleCareTaker.h"
//typedef Particle::Memento Memento;

ParticleCareTaker::ParticleCareTaker()
{
	//throw "Cannot directly initialize ParticleCareTaker";
}

ParticleCareTaker::ParticleCareTaker(Particle * particle)
	: mParticle{particle}
	, mHistory{}
{
}

void ParticleCareTaker::createSnapshot()
{
	Particle::Memento snapshot = mParticle->saveToMemento();
	mHistory.push(snapshot);
}

void ParticleCareTaker::undo()
{
	if (!hasHistory())
		return;

	mParticle->restoreFromMemento(mHistory.top());
	mHistory.pop();		// remove snapshot from stack
}

bool ParticleCareTaker::hasHistory()
{
	return !mHistory.empty();
}


