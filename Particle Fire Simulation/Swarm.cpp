#include "Swarm.h"
#include <iostream>

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
}

//cannot change the pointer or the particles it is pointing to after getting the particles from this method
const Particle* const Swarm::getParticles() {
	return m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}