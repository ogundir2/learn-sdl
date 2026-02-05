#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <string>

class Image {
public:
  Image(const std::string& File) {

    const std::string BASE_PATH{ SDL_GetBasePath() };
    const std::string IMAGE_PATH{ BASE_PATH + File };
    ImageSurface = SDL_LoadBMP(IMAGE_PATH.c_str());

    if (!ImageSurface) {
      std::cout << "Failed to load image "
                << File << ":\n " << SDL_GetError() << '\n';
    }
  }

  void Render(SDL_Surface* DestinationSurface) {
    if (!ImageSurface)
      return;

    SDL_BlitSurface(
      ImageSurface, nullptr, DestinationSurface, nullptr);
  }

  ~Image() {
    if (ImageSurface) {
      SDL_DestroySurface(ImageSurface);
    }
  }

  Image(const Image&) = delete;
  Image& operator=(const Image&) = delete;

private:
  SDL_Surface* ImageSurface{ nullptr };
};