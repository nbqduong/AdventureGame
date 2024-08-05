//
// Created by duong on 8/2/24.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
#include <memory>
#include <mutex>
#include <SDL2/SDL.h>

#include "../Parameters.h"

class Windows {
private:
    int mWidth;
    int mHeight;
    WindowsPar mStatus{WindowsPar::emWindowExit};
    SDL_Window* mWindow;
    SDL_Surface* mScreenSurface;
    SDL_Renderer* mRenderer;


public:
    Windows(const char* windows_name= "Adventure Game",uint16_t width=1600, uint16_t height=900);

    WindowsPar create(const char* name, uint16_t width, uint16_t height);

    inline WindowsPar isRunning() const {return mStatus;};

    void checkEvent(SDL_Event &event);

    void setWindowSurface(const SDL_Rect * rect, Uint32 color) const;

    ~Windows();
};



#endif //WINDOWS_H
