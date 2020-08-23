#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

class Window {
	public:
		void CreateWindow(const char *name, const float posx, const float posy);

	private:
		SDL_Window *nwindow;
};

void init();
#endif
