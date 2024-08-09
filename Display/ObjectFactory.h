//
// Created by duong on 8/8/24.
//

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <Hero.h>
#include <Map.h>
#include <memory>
#include <Object.h>
#include <vector>


class ObjectFactory {
    std::shared_ptr<Map> mMapPtr;
    static std::shared_ptr<ObjectFactory> mInstance;
    std::vector<std::shared_ptr<Object>> mObjects;
    std::shared_ptr<Hero> mHero{std::make_shared<BasicHero>()};
    ObjectFactory();
public:
    static std::shared_ptr<ObjectFactory> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<ObjectFactory>(new ObjectFactory());}
    const std::vector<std::shared_ptr<Object>>& GetObject(){return mObjects;}
    std::shared_ptr<Hero> GetHero(){return mHero;}
    std::shared_ptr<Object> GetObject(XYWH Pos)
        {return mObjects[mMapPtr->GetVectorIndex(GamePosition::GetGamePos(Pos.Y), GamePosition::GetGamePos(Pos.X))];}
};



#endif //OBJECTFACTORY_H
