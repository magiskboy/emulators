#include "InputHandler.hpp"
#include "Config.hpp"
#include <SDL2/SDL_events.h>

InputHandler::InputHandler() {}

InputHandler::~InputHandler() {}

void InputHandler::update() {
  if (SDL_PollEvent(&this->event)) {
    if (this->event.type == SDL_KEYDOWN &&
        this->event.key.keysym.sym == Config::KEY_BACK) {
    }
  }
}
