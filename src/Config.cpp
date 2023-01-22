#include "Config.hpp"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <cstdint>

int Config::WINDOWPOS_X = SDL_WINDOWPOS_CENTERED;
int Config::WINDOWPOS_Y = SDL_WINDOWPOS_CENTERED;
int Config::WINDOW_WIDTH = 640;
int Config::WINDOW_HEIGHT = 480;
Uint32 Config::WINDOW_FLAGS = SDL_WINDOW_SHOWN;
std::string Config::WINDOW_TITLE = "The Emulators";

Uint32 Config::RENDERER_FLAGS =
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

SDL_KeyCode Config::KEY_BACK = SDLK_ESCAPE;

uint32_t Config::FPS = 60;
