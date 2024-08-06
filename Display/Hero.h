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
    void Load();
    void Move(uint32_t x, uint32_t y);
    void Move(Direction dir);
    void Resize(uint32_t width, uint32_t height);
    void Destroy();
    void ChangeFrame();
    ~Hero();
};



#endif //HERO_H
