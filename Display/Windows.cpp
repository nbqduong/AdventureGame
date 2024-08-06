//
// Created by duong on 8/2/24.
//

#include "Windows.h"



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
    TextureManager::GetInstance()->setRenderer(mRenderer);
    mStatus = WindowsPar::emWindowRunning;
    return  WindowsPar::emWindowsCreateSucessfull;

}


void Windows::checkEvent(SDL_Event &event) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        mStatus = WindowsPar::emWindowExit;
    }
}

void Windows::setRender(std::vector<std::shared_ptr<Object>> &obj) {

    SDL_SetRenderDrawColor(mRenderer, 193, 224, 245,255);
    SDL_RenderClear(mRenderer);

    for (auto const &i : obj)
        i->Load();
    //TextureManager::GetInstance()->Draw("tree", 100,100,64,64);
    SDL_RenderPresent(mRenderer);
}

Windows::~Windows() {
    Debug::Console("Windows destructor");
    //Destroy Renderer
    SDL_DestroyRenderer(mRenderer);
    SDL_Log("Destroy renderer");
    //Destroy window
    SDL_DestroyWindow( mWindow );
    SDL_Log("Destroy Window");
}

