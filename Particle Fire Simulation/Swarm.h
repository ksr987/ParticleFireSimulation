#pragma once
#include "Particle.h"
class Swarm
{
private:
	Particle* m_pParticles;
	int lastTime;

public:
	const static int NPARTICLES = 5000;
	Swarm();
	const Particle* const getParticles();
	void update(int elapsed);
	~Swarm();

};

