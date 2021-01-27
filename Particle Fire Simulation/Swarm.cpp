#include "Swarm.h"
#include <iostream>

Swarm::Swarm():lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];
}

//cannot change the pointer or the particles it is pointing to after getting the particles from this method
const Particle* const Swarm::getParticles() {
	return m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
	lastTime = elapsed;
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}