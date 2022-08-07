#include "SDL2/SDL.h"
#include <iostream>
#include <string>

// This code seems to be written in a C-like style;
// note the error handling.
// I guess that's necessary, since SDL is a C library?

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// The window we'll render to.
SDL_Window* gWindow = nullptr;

// The surface contained by the window.
SDL_Surface* gScreenSurface = nullptr;

// The image we will load and show on screen.
SDL_Surface* gHelloWorld = nullptr;

// Starts SDL and load a window.
bool init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL_Error: " 
              << SDL_GetError() << "\n";
    return false;
  }
  
  gWindow = SDL_CreateWindow("Tac_RTS", 
                                        SDL_WINDOWPOS_UNDEFINED, 
                                        SDL_WINDOWPOS_UNDEFINED, 
                                        SCREEN_WIDTH, 
                                        SCREEN_HEIGHT, 
                                        SDL_WINDOW_SHOWN);
  if (!gWindow) {
    std::cout << "Window could not be created! SDL_Error: " 
              << SDL_GetError() << "\n";
    return false;
  }
  
  gScreenSurface = SDL_GetWindowSurface(gWindow);
  
  return true;
}

bool load_media() {
  std::string image_name = "hello_world.bmp";
  gHelloWorld = SDL_LoadBMP(image_name.c_str());
  if (!gHelloWorld) {
    std::cout << "Unable to load image " << image_name << "! "
              << "SDL Error: " << SDL_GetError() << "\n";
    return false;
  }
  return true;
}

// Free media and shut down SDL.
void close() {
  // Deallocate the surface
  SDL_FreeSurface(gHelloWorld);
  gHelloWorld = nullptr;
  
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  
  SDL_Quit();
}

int main() {
  if (!init()) {
    std::cout << "Failed to initialize!\n";
    return 0;
  }
  
  if (!load_media()) {
    std::cout << "Failed to load media!\n";
    return 0;
  }
  
  // // Fill the surface with white.
  // SDL_FillRect(screenSurface, 
  //              nullptr, 
  //              SDL_MapRGB(screenSurface->format, 
  //                         0xFF, 
  //                         0xFF, 
  //                         0xFF));
  
  SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
  
  // Update the surface. Needs to be done as well.
  SDL_UpdateWindowSurface(gWindow);
  
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      } else if (event.type == SDL_KEYDOWN) {
        quit = true;
      } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        quit = true;
      }
    }
  }  
  return 0;
}
