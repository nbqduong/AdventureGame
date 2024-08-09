//
// Created by duong on 8/8/24.
//

#include "Collision.h"

std::shared_ptr<Map> Collision::mMapPtr{Map::GetInstance()};
std::shared_ptr<Collision> Collision::mInstance{std::shared_ptr<Collision>(new Collision)};


bool Collision::Check(Direction dir, XYWH cor) {
    Move(dir, cor);
    if(mMapPtr->GetObject(GetGamePos(cor.Y),GetGamePos(cor.X)) != 0) {
        mInstance->mCollisionPosition = cor;
        return true;
    }
    return false;
}
