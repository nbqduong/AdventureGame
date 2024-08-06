//
// Created by duong on 8/6/24.
//

#include "GamePosition.h"

uint16_t GamePosition::mScale{DEFAULT::mScale};
uint16_t GamePosition::mFactor{uint16_t(mScale*DEFAULT::mUnit)};

XYWH GamePosition::FullTransfer(uint16_t colum, uint16_t row,  uint16_t width, uint16_t height) {
        return XYWH({uint16_t(colum*mFactor),uint16_t(row*mFactor),uint16_t(width*mFactor),uint16_t(height*mFactor)});
}

XYWH GamePosition::Move(Direction dir, XYWH &cor) {
        switch (dir) {
                case Direction::Up:
                        if(cor.Y >= mFactor) {
                                cor.Y -= mFactor;
                        }
                        break;
                case Direction::Down:
                        if(cor.Y < DEFAULT::mScreenHeight - mFactor) {
                                cor.Y += mFactor;
                        }
                        break;
                case Direction::Left:
                        if(cor.X >= mFactor) {
                                cor.X -= mFactor;
                        }
                break;
                default:
                        if(cor.X < DEFAULT::mScreenWidth - mFactor) {
                                cor.
                                X += mFactor;
                        }
                break;
        }
}
