#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../include/SDL3_Context.hpp"
#include <iostream>

#define SDL_WINDOW_FLAGS (SDL_WINDOW_RESIZABLE)

int main() {
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "Error in sdl_init: " << SDL_GetError();
        return EXIT_FAILURE;
    }
    Term_SDL app;
    app.init_SDL_Window();

    SDL_GetWindowSurface(app.window);
    SDL_UpdateWindowSurface(app.window);

    bool IsRunning = true;
    SDL_Event Event;
    app.event = &Event;

    while (IsRunning) {
        while (SDL_PollEvent(app.event)) {
        if (Event.type == SDL_EVENT_QUIT) {
            IsRunning = false;
            }
        if(Event.type == SDL_EVENT_KEY_DOWN){
                SDL_Keycode key = SDL_GetKeyFromScancode(Event.key.scancode, Event.key.mod, false);
            if (key == '$') {
                IsRunning = false;
                }
            else{
                SDL_Log("%s", SDL_GetKeyName(key));
                }
            }
        }
    }
    return 0;
}
