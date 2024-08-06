//
// Created by duong on 8/5/24.
//

#include "TextureManager.h"




std::shared_ptr<TextureManager> TextureManager::sInstance = nullptr;

bool TextureManager::Load(std::string id, std::string filename) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if(surface == nullptr){
        SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    if(texture == nullptr){
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return false;
    }

    mTextureMap[id] = texture;
    return true;
}

void TextureManager::Drop(std::string id) {
    SDL_DestroyTexture(mTextureMap[id]);
    mTextureMap.erase(id);
}

void TextureManager::Clean() {
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = mTextureMap.begin(); it != mTextureMap.end(); it++)
        SDL_DestroyTexture(it->second);

    mTextureMap.clear();

    SDL_Log("texture map cleaned!");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int heigt, SDL_RendererFlip flip) {
    SDL_Rect srcRect = {0, 0, width, heigt};
    SDL_Rect dstRect = {x, y, width, heigt};
    SDL_RenderCopyEx(mRenderer,mTextureMap[id], &srcRect, &dstRect,0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, XYWH &src, XYWH &dst, SDL_RendererFlip flip) {
    SDL_Rect srcRect = {src.X, src.Y, src.width, src.height};
    SDL_Rect dstRect = {dst.X, dst.Y, dst.width, dst.height};
    SDL_RenderCopyEx(mRenderer,mTextureMap[id], &srcRect, &dstRect,0, nullptr, flip);
}

void TextureManager::setRenderer(SDL_Renderer *renderer) {
    this->mRenderer = renderer;
}

TextureManager::~TextureManager() {
    Debug::Console("TXM destructor");
}
