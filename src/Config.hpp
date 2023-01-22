#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "ConfigReader.hpp"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_stdinc.h>
#include <cstdint>
#include <string>

class Config {
public:
  static int WINDOWPOS_X;
  static int WINDOWPOS_Y;
  static int WINDOW_HEIGHT;
  static int WINDOW_WIDTH;
  static Uint32 WINDOW_FLAGS;
  static std::string WINDOW_TITLE;
  static Uint32 RENDERER_FLAGS;
  static SDL_KeyCode KEY_BACK;
  static uint32_t FPS;
};

#endif
