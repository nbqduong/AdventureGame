//Using SDL and standard IO
#include <SDL2/SDL.h>
#include "Display/Windows.h"
#include "Resource/Player.h"
#include "Parameters.h"
#include "Logic/Engine.h"
#include "Logic/Engine.h"
#include <string>



int main( int argc, char *argv[] )
{
    Engine::getInstance()->Start();
    
    return EXIT_SUCCESS;
}



