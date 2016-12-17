#include <SDL2/SDL.h>
#include <cstdint>
#include <string>


class Window
{
public:
	static const int WIDTH;
	static const int HEIGHT;

	static SDL_Window *window;
	static SDL_Renderer *renderer;

	static void init(uint32_t flags);
	static void createWindow(std::string title, int x, int y, int w, int h, uint32_t flags = NULL);
	static void createRenderer();
};
