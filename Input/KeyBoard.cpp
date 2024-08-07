//
// Created by duong on 8/7/24.
//

#include "KeyBoard.h"

std::shared_ptr<KeyBoard> KeyBoard::mInstance = nullptr;

UserEvent KeyBoard::Listen() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            Quit();
            return UserEvent::emQuit;
        case SDL_KEYUP:
            KeyUp();
            return UserEvent::emKeyUp;
        case SDL_KEYDOWN:
            KeyDown();
            return UserEvent::emKeyDown;
        default:
            return UserEvent::emOther;
    }
}

void KeyBoard::Quit() {
}

void KeyBoard::KeyUp() {
    mKeyState= SDL_GetKeyboardState(nullptr);
}

void KeyBoard::KeyDown() {
    mKeyState= SDL_GetKeyboardState(nullptr);
}

bool KeyBoard::GetKey(SDL_Scancode key) {
    return (mKeyState[key] == 1) ? true : false;

}
