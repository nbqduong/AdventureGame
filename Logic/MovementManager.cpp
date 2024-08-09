//
// Created by duong on 8/9/24.
//

#include "MovementManager.h"

std::shared_ptr<MovementManager> MovementManager::mInstance = nullptr;

void MovementManager::Move(UserEvent event) {
    switch (event) {
        case UserEvent::emUp:
            if(mCollision->Check(Direction::Up,mHero->GetPos()) == false) {
                mHero->Move(Direction::Up);
            }else {
                HandleCollision(Direction::Up);
            }

        break;
        case UserEvent::emDown:
            if(mCollision->Check(Direction::Down,mHero->GetPos()) == false)
                mHero->Move(Direction::Down);

        break;
        case UserEvent::emLeft:
            if(mCollision->Check(Direction::Left,mHero->GetPos()) == false)
                mHero->Move(Direction::Left);

        break;
        case UserEvent::emRight:
            if(mCollision->Check(Direction::Right,mHero->GetPos()) == false)
                mHero->Move(Direction::Right);

        break;
        default:
            break;
    }
}

void MovementManager::HandleCollision(Direction direction) {
    XYWH col = mCollision->GetLastCollision();
    auto object = mObjects->GetObject(col);
    object->Touched();
}
