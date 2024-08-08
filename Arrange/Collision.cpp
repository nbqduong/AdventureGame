//
// Created by duong on 8/8/24.
//

#include "Collision.h"

std::shared_ptr<Map> Collision::mMapPtr{Map::GetInstance()};
std::shared_ptr<Collision> Collision::mInstance{std::shared_ptr<Collision>(new Collision)};


void Collision::HeroMove(Direction dir, XYWH &cor) {
    XYWH tmp = cor;
    Move(dir, tmp);
    if(mMapPtr->GetObject(GetGamePos(tmp.Y),GetGamePos(tmp.X)) != 0) {
        return;
    }
    cor = tmp;
}
