//
// Created by duong on 8/3/24.
//

#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <memory>
#include <mutex>
#include <SDL2/SDL.h>
#include <Windows.h>


class Engine {
private:
     // Hero H;
     static std::shared_ptr<Engine> mEngine;
     static std::once_flag mInitFlag;
     std::shared_ptr<Windows> mMainWindow{nullptr};
     Engine();
public:
     static std::shared_ptr<Engine> getInstance();
     inline std::shared_ptr<Windows> getMainWindow(){return mMainWindow;}

     bool Init();
     void Start();

     ~Engine();
};



#endif //ENGINE_H
