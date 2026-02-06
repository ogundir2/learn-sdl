#include "Image.h"

Image::Image(const std::string& File) {

  const std::string BASE_PATH{ SDL_GetBasePath() };
  const std::string IMAGE_PATH{ BASE_PATH + File };
  ImageSurface = IMG_Load(IMAGE_PATH.c_str());

  if (!ImageSurface) {
    std::cout << "Failed to load image "
              << File << ":\n " << SDL_GetError() << '\n';
    return;
  }
}

void Image::Render(SDL_Surface* DestinationSurface) {
  if (!ImageSurface)
    return;

  SDL_BlitSurfaceScaled(
    ImageSurface,
    nullptr,
    DestinationSurface,
    &DestinationRectangle,
    SDL_SCALEMODE_LINEAR);
}

Image::Image(const Image& Source)
    : DestinationRectangle(Source.DestinationRectangle) {
  // Copy the SDL_Surface using SDL_ConvertSurface
  if (Source.ImageSurface) {
    ImageSurface = SDL_ConvertSurface(
      Source.ImageSurface,
      Source.ImageSurface->format);
  }
}

Image& Image::operator=(const Image& Source) {
  if (this == &Source) {
    return *this;
  }

  // Free current resources
  if (ImageSurface) {
    SDL_DestroySurface(ImageSurface);
  }

  // Copy the SDL_Surface using SDL_ConvertSurface
  if (Source.ImageSurface) {
    ImageSurface = SDL_ConvertSurface(
      Source.ImageSurface,
      Source.ImageSurface->format);
  } else {
    ImageSurface = nullptr;
  }

  DestinationRectangle = Source.DestinationRectangle;
}

Image::~Image() {
  if (ImageSurface) {
    SDL_DestroySurface(ImageSurface);
  }
}