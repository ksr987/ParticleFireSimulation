#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;

int main(int argc, char* args[]) {

	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		cout << "Error initializing SDL" << endl;
	}

	Swarm swarm;
	
	while (true) {

		//time elapsed after the program ran
		int elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update();

		//multiplied by 0.001 to avoid rapid changes in sin values
		//ensures the value is between 0 and 255.
		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			//map particle space (from -1 to +1) to screen space (width by height)
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		/*update particles*/

		
		/*draw particles*/
		
		/*draw the screen*/
		screen.update();

		/*check for events/messages*/
		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();	
	return 0;
}
