//
// Created by duong on 8/2/24.
//

#include "Windows.h"

#include <mutex>
#include <TextureManager.h>

Windows::Windows(const char* windows_name, uint16_t width, uint16_t height)
        : mWidth(width),
          mHeight(height) {
    create(windows_name, this->mWidth, this->mHeight);
}

WindowsPar Windows::create(const char *name, uint16_t width, uint16_t height) {
    //Create window
    mWindow = SDL_CreateWindow( name, 0, 0, width, height, SDL_WINDOW_SHOWN );
    if( mWindow == nullptr )
    {
        Error::SdlError("Window could not be created!", SDL_GetError());
        return WindowsPar::emWindowsCreateFail;
    }
    //Get window surface
    mRenderer = SDL_CreateRenderer( mWindow ,-1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if( mRenderer == nullptr )
    {
        Error::SdlError("Could not get window rederer!", SDL_GetError());
        return WindowsPar::emWindowsCreateFail;
    }

    mStatus = WindowsPar::emWindowRunning;
    return  WindowsPar::emWindowsCreateSucessfull;

}


void Windows::checkEvent(SDL_Event &event) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        mStatus = WindowsPar::emWindowExit;
    }
}

void Windows::setSurface(const SDL_Rect *rect, Uint32 color) const {
    //Fill the surface white
    SDL_FillRect( mScreenSurface, rect, color );
    //Update the surface
    SDL_UpdateWindowSurface( mWindow );
}

void Windows::setRender() {
    SDL_SetRenderDrawColor(mRenderer, 193, 224, 245,255);
    SDL_RenderClear(mRenderer);

    TextureManager::GetInstance()->Draw("tree", 100,100,347,365);
    SDL_RenderPresent(mRenderer);
}

Windows::~Windows() {
    Debug::Console("Windows destructor");

    //Destroy window
    SDL_DestroyWindow( mWindow );
}

