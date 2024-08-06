//
// Created by duong on 8/3/24.
//

#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include "Parameters.h"


class Debug {
public:
    static void BasePrint();

    template <typename T, typename... Args>
    static void BasePrint(T first, Args... args) ;

    static void Console(const char* mess);

};

class Error {
public:
    static void SdlError(const char* mess, const char* sdl_error);
    static void Fatal(const char* mess);
};



#endif //DEBUG_H
