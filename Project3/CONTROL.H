#ifndef CONTROL
#define CONTROL

#include "SDL.h"
#include "Model.h"
#include "View.h"
#include "Camera.h"
#include "GLInit.h"

class Control {
private:
	Model& model;
	View& view;
	const Uint8* key_state;
public:
	void handlInput();
	Control(Model& model, View& view);

	int break_var = 0;
};

#endif
