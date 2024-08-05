//
// Created by duong on 8/3/24.
//

#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include "../Parameters.h"


class Debug {
    static void BasePrint();

    template <typename T, typename... Args>
    static void BasePrint(T first, Args... args) ;
public:
    static void ConsoleMessage(const char* mess);

};

class Error {
public:
    static void SdlError(const char* mess, const char* sdl_error);
};



#endif //DEBUG_H
