#include "SDLRenderer.h"

SDL_Window* SDLRenderer::window = nullptr;
SDL_Renderer* SDLRenderer::renderer = nullptr;

void SDLRenderer::init()
{
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

void SDLRenderer::Destroy()
{
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}
}