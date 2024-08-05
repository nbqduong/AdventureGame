//
// Created by duong on 8/3/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <memory>
#include <mutex>
#include <SDL2/SDL.h>
#include"../Display/Windows.h"

class Engine {
private:
     static std::shared_ptr<Engine> engine_;
     static std::once_flag initFlag;
     Engine();
public:
     static std::shared_ptr<Engine> getInstance();

     ~Engine();
};



#endif //ENGINE_H
