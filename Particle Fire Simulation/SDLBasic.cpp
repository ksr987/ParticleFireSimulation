#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* args[]) {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed!" << endl;
		return 1;
	}

	cout << "SDL Init succedded!" << endl;
	SDL_Quit();
	return 0;
}
