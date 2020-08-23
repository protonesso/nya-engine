#include "init.h"

void Window::CreateWindow(const char *name, const float posx, const float posy) {
	nwindow = SDL_CreateWindow(name,
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				posx,
				posy,
				SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(nwindow); // set GL context

	if (!nwindow) {
		fprintf(stderr, "Failed to load SDL: %s", SDL_GetError());
		exit(1);
	}

	/* Setup OpenGL */
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // background color
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST); // Enable depth test
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float) posx / (float) posy, 0.1f, 100.0f); // Setup perspective
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	Window win;

	/* SDL2 initialization code */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Failed to load SDL: %s", SDL_GetError());
		exit(1);
	}

	/* Initialize double buffer */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	/* Create window */
	win.CreateWindow("tfw engine", 1024, 768);
}
