//
// Created by duong on 8/2/24.
//

#include "Windows.h"
Windows::Windows(int x, int y)
        : width(x),
          heigh(y) {

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        const char* driver = SDL_GetCurrentVideoDriver();
        if (driver) {
            printf("Current video driver: %s\n", driver);
        } else {
            printf("Failed to get current video driver! SDL_Error: %s\n", SDL_GetError());
        }
        //Create window
        window = SDL_CreateWindow( "Diamond Rush", 0, 0, width, heigh, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );




        }
    }


}

Windows::~Windows() {
    //Destroy window
    SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();

}

