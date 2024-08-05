//
// Created by duong on 8/2/24.
//

#include "Windows.h"

#include <mutex>

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
    mScreenSurface = SDL_GetWindowSurface( mWindow );
    if( mScreenSurface == nullptr )
    {
        Error::SdlError("Could not get window surface!", SDL_GetError());
        return WindowsPar::emWindowsCreateFail;
    }


    setWindowSurface(nullptr, SDL_MapRGB( mScreenSurface->format, 0xFF, 0xFF, 0xFF ) );

    mStatus = WindowsPar::emWindowRunning;
    return  WindowsPar::emWindowsCreateSucessfull;

}


void Windows::checkEvent(SDL_Event &event) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        mStatus = WindowsPar::emWindowExit;
    }
}

void Windows::setWindowSurface(const SDL_Rect *rect, Uint32 color) const {
    //Fill the surface white
    SDL_FillRect( mScreenSurface, rect, color );
    //Update the surface
    SDL_UpdateWindowSurface( mWindow );
}

Windows::~Windows() {
    Debug::ConsoleMessage("Windows destructor");

    //Destroy window
    SDL_DestroyWindow( mWindow );
}

