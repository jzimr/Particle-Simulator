#pragma once
#include <iostream>
#include <vector>
#include "Particle.h"

class Factory
{
public:
	Factory();

	std::vector<Particle*>			operation();
	
private:
	virtual std::vector<Particle*>	createParticles(int amount) = 0;
};
