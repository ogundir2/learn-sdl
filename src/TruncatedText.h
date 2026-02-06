#pragma once
#include "Text.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

class TruncatedText : public Text {
public:
  TruncatedText(
    std::string Content, float FontSize, int MaxWidth)
      : Text { FontSize } {

    size_t MaxCharacters;

    TTF_MeasureString(
      Font, Content.c_str(), 0, MaxWidth, nullptr, &MaxCharacters);

    if (MaxCharacters < Content.size()) {
      Content.resize(MaxCharacters - 3);
      Content.append("...");
    }

    CreateSurface(Content);
  }
};