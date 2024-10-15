#include "TextureResourceManager.h"
// Static method to access the single instance
TextureResourceManager& TextureResourceManager::GetInstance() {
    static TextureResourceManager instance;
    return instance;
}

TextureResource* TextureResourceManager::Add(const string& source) {
    // Check if the texture already exists
    auto it = _resources.find(source);
    if (it != _resources.end()) {
        // Texture already loaded; return the existing resource
        return &(it->second);
    }

    // Load the new texture
    TextureResource texture(source);  // Create a temporary TextureResource
    if (!texture.GetTexture()) {
        cerr << "Failed to load texture from: " << source << endl;
        return nullptr;
    }

    // Insert the new texture into the _resources map using move semantics
    auto result = _resources.emplace(make_pair(source, move(texture)));
    // This ensures that 'texture' is moved into the map, not copied.

    if (!result.second) {
        cerr << "Failed to insert texture into manager: " << source << endl;
        return nullptr;
    }

    // Return a pointer to the newly added texture
    return &(result.first->second);
}

void TextureResourceManager::Remove(const string& source) {
    // Attempt to remove the texture resource
    auto it = _resources.find(source);
    if (it != _resources.end()) {
        _resources.erase(it);
        cout << "Texture with path " << source << " removed successfully." << endl;
    }
    else {
        cerr << "Texture with path " << source << " not found. Cannot remove." << endl;
    }
}

TextureResource* TextureResourceManager::Get(const string& source) {
    // Retrieve the TextureResource using the file path
    auto it = _resources.find(source);
    if (it != _resources.end()) {
        return &(it->second); // Return pointer to the existing texture
    }
    else {
        cerr << "Texture with path " << source << " not found." << endl;
        return nullptr;
    }
}

TextureResourceManager::~TextureResourceManager()
{
    for (auto& pair : _resources) {
        // Call the destructor of TextureResource to free the SDL_Texture
        // This assumes TextureResource's destructor handles the SDL_DestroyTexture
        pair.second.~TextureResource(); // Explicitly call the destructor (optional, but can be done)
    }
    _resources.clear();
}

