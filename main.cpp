//Using SDL and standard IO
#include <Map.h>
#include <SDL2/SDL.h>
#include "Engine.h"
#include <string>


int main( int argc, char *argv[] )
{
    Engine::getInstance()->Start();
    // std::cout << static_cast<int>(Map::GetInstance()->Get(29,49)) ;

    return EXIT_SUCCESS;
}



