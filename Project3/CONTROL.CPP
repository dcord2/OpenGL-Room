#include "Control.h"

Control::Control(Model& model, View& view):model(model),view(view) {
	key_state = SDL_GetKeyboardState(nullptr);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void Control::handlInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEMOTION) {
			view.camera.pitch -= event.motion.yrel * 0.01f;
			view.camera.yaw -= event.motion.xrel * 0.01f;
		}
		if (event.type == SDL_QUIT) { break_var = -1; }
	}

	if (key_state[SDL_SCANCODE_R]) { model.background_color = std::vector<double>{ 1,0,0,1 }; }
	if (key_state[SDL_SCANCODE_G]) { model.background_color = std::vector<double>{ 0,1,0,1 }; }
	if (key_state[SDL_SCANCODE_B]) { model.background_color = std::vector<double>{ 0,0,1,1 }; }
	if (key_state[SDL_SCANCODE_1]) { model.background_color = std::vector<double>{ 0,0,0,1 }; }
	if (key_state[SDL_SCANCODE_2]) { model.background_color = std::vector<double>{ .5,.5,.5,1 }; }
	if (key_state[SDL_SCANCODE_3]) { model.background_color = std::vector<double>{ 1,1,1,1 }; }

	if (key_state[SDL_SCANCODE_W]) { view.camera.position += view.camera.direction; }
	if (key_state[SDL_SCANCODE_A]) { view.camera.position -= view.camera.right; }
	if (key_state[SDL_SCANCODE_S]) { view.camera.position -= view.camera.direction; }
	if (key_state[SDL_SCANCODE_D]) { view.camera.position += view.camera.right; }

	if (key_state[SDL_SCANCODE_UP]) { view.light_position[2] += 10.0f; }
	if (key_state[SDL_SCANCODE_DOWN]) { view.light_position[2] -= 10.0f; }
	if (key_state[SDL_SCANCODE_LEFT]) { view.light_position[0] += 10.0f; }
	if (key_state[SDL_SCANCODE_RIGHT]) { view.light_position[0] -= 10.0f; }
	if (key_state[SDL_SCANCODE_N]) { view.light_position[1] += 10.0f; }
	if (key_state[SDL_SCANCODE_M]) { view.light_position[1] -= 10.0f; }

	if (key_state[SDL_SCANCODE_ESCAPE]) { break_var = -1; }
}