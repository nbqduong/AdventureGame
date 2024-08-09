//
// Created by duong on 8/7/24.
//

#ifndef DECO_H
#define DECO_H
#include <Object.h>
#include <TextureManager.h>

class Deco:public Object{
    XYWH mSrc;
    uint16_t mFrame{0};
public:
    Deco(const char* link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
    virtual void Load();
    virtual void Resize(uint32_t width, uint32_t height);
    virtual void Destroy();
    virtual void ChangeFrame();
    virtual TouchEvent Touched() override{return TouchEvent::emPass;};
    ~Deco();
};

class BoxDeco : public Deco {
    static uint16_t mObjectCount;
    std::string mID;
public:
    BoxDeco(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1);
    TouchEvent Touched() override;

};

class GrassDeco : public Deco {
public:
    GrassDeco(uint8_t collum=0, uint8_t row=0, uint8_t width = 1, uint8_t height = 1)
    :Deco("../assets/Grass.png", "Grass", row,collum,width,height) {}
};



#endif //DECO_H
