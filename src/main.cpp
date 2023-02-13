#include "Config.hpp"
#include "Graphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

const Uint32 TIME_FOR_FRAME = 1000 / Config::FPS;

int main(int argc, char **argv) {
  Graphic g;
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Event event;
  Uint32 is_running = 1;

  while (is_running == 1) {
    Uint32 st_time = SDL_GetTicks();
    // Update data

    // Render to screen
    g.update();

    // Handle input
    SDL_PollEvent(&event);
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == Config::KEY_BACK) {
      is_running = 0;
    }

    Uint32 elap_time = SDL_GetTicks() - st_time;
    if (elap_time < TIME_FOR_FRAME) {
      SDL_Delay(TIME_FOR_FRAME - elap_time);
    }
  }
  return 0;
}
