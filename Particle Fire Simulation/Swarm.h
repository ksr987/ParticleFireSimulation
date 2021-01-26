#pragma once
#include "Particle.h"
class Swarm
{
private:
	Particle* m_pParticles;

public:
	const static int NPARTICLES = 1000;
	Swarm();
	const Particle* const getParticles();
	void update();
	~Swarm();

};

