//
// Created by duong on 8/3/24.
//

#include "Debug.h"
// Base case: single argument
void Debug::BasePrint() {
#ifdef DEBUG_MODE
    std::cout << std::endl;
#endif
}

// Recursive case: handle one argument and then call print() for the rest
template <typename T, typename... Args>
void Debug::BasePrint(T first, Args... args) {
#ifdef DEBUG_MODE
    std::cout << first << " ";
    Debug::BasePrint(args...);  // Recursively call print with the remaining arguments
#endif
}

void Debug::ConsoleMessage(const char* mess) {
    BasePrint("[Debug]: ", mess);

}

void Error::SdlError(const char *mess, const char *sdl_error) {
    std::cout << "[Error] " << mess << " SDL error: "<< sdl_error << std::endl;
}
