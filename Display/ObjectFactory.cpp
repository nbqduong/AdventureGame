//
// Created by duong on 8/8/24.
//

#include "ObjectFactory.h"

#include <Deco.h>
#include <iostream>
std::shared_ptr<ObjectFactory> ObjectFactory::mInstance = nullptr;

ObjectFactory::ObjectFactory() {
    mMapPtr = Map::GetInstance();

    for (int i = 0; i < mMapPtr->GetHeight(); ++i) {
        for (int j = 0; j < mMapPtr->GetWidth(); ++j) {
            if(mMapPtr->GetObject(i,j)==1) {
                mObjects.push_back(std::make_shared<BoxDeco>(i,j));
            }
        }
    }
}
