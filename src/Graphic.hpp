#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "Config.hpp"
#include <SDL2/SDL.h>

class Graphic {
public:
  Graphic();
  ~Graphic();

  void update();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif
