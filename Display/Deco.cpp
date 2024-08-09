//
// Created by duong on 8/7/24.
//

#include "Deco.h"



Deco::Deco(const char *link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height) :Object(link,m_id,x,y,width,height),
                                                                                                                mSrc(0,0, CURRENT::mSourceUnit, CURRENT::mSourceUnit){
    TextureManager::GetInstance()->Load(m_id, link);
}

void Deco::Load() {
    TextureManager::GetInstance()->DrawFrame(mID, mSrc,mView);
}

void Deco::Resize(uint32_t width, uint32_t height) {
    this->mView.width = width;
    this->mView.height = height;
}

void Deco::Destroy() {
    TextureManager::GetInstance()->Drop(mID);
}

void Deco::ChangeFrame() {
    // if(mFrame >= DEFAULT::mHeroMaxFrame) {
    //     mFrame = 0;
    // }
    // mSrc = GamePosition::GetSrc(mFrame++,0);
}

Deco::~Deco() {
    Destroy();
}

BoxDeco::BoxDeco(uint8_t collum, uint8_t row, uint8_t width, uint8_t height)
:Deco("../assets/Box.png", "Box", row,collum,width,height) {
    mID = "Box" + std::to_string(mObjectCount);
}

TouchEvent BoxDeco::Touched() {
    Debug::Console("Awwwwwwww");
    return TouchEvent::emBlock;
}

uint16_t BoxDeco::mObjectCount = 0;
