#include "../include/SDL3_Context.hpp"
#include <SDL3/SDL_render.h>
#include <iostream>

Term_SDL::Term_SDL(){};
Term_SDL::~Term_SDL(){
    if(window != NULL)
        SDL_DestroyWindow(window);
    if(render != NULL)
        SDL_DestroyRenderer(render);
    SDL_Quit();
};

bool Term_SDL::init_SDL_Window(){
    window = nullptr;
    render = nullptr;

    if (!SDL_CreateWindowAndRenderer("Term-fy", 800, 600, 0, &window, &render)){
        std::cerr << "Error on create window and render " << SDL_GetError() << "\n";
        SDL_Quit();
        return -1;
    }
    return true;    
}

