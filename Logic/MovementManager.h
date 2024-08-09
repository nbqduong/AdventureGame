//
// Created by duong on 8/9/24.
//

#ifndef MOVEMENTMANAGER_H
#define MOVEMENTMANAGER_H
#include <Collision.h>
#include <Hero.h>
#include <KeyBoard.h>
#include <memory>

#include "ObjectFactory.h"


class MovementManager {
    static std::shared_ptr<MovementManager> mInstance;
    std::shared_ptr<ObjectFactory> mObjects{ObjectFactory::GetInstance()};
    std::shared_ptr<Hero> mHero{mObjects->GetHero()};
    std::shared_ptr<Collision> mCollision{Collision::GetInstance()};

    MovementManager(){}
public:
    static std::shared_ptr<MovementManager> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<MovementManager>(new MovementManager());}
    void Move(UserEvent event );
    void HandleCollision(Direction direction);
};



#endif //MOVEMENTMANAGER_H
