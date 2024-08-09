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
    XYWH mCollisionPosition{0,0};
    Collision(){};
public:
    static auto GetInstance(){return (mInstance==nullptr)? std::shared_ptr<Collision>(new Collision): mInstance;}
    static bool Check(Direction dir, XYWH cor);
    XYWH GetLastCollision(){return mCollisionPosition;}

};



#endif //COLLISION_H
