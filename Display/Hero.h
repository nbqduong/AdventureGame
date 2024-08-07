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
     BasicHero():Hero("../assets/BasicHero.png", "BasicHero", 0,0,1,1){}
 };

class SimpleHero : public Hero {
public:
    SimpleHero():Hero("../assets/SimpleHero.png", "SimpleHero", 0,0,1,1){}
};


#endif //HERO_H
