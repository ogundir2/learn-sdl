#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Text.h"
#include "Window.h"
#include "WrappedText.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  if (!TTF_Init()) {
    std::cout << "Error initializing SDL_ttf: "
              << SDL_GetError();
  }

  Window GameWindow;
  WrappedText TextExample {
    "The quick brown fox jumps over the lazy dog",
    36.0f,
    GameWindow.GetWidth()
  };

  bool IsRunning = true;
  SDL_Event Event;
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }

    GameWindow.Render();
    TextExample.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  TTF_Quit();
  SDL_Quit();

  return 0;
}