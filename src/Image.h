#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>

class Image {
public:
  Image(const std::string& File);

  void Render(SDL_Surface* DestinationSurface);

  ~Image();
  Image(const Image&);
  Image& operator=(const Image&);

private:
  SDL_Surface* ImageSurface{ nullptr };
  SDL_Rect DestinationRectangle{ 200, 50, 200, 200 };
};