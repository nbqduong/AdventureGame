//
// Created by duong on 8/6/24.
//

#include "GamePosition.h"

uint16_t GamePosition::mScale{CURRENT::mScale};
uint16_t GamePosition::mViewFactor{uint16_t(mScale*CURRENT::mViewUnit)};
uint16_t GamePosition::mSrcFactor{uint16_t(mScale*CURRENT::mSourceUnit)};

XYWH GamePosition::Get(uint16_t colum, uint16_t row,  uint16_t width, uint16_t height) {
        return XYWH({uint16_t(colum*mViewFactor),uint16_t(row*mViewFactor),uint16_t(width*mViewFactor),uint16_t(height*mViewFactor)});
}

XYWH GamePosition::GetSrc(uint16_t colum, uint16_t row, uint16_t width, uint16_t height) {
        return XYWH({uint16_t(colum*mSrcFactor),uint16_t(row*mSrcFactor),uint16_t(width*mSrcFactor),uint16_t(height*mSrcFactor)});
}

bool GamePosition::Move(Direction dir, XYWH &cor) {
        switch (dir) {
                case Direction::Up:
                        if(cor.Y >= mViewFactor) {
                                cor.Y -= mViewFactor;
                                return true;
                        }
                break;
                case Direction::Down:
                        if(cor.Y < CURRENT::mScreenHeight - mViewFactor) {
                                cor.Y += mViewFactor;
                                return true;
                        }
                        break;
                case Direction::Left:
                        if(cor.X >= mViewFactor) {
                                cor.X -= mViewFactor;
                                return true;
                        }
                break;
                default:
                        if(cor.X < CURRENT::mScreenWidth - mViewFactor) {
                                cor.
                                X += mViewFactor;
                                return true;
                        }
                break;
        }
        return false;
}

uint16_t GamePosition::GetGamePos(uint16_t Pos) {
        return Pos/mViewFactor;
}


