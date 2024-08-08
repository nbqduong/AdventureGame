//
// Created by duong on 8/6/24.
//

#ifndef HERO_H
#define HERO_H
#include "Object.h"
#include <TextureManager.h>
#include <Debug.h>


class Hero:public Object {
    XYWH mSrc;
    uint16_t mFrame{0};
public:
    Hero(const char* link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
    virtual void Load();
    virtual void Move(uint32_t x, uint32_t y);
    virtual void Move(Direction dir);
    virtual void Resize(uint32_t width, uint32_t height);
    virtual void Destroy();
    virtual void ChangeFrame();
    ~Hero();
};
 class BasicHero : public Hero {
 public:
     BasicHero(uint8_t collum = 0, uint8_t row = CURRENT::mDownMost - 2, uint8_t width = 1, uint8_t height = 1)
        :Hero("../assets/BasicHero.png", "BasicHero", collum,row,width,height){}
 };

class SimpleHero : public Hero {
public:
    SimpleHero(uint8_t collum = 0, uint8_t row = CURRENT::mDownMost - 2, uint8_t width = 1, uint8_t height = 1)
        :Hero("../assets/SimpleHero.png", "SimpleHero",collum,row,width,height){}
};


#endif //HERO_H
