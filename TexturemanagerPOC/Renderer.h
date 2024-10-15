#pragma once
#include "Component.h"
#include "TextureResource.h"
#include "TextureResourceManager.h"


class Renderer : public Component
{
public:
	Renderer(const string& source, int width, int height, Entity& entity);
	~Renderer() = default;
	void OnUpdate();

private:
	const TextureResource* _texture;
	static TextureResourceManager& _manager;
	const int _width;
	const int _height;
};

