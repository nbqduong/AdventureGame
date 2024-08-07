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
        Error::Fatal("Game engine false to init");
    }

    std::shared_ptr<Hero> hero = std::make_shared<BasicHero>(),
        hero2 = std::make_shared<SimpleHero>();


    std::vector<std::shared_ptr<Object>> objects{hero, hero2};

    SDL_Event event;
    const Uint8* m = SDL_GetKeyboardState(nullptr);
    while (mMainWindow->isRunning() == WindowsPar::emWindowRunning) {
        mMainWindow->checkEvent(event);
        mMainWindow->setRender(objects);
        if(KeyBoard::GetInstance()->GetKey(SDL_SCANCODE_DOWN)) {
            hero->Move(Direction::Down);
            hero->ChangeFrame();
        }
        if(KeyBoard::GetInstance()->GetKey(SDL_SCANCODE_UP)) {
            hero->Move(Direction::Up);
            hero->ChangeFrame();
        }


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

