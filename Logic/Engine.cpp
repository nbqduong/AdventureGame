//
// Created by duong on 8/3/24.
//

#include "Engine.h"

#include "Deco.h"
#include "Frame.h"
#include "MovementManager.h"
#include "ObjectFactory.h"

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
    auto objects{ObjectFactory::GetInstance()->GetObject()};
    auto m = SDL_GetKeyboardState(nullptr);
    auto input = KeyBoard::GetInstance();
    auto move = MovementManager::GetInstance();
    auto frame = Frame::GetInstance();

    /*-------------------------THE GAME LOOP---------------------------------*/
    while (true) {

        mMainWindow->setRender(objects);
        auto event = input->GetEvent();
        if(event == UserEvent::emQuit) {
            return;
        }
        move->Move(event);
        frame->Delay();
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

