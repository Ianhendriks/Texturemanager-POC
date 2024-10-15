#include "TextureResource.h"

#include <iostream>
#include <ostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDLRenderer.h"


TextureResource::TextureResource(const string& source) : _texture(nullptr)
{
    SDL_Surface* surface = IMG_Load(source.c_str());
    if (!surface) {
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return; // Or handle the error as appropriate
    }
    _texture = SDL_CreateTextureFromSurface(SDLRenderer::renderer, surface);
    SDL_FreeSurface(surface);
}

TextureResource::~TextureResource()
{
    //destroy texture
    if (_texture) 
    {
        SDL_DestroyTexture(_texture);
    }
    _texture = nullptr;
}

TextureResource::TextureResource(TextureResource&& other) noexcept : _texture(other._texture)
{
    other._texture = nullptr;
}

// Move assignment
TextureResource& TextureResource::operator=(TextureResource&& other) noexcept
{
    if (this != &other) {
        // Clean up current resource
        if (_texture) {
            SDL_DestroyTexture(_texture);
        }
        // Transfer ownership
        _texture = other._texture;
        other._texture = nullptr;  // Nullify the old resource
    }
    return *this;
}

