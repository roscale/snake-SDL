#pragma once

#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

namespace MySDL
{
	void init(uint32_t flags);
	SDL_Window* createWindow(std::string title, int x, int y, int w, int h, uint32_t flags = NULL);
	SDL_Renderer* createRenderer(SDL_Window* window);
}
