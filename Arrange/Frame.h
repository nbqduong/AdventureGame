//
// Created by duong on 8/8/24.
//

#ifndef FRAME_H
#define FRAME_H
#include <cstdint>
#include <memory>
#include <Parameters.h>


class Frame {
    const uint16_t mSecond = 1000;
    constexpr static uint16_t mFrame{CURRENT::mFrame};
    uint16_t mDelay{static_cast<uint16_t>(mSecond/mFrame)};
    uint32_t mLastTick;
    uint32_t mThisTick;
    static std::shared_ptr<Frame> mInstance;
    Frame();
public:
    static std::shared_ptr<Frame> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<Frame>(new Frame());}
    void Delay();

};



#endif //FRAME_H
