#include <SDL3/SDL.h>
#include <iostream>

int main() {
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "Error in sdl_init: " << SDL_GetError();
        return EXIT_FAILURE;
    }

    SDL_Window* window{SDL_CreateWindow(
        "Term-fy", 800, 800, 0
    )};
    if(!window){
        std::cerr << "Error in create a window: " << SDL_GetError();
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    SDL_GetWindowSurface(window);
    SDL_UpdateWindowSurface(window);

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning) {
        while (SDL_PollEvent(&Event)) {
        if (Event.type == SDL_EVENT_QUIT) {
            IsRunning = false;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
