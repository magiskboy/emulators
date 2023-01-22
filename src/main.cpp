#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const Uint32 FPS = 60;
const Uint32 TIME_FOR_FRAME = 1000 / FPS;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *wind =
      SDL_CreateWindow("The game", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  if (wind == NULL) {
    perror(SDL_GetError());
    return 1;
  }

  SDL_Renderer *rR = SDL_CreateRenderer(
      wind, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
      is_running = 0;
    }

    Uint32 elap_time = SDL_GetTicks() - st_time;
    if (elap_time < TIME_FOR_FRAME) {
      SDL_Delay(TIME_FOR_FRAME - elap_time);
    }
  }
  return 0;
}
