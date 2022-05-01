#ifndef GLINIT_H
#define GLINIT_H

#include <iostream>
#include "SDL.h"
#define GLEW_STATIC
#include "glew.h"

/*
Call to create a window, initialize a GL context and initialize the GLEW library
Necessary to start drawing to a wind
*/
void init(SDL_Window*& window);

/*
Call before creating a GL context to set attributes
*/
void initGLAttributes(int glMajorVersion, int glMinorVersion, int useDoubleBuffering);

/*
Call when program is done
*/
void tearDown(SDL_Window*& window);

#endif