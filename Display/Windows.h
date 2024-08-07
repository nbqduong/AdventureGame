//
// Created by duong on 8/2/24.
//

#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
#include <memory>
#include <mutex>
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "Parameters.h"
#include "Debug.h"
#include <Object.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <Hero.h>
#include <KeyBoard.h>

class Windows {
private:
    int mWidth;
    int mHeight;
    WindowsPar mStatus{WindowsPar::emWindowExit};
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;


public:
    Windows(const char* windows_name= "Adventure Game",uint16_t width=DEFAULT::mScreenWidth, uint16_t height = DEFAULT::mScreenHeight);

    WindowsPar create(const char* name, uint16_t width, uint16_t height);

    inline WindowsPar isRunning() const {return mStatus;};

    void checkEvent(SDL_Event &event);

    void setSurface(const SDL_Rect * rect, Uint32 color) const;

    void setRender(std::vector<std::shared_ptr<Object>> &obj);

    inline SDL_Renderer* getRenderer(){return mRenderer;}

    ~Windows();
};



#endif //WINDOWS_H
