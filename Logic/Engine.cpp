//
// Created by duong on 8/3/24.
//

#include "Engine.h"

Engine::Engine() {

}

std::shared_ptr<Engine> Engine::getInstance()
{
    if(mEngine == nullptr) {
        mEngine = std::shared_ptr<Engine>(new Engine);
        return mEngine;
    }
    return mEngine;
}

bool Engine::Init() {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0  && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else {
        mMainWindow = std::make_shared<Windows>();
    }
    return true;
}

void Engine::Start() {
    if(Init() == false) {
        Error::Fatal("False to init");
    }

    std::shared_ptr<Hero> hero = std::make_shared<Hero>("../assets/face.png","tree", 0,0,64 ,64),
        hero2 = std::make_shared<Hero>("../assets/face.png","hel", 100,100,64 ,64);


    std::vector<std::shared_ptr<Object>> objects{hero, hero2};

    SDL_Event event;
    while (mMainWindow->isRunning() == WindowsPar::emWindowRunning) {
        hero->Move(Direction::Down);
        mMainWindow->checkEvent(event);
        mMainWindow->setRender(objects);
        Debug::Console("running");
        SDL_Delay(100);
    }
}

Engine::~Engine() {
    TextureManager::GetInstance()->Clean();
    SDL_Log("Engine Destructor");
    //Quit IMG
    IMG_Quit();
    //Quit SDL subsystems
    SDL_Quit();
}

std::shared_ptr<Engine> Engine::mEngine = nullptr;
std::once_flag Engine::mInitFlag;

