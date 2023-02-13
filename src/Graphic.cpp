#include "Graphic.hpp"

Graphic::Graphic() {
  this->window = SDL_CreateWindow(
      Config::WINDOW_TITLE.c_str(), Config::WINDOWPOS_X, Config::WINDOWPOS_Y,
      Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, Config::WINDOW_FLAGS);
  if (this->window == NULL) {
    perror(SDL_GetError());
  }

  this->renderer = SDL_CreateRenderer(this->window, 0, Config::RENDERER_FLAGS);
  if (this->renderer == NULL) {
    perror(SDL_GetError());
  }
}

Graphic::~Graphic() {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
}

void Graphic::update() {
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 1);
  SDL_RenderClear(this->renderer);
  SDL_RenderPresent(this->renderer);
}
