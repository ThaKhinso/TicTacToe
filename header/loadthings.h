#pragma once 

#include "LTexture.h"


class loadFont {
public:
    loadFont(int ptsize,int loadFromWhat);
    ~loadFont();
    void setPath(std::string fontPath);
    void loadMMFontRaw(int ptsize);
    void loadFontRaw(int ptsize);
    void loadFontWithText(std::string text,SDL_Color textColor,SDL_Renderer* renderer);
    void fontRender(float x,float y,SDL_Renderer* renderer,SDL_FRect* dst);
    void free();
    void loadAgain(int ptsize, int loadFromWhat);

    void setTextColor(SDL_Color &color);

    TTF_Font* getFont();
    LTexture getTexture();
private:
    std::string path;
    std::string name;
    TTF_Font* lFont;
    LTexture fontTexture;
    SDL_Color color;
};

