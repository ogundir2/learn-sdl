#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <string>

class Text {
public:
  Text(const std::string& Content, float FontSize = 25.0f)
      : Font { LoadFont(FontSize) } {

    CreateSurface(Content);
  }

  void Render(SDL_Surface* DestinationSurface) {
    SDL_BlitSurface(
      TextSurface,
      nullptr,
      DestinationSurface,
      nullptr);
  }

  void SetFontSize(float NewSize) {
    TTF_SetFontSize(Font, NewSize);
  }

  ~Text() {
    SDL_DestroySurface(TextSurface);
    if (TTF_WasInit()) {
      TTF_CloseFont(Font);
    }
  }
  Text(const Text&) = delete;
  Text& operator=(const Text&) = delete;

protected:
  Text(float FontSize)
      : Font { LoadFont(FontSize) } {}

  TTF_Font* LoadFont(float FontSize) {
    std::string BASE_PATH { SDL_GetBasePath() };
    std::string FONT_PATH { BASE_PATH + "Assets/Roboto/Roboto-VariableFont_wdth,wght.ttf" };
    TTF_Font* LoadedFont = TTF_OpenFont(FONT_PATH.c_str(), FontSize);
    if (!LoadedFont) {
      std::cout << "Error loading font: "
                << SDL_GetError() << '\n';
    }
    return LoadedFont;
  }

  void CreateSurface(const std::string& Content) {
    SDL_Surface* newSurface {
      TTF_RenderText_LCD(
        Font,
        Content.c_str(),
        0,
        { 255, 255, 255, 255 },
        { 0, 0, 90, 255 })
    };

    if (newSurface) {
      SDL_DestroySurface(TextSurface);
      TextSurface = newSurface;
    } else {
      std::cout << "Error creating TextSurface: "
                << SDL_GetError() << '\n';
    }
  }

  TTF_Font* Font { nullptr };
  SDL_Surface* TextSurface { nullptr };
  SDL_Rect DestinationRectangle { 0, 0, 0, 0 };
};