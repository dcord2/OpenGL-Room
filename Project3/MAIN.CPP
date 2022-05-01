#include "Main.h"

int main(int argc, char* argv[]) {
    SDL_Window* main_window;
    init(main_window);

    Model model;
    Camera camera;
    View view(model,camera);
    Control control(model,view);

    const double dt = 10;
    double accumulatedTime = 0.0;
    double lastTime = SDL_GetTicks();
    double currentTime;

    //Main Loop
    while (true) {

        currentTime = SDL_GetTicks();
        accumulatedTime += currentTime - lastTime;
        lastTime = currentTime;

        //Input
        control.handlInput();
        if (control.break_var == -1) { break; }

        //Simulation speed control?
        while (accumulatedTime > dt) {
            //timeStepModel(model, dt); //move the model dt time forward
            accumulatedTime -= dt;
        }

        //Render
        view.render(main_window);

    }
    
    tearDown(main_window);

    return 0;
}