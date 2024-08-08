//
// Created by duong on 8/6/24.
//

#include "Hero.h"


Hero::Hero(const char* link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    :Object(link,m_id,x,y,width,height),
    mSrc(0,0, CURRENT::mSourceUnit, CURRENT::mSourceUnit)
{
    TextureManager::GetInstance()->Load(m_id, link);
}

void Hero::Load() {

    TextureManager::GetInstance()->DrawFrame(mID, mSrc,mView);

}


void Hero::Move(uint32_t x, uint32_t y) {
    this->mView.X=x;
    this->mView.Y=y;
}

void Hero::Move(Direction dir) {
    GamePosition::Move(dir, this->mView);
}

void Hero::Resize(uint32_t width, uint32_t height) {
    this->mView.width = width;
    this->mView.height = height;
}

void Hero::Destroy() {
    TextureManager::GetInstance()->Drop(mID);
}

void Hero::ChangeFrame() {
    if(mFrame >= CURRENT::mHeroMaxFrame) {
        mFrame = 0;
    }
    mSrc = GamePosition::GetSrc(mFrame++,0);
}

Hero::~Hero() {
    Destroy();
    Debug::BasePrint(mID.c_str()," Hero destructor");
}
