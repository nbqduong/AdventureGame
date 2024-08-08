//
// Created by duong on 8/3/24.
//

#ifndef PARAMETERS_H
#define PARAMETERS_H


#define DEBUG_MODE

struct CURRENT {
    //Basic display parameters
    static constexpr uint16_t mScreenWidth{1600};
    static constexpr uint16_t mScreenHeight{960};
    static constexpr uint16_t mViewUnit{32};
    static constexpr uint16_t mSourceUnit{64};
    static constexpr uint16_t mFrame{64};



    //Derived display parameters
    static constexpr uint16_t mSourceonView{mSourceUnit/mViewUnit};
    static constexpr uint8_t mScale{1};
    static constexpr uint16_t mHeroMaxFrame{2};
    static constexpr uint8_t mRightMost{uint8_t(mScreenWidth/mViewUnit)};
    static constexpr uint8_t mDownMost{uint8_t(mScreenHeight/mViewUnit)};



};

enum class WindowsPar
{
    emWindowRunning,
    emWindowExit,
    emWindowsCreateSucessfull,
    emWindowsCreateFail,
};

struct XYWH
{
    uint16_t X{0}, Y{0}, width{CURRENT::mViewUnit}, height{CURRENT::mViewUnit};

    XYWH(uint16_t x, uint16_t y, uint16_t width = CURRENT::mViewUnit, uint16_t height = CURRENT::mViewUnit ):X(x), Y(y), width(width), height(height) {}
    XYWH(const XYWH& other):X(other.X), Y(other.Y), width(other.width), height(other.height){}

    void Set(uint16_t x, uint16_t y, uint16_t width = CURRENT::mViewUnit, uint16_t height = CURRENT::mViewUnit ) {
        this->X = x;
        this->Y = y;
        this->width = width;
        this->height = height;
    }
    void SetPos(uint16_t x, uint16_t y ) {
        this->X = x;
        this->Y = y;
    }
    void SetRange(uint16_t width = CURRENT::mViewUnit, uint16_t height = CURRENT::mViewUnit ) {
        this->width = width;
        this->height = height;
    }

};



enum class Direction {
    Up,
    Down,
    Left,
    Right,

};
#endif //PARAMETERS_H
