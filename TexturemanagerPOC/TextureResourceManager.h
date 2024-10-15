#pragma once
#include <string>
#include <fstream>
#include "TextureResource.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std; 
class TextureResourceManager
{
public:
	TextureResourceManager() = default;
	~TextureResourceManager();
	TextureResourceManager(const TextureResource&) = delete;
	TextureResourceManager& operator=(const TextureResource&) = delete;
	TextureResourceManager(TextureResource&&) = delete;
	TextureResourceManager& operator=(TextureResource&&) = delete;
	static TextureResourceManager& GetInstance();

	TextureResource* Add(const string& source);
	void Remove(const string& source);
	TextureResource* Get(const string& source);
private:
	unordered_map<string, TextureResource> _resources;
};

