//
// Created by duong on 8/7/24.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <memory>
#include <SDL.h>

enum class UserEvent {
    emOther,
    emQuit,
    emKeyUp,
    emKeyDown,
};

class KeyBoard {
    static  std::shared_ptr<KeyBoard> mInstance;
    const Uint8* mKeyState;
    KeyBoard():mKeyState{SDL_GetKeyboardState(nullptr)}{}
public:
    static std::shared_ptr<KeyBoard> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<KeyBoard>(new KeyBoard());}
    UserEvent Listen();
    void Quit();
    void KeyUp();
    void KeyDown();
    bool GetKey(SDL_Scancode key);

};



#endif //KEYBOARD_H
