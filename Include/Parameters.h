//
// Created by duong on 8/3/24.
//

#ifndef PARAMETERS_H
#define PARAMETERS_H


#define DEBUG_MODE

struct DEFAULT {
    static constexpr uint16_t mScreenWidth{1600};
    static constexpr uint16_t mScreenHeight{960};
    static constexpr uint16_t mUnit{64};
    static constexpr uint8_t mScale{1};
    static constexpr uint16_t mHeroMaxFrame{2};
    static constexpr uint8_t mRightMost{uint8_t(mScreenWidth/mUnit)};
    static constexpr uint8_t mDownMost{uint8_t(mScreenHeight/mUnit)};

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
    uint16_t X{0}, Y{0}, width{DEFAULT::mUnit}, height{DEFAULT::mUnit};

    XYWH(uint16_t x, uint16_t y, uint16_t width = DEFAULT::mUnit, uint16_t height = DEFAULT::mUnit ):X(x), Y(y), width(width), height(height) {}
    XYWH(const XYWH& other):X(other.X), Y(other.Y), width(other.width), height(other.height){}

    void Set(uint16_t x, uint16_t y, uint16_t width = DEFAULT::mUnit, uint16_t height = DEFAULT::mUnit ) {
        this->X = x;
        this->Y = y;
        this->width = width;
        this->height = height;
    }
    void SetPos(uint16_t x, uint16_t y ) {
        this->X = x;
        this->Y = y;
    }
    void SetRange(uint16_t width = DEFAULT::mUnit, uint16_t height = DEFAULT::mUnit ) {
        this->width = width;
        this->height = height;
    }

};

struct Map {
    uint8_t row{0}, collum{0};

};

enum class Direction {
    Up,
    Down,
    Left,
    Right,

};
#endif //PARAMETERS_H
