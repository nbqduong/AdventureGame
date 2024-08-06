//
// Created by duong on 8/5/24.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <memory>
#include <Debug.h>
#include <GamePosition.h>
#include <Parameters.h>


class TextureManager {
        public:
        static std::shared_ptr<TextureManager> GetInstance(){ return sInstance = (sInstance != nullptr)? sInstance : std::shared_ptr<TextureManager>(new TextureManager());}

        bool Load(std::string id, std::string filename);
        void Drop(std::string id);
        void Clean();

        void Draw(std::string id, int x, int y, int width, int heigt, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void DrawFrame(std::string id, XYWH &src, XYWH &dst, SDL_RendererFlip flip=SDL_FLIP_NONE);
        void setRenderer(SDL_Renderer* renderer);
        ~TextureManager();
    private:
        TextureManager(){}
        std::map<std::string, SDL_Texture*> mTextureMap;
        SDL_Renderer* mRenderer;
        static std::shared_ptr<TextureManager> sInstance;
};



#endif //TEXTUREMANAGER_H
