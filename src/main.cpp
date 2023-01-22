#include "Config.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

const Uint32 TIME_FOR_FRAME = 1000 / Config::FPS;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *wind = SDL_CreateWindow(
      Config::WINDOW_TITLE.c_str(), Config::WINDOWPOS_X, Config::WINDOWPOS_Y,
      Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::WINDOW_FLAGS);
  if (wind == NULL) {
    perror(SDL_GetError());
    return 1;
  }

  SDL_Renderer *rR = SDL_CreateRenderer(wind, 0, Config::RENDERER_FLAGS);
  if (rR == NULL) {
    perror(SDL_GetError());
    return 1;
  }

  SDL_Event event;
  Uint32 is_running = 1;
  while (is_running == 1) {
    Uint32 st_time = SDL_GetTicks();
    // Update data

    // Render to screen
    SDL_SetRenderDrawColor(rR, 0, 0, 0, 1);
    SDL_RenderClear(rR);
    SDL_RenderPresent(rR);

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
