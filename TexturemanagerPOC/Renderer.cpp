#include "Renderer.h"

#include "SDLRenderer.h"

TextureResourceManager& Renderer::_manager = TextureResourceManager::GetInstance();

Renderer::Renderer(const string& source, int width, int height, Entity& entity) :
	Component(entity),
	_width(width),
	_height(height)
{
	_texture = _manager.Get(source);
	if(_texture == nullptr)
	{
		_texture = _manager.Add(source);
	}
}

void Renderer::OnUpdate()
{
	SDL_Rect rect = { entity.x, entity.y, _width, _height };
	SDL_RenderCopy(SDLRenderer::renderer, _texture->GetTexture(), nullptr, &rect);
}

