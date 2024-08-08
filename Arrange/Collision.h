//
// Created by duong on 8/8/24.
//

#ifndef COLLISION_H
#define COLLISION_H
#include <GamePosition.h>
#include <Map.h>


class Collision : public GamePosition{
    static std::shared_ptr<Map> mMapPtr;
    static std::shared_ptr<Collision> mInstance;
    Collision(){};
public:
    static auto mGetInstance(){return (mInstance==nullptr)? std::shared_ptr<Collision>(new Collision): mInstance;}
    static void HeroMove(Direction dir, XYWH &cor);


};



#endif //COLLISION_H
