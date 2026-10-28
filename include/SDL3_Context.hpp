#ifndef SDL3_Context_HPP
#define SDL3_Context_HPP

#include <SDL3/SDL.h>
#define SDL_WINDOW_FLAGS (SDL_WINDOW_RESIZABLE)

class Term_SDL{
    public:
        SDL_Window *window;
        SDL_Renderer *render;
        SDL_Event *event;
        Term_SDL();
        ~Term_SDL();
        bool init_SDL_Window();
};

#endif// SDL3_Context_HPP


