//
// Created by duong on 8/2/24.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
#include <SDL2/SDL.h>

class Windows {
private:
    int width;
    int heigh;
    SDL_Window* window;
    SDL_Surface* screenSurface;

public:
    Windows(int x=640, int y=480);

    ~Windows();
};



#endif //WINDOWS_H
