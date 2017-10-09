#pragma once

#include "Textures.h"
#include "Sprites.h"
#include "SDL2/SDL.h"

typedef struct
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int xres;
    int yres;
    int fps;
    Surfaces surfaces;
    Textures textures;
}
Sdl;

Sdl xsetup(const int xres, const int yres, const int fps);

void xrelease(const Sdl sdl);

// Renders one one frame with SDL using hero, sprite, and map data. Ticks determine animation
void xrender(const Sdl sdl, const Hero hero, const Sprites sprites, const Map map, const int ticks);
