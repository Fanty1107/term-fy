#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../include/SDL3_Context.hpp"
#include <cstdlib>
#include <iostream>

#define SDL_WINDOW_FLAGS (SDL_WINDOW_RESIZABLE)

int main() {
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "Error in sdl_init: " << SDL_GetError();
        return EXIT_FAILURE;
    }
    if(!TTF_Init()){
        std::cerr << "Error in init ttf lib: " << SDL_GetError();
        return EXIT_FAILURE;
    }

    Term_SDL app;
    app.init_SDL_Window();

    TTF_Font *font = TTF_OpenFont("../hello-christmas-font/HelloChristmas-1Ge70.ttf", 64);
    if(font == NULL){
        std::cerr << "Error in open font: " << SDL_GetError();
        return EXIT_FAILURE;
    }
    SDL_Texture* textTexture = nullptr;
    SDL_FRect destRect = {0.0f, 0.0f, 0.0f, 0.0f};
    if(font){
        SDL_Color textColor = {255,255,255,255};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Hello World", 0, textColor);

        if(textSurface){
            textTexture = SDL_CreateTextureFromSurface(app.render, textSurface);
            
            destRect.x = 150.0f;
            destRect.y = 250.0f;
            destRect.w = static_cast<float>(textSurface->w);
            destRect.h = static_cast<float>(textSurface->h);

            SDL_DestroySurface(textSurface);
        }else {
            std::cerr << "Erro ao gerar a surface do texto: " << SDL_GetError() << "\n";
        }
    }


    bool IsRunning = true;
    SDL_Event Event;
    app.event = &Event;

    while (IsRunning) {
        while (SDL_PollEvent(app.event)) {
        if (app.event->type == SDL_EVENT_QUIT) {
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
        SDL_SetRenderDrawColor(app.render, 0,0,0,255);
        SDL_RenderClear(app.render);

        if(textTexture){
            SDL_RenderTexture(app.render, textTexture, nullptr, &destRect);
        }
        SDL_RenderPresent(app.render);
    }
    SDL_DestroyRenderer(app.render);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}
