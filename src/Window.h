#pragma once
#include <SDL3/SDL.h>

#include <iostream>

class Window {
public:
  Window() {
    SDLWindow = SDL_CreateWindow(
      "Hello Window",
      GetWidth(),
      GetHeight(),
      0);
  }

  void Render() {
    const SDL_PixelFormatDetails* Fmt = SDL_GetPixelFormatDetails(GetSurface()->format);

    SDL_FillSurfaceRect(
      GetSurface(),
      nullptr,
      SDL_MapRGB(Fmt, nullptr, 50, 50, 50));
  }

  void Update() {
    SDL_UpdateWindowSurface(SDLWindow);
  }

  int GetWidth() const {
    return { 800 };
  }

  int GetHeight() const {
    return { 300 };
  }

  SDL_Surface* GetSurface() const {
    return SDL_GetWindowSurface(SDLWindow);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  ~Window() {
    if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
      SDL_DestroyWindow(SDLWindow);
    }
  }

private:
  SDL_Window* SDLWindow{ nullptr };
};