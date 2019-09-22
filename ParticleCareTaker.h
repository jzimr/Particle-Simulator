#pragma once
#include <iostream>
#include <stack>
#include "Particle.h"

/*
Created own class for caretaker to prevent bloating in "Game" class and
to increase decoupling
*/
class ParticleCareTaker
{
public:
	ParticleCareTaker();
	ParticleCareTaker(Particle* particle);

	void createSnapshot();		// saves a new state of the particle
	void undo();				// returns to previous state of particle
	bool hasHistory();			// check if particle has snapshots

private:

	std::stack<Particle::Memento> mHistory;
	Particle* mParticle;
};