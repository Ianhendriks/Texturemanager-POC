#pragma once
#include <string>
#include <SDL2/SDL_render.h>
using namespace std;
class TextureResource
{
public:
    TextureResource(const string& source);
    ~TextureResource();

    // Disable copy semantics
    TextureResource(const TextureResource&) = delete;
    TextureResource& operator=(const TextureResource&) = delete;

    // Enable move semantics
    TextureResource(TextureResource&& other) noexcept;
    TextureResource& operator=(TextureResource&& other) noexcept;

    SDL_Texture* GetTexture() const { return _texture; }

private:
    SDL_Texture* _texture;
};

