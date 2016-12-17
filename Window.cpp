#include "Window.hpp"
#include <SDL2/SDL.h>
#include <cstdint>
#include <string>
#include <iostream>

SDL_Window *Window::window = nullptr;
SDL_Renderer *Window::renderer = nullptr;

void Window::init(uint32_t flags)
{
	if (SDL_Init(flags) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
		exit(1);
	}
}

void Window::createWindow(std::string title, int x, int y, int w, int h, uint32_t flags)
{
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if(window == NULL)
	{
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
		exit(2);
	}
}

void Window::createRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << '\n';
		exit(3);
	}
}
