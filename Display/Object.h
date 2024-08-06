//
// Created by duong on 8/6/24.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <cstdint>
#include <string>
#include "Parameters.h"
class Object {
protected:
    XYWH mView;
    std::string mID;
public:
    Object(const char* link, const std::string &m_id, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
        :mView(x,y, width, height),
        mID(m_id) {

    }

    Object() = default;

    virtual void Load()=0;
    virtual void Move(uint32_t x, uint32_t y)=0;
    virtual void Resize(uint32_t width, uint32_t height)=0;
    virtual void Destroy()=0;
    ~Object()=default;
};



#endif //OBJECT_H
