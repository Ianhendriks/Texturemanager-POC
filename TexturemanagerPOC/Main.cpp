
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <crtdbg.h>
#include "Entity.h"
#include "Renderer.h"
#include "SDLRenderer.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //init and load tiles
    SDL_Init(SDL_INIT_EVERYTHING);
    SDLRenderer::init();
    int x = 20;
    int y = 20;
    Entity entity(x, y);
    Renderer texture("./Texture2.png", 10, 10, entity);
    Renderer duplicate("./Texture2.png", 10, 10, entity);
    texture.OnUpdate();
    duplicate.OnUpdate();
    SDL_RenderPresent(SDLRenderer::renderer);
    SDL_RenderClear(SDLRenderer::renderer);
    SDLRenderer::Destroy();
    SDL_Quit();
    _CrtDumpMemoryLeaks();
}
