#include "SDL2/SDL.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
    return 0;
  }
  
  SDL_Window* window = SDL_CreateWindow("Tac_RTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
  }
  
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
  // Fill the surface with white
  SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  SDL_UpdateWindowSurface(window);
  
  // Wait 2 seconds.
  SDL_Delay(2000);
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}
