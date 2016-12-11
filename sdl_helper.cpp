#include "sdl_helper.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdint>
#include <string>

namespace MySDL
{
	void init(uint32_t flags)
	{
		if (SDL_Init(flags) < 0)
		{
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
			exit(1);
		}
	}

	SDL_Window* createWindow(std::string title, int x, int y, int w, int h, uint32_t flags)
	{
		SDL_Window *window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

		if(window == NULL)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
			exit(2);
		}

		return window;
	}

	SDL_Renderer* createRenderer(SDL_Window* window)
	{
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if(renderer == NULL)
		{
			std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << '\n';
			exit(3);
		}

		return renderer;
	}
}
