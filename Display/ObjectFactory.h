//
// Created by duong on 8/8/24.
//

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <Map.h>
#include <memory>
#include <Object.h>
#include <vector>


class ObjectFactory {
    std::shared_ptr<Map> mMapPtr;
    static std::shared_ptr<ObjectFactory> mInstance;
    std::vector<std::shared_ptr<Object>> mObjects;
    ObjectFactory();
public:
    static std::shared_ptr<ObjectFactory> GetInstance(){ return mInstance = (mInstance != nullptr)? mInstance : std::shared_ptr<ObjectFactory>(new ObjectFactory());}
    const std::vector<std::shared_ptr<Object>>& GetObject(){return mObjects;}
};



#endif //OBJECTFACTORY_H
