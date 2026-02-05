#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "Image.h"
#include "Window.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;
  Image Example("Assets/land2.bmp");
  Uint64 total = 0;
  Uint64 count = 0;

  bool IsRunning = true;
  SDL_Event Event;
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }

    GameWindow.Render();
    Uint64 Start{ SDL_GetPerformanceCounter() };
    Example.Render(GameWindow.GetSurface());
    Uint64 Delta{ SDL_GetPerformanceCounter() - Start };
    total += Delta;
    count += 1;
    GameWindow.Update();
  }

  std::cout << "Average time to Render Image: "
            << total / count << '\n';

  SDL_Quit();

  return 0;
}