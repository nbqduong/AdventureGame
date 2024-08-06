//Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Windows.h"
#include "Parameters.h"
#include "Engine.h"
#include <string>



int main( int argc, char *argv[] )
{
    Engine::getInstance()->Start();


    return EXIT_SUCCESS;
}



