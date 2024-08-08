//
// Created by duong on 8/6/24.
//

#ifndef GAMPOS_H
#define GAMPOS_H
#include <cstdint>
#include <memory>
#include <Parameters.h>

class GamePosition {
    static uint16_t mScale;
    static uint16_t mViewFactor;
    static uint16_t mSrcFactor;
    static std::shared_ptr<GamePosition> mInstance;

public:
    static std::shared_ptr<GamePosition> GetInstance(){return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<GamePosition>(new GamePosition());}
    static XYWH Get(uint16_t colum, uint16_t row, uint16_t width=1, uint16_t height=1);
    static XYWH GetSrc(uint16_t colum, uint16_t row, uint16_t width=1, uint16_t height=1);
    static bool Move(Direction dir, XYWH &cor);
    static uint16_t GetGamePos(uint16_t Pos);
};



#endif //GAMPOS_H
