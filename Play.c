#include "Play.h"

#include "Hero.h"
#include "Sdl.h"
#include "Map.h"
#include "Sprites.h"
#include "Input.h"

static bool done(const uint8_t* const key)
{
    return key[SDL_SCANCODE_F1];
}

extern void play(const char* argv[])
{
    const int res = strtol(argv[1], NULL, 0);
    const int fps = 60;
    Hero hero = spawn();
    Map map = open(hero.level);
    Sprites sprites = wake(hero.level);
    Sdl sdl = setup(res, fps);
    Input input = ready();
    for(int renders = 0; res == 128 ? renders < fps : !done(input.key); renders++)
    {
        const int t0 = SDL_GetTicks();
        // Data
        if(teleporting(hero, map, input, sdl.ticks))
        {
            hero = teleport(hero, map);
            map = reopen(map, hero.level);
            sprites = rewake(sprites, hero.level);
        }
        hero = sustain(hero, sprites, map, input);
        sprites = caretake(sprites, hero, input);
        // Output
        render(sdl, hero, sprites, map);
        sdl = tick(sdl, renders);
        const int t1 = SDL_GetTicks();
        const int ms = 1000.0 / sdl.fps - (t1 - t0);
        SDL_Delay(ms < 0 ? 0 : ms);
        // Input
        input = pump(input);
    }
    release(sdl);
    close(map);
    kill(sprites);
}
