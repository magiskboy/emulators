#ifndef CORE_HPP
#define CORE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

class Core {
public:
  Core();
  ~Core();

  int loop();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif
