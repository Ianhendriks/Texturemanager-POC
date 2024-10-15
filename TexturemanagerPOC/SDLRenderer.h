#pragma once
#include <SDL2/SDL_render.h>


class SDLRenderer
{
public:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static void init();
	~SDLRenderer() = default;
	static void Destroy();
private:
	SDLRenderer() = default;
};

