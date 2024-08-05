//
// Created by duong on 8/3/24.
//

#include "Engine.h"

Engine::Engine() {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
        std::shared_ptr<Windows> my_windows = std::make_shared<Windows>();

        // my_windows

        bool game;
        SDL_Event event;
        //Wait two seconds

        while (my_windows->isRunning() == WindowsPar::emWindowRunning) {

            my_windows->checkEvent(event);
            Debug::ConsoleMessage("running");

        }
    }
}

std::shared_ptr<Engine> Engine::getInstance()
{
    std::call_once(initFlag, []() {
            engine_.reset(new Engine());  // Create the Singleton instance
        });
    return engine_;
}

Engine::~Engine() {
    Debug::ConsoleMessage("Engine Destructor");
    //Quit SDL subsystems
    SDL_Quit();
}

std::shared_ptr<Engine> Engine::engine_ = nullptr;
std::once_flag Engine::initFlag;

