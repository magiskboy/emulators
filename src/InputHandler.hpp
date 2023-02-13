#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SDL2/SDL_events.h>

class InputHandler {
public:
  InputHandler();
  ~InputHandler();

  void update();

private:
  SDL_Event event;
};

#endif
