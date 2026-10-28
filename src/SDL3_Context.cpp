#include "../include/SDL3_Context.hpp"
#include <iostream>

Term_SDL::Term_SDL(){};
Term_SDL::~Term_SDL(){
    if(window != NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
};

bool Term_SDL::init_SDL_Window(){
    window = SDL_CreateWindow(
        "Term-fy", 800, 800, SDL_WINDOW_FLAGS
    );
    if(!window){
        std::cerr << "Error in create a window: " << SDL_GetError();
        SDL_Quit();
        return false;
    }
    return true;    
}

