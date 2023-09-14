#pragma once 

#include "LTexture.h"


class loadFont {
public:
    loadFont(std::string path,int ptsize,int loadFromWhat);
    ~loadFont();
    void loadFontRaw(std::string path,int ptsize);
    void loadFontWithText(std::string text,SDL_Color textColor,SDL_Renderer* renderer);
    void fontRender(float x,float y,SDL_Renderer* renderer,SDL_FRect* dst);
    void free();
    void loadAgain(std::string path,int ptsize);

    void setTextColor(SDL_Color &color);

    TTF_Font* getFont();
    LTexture getTexture();
private:
    std::string name;
    TTF_Font* lFont;
    LTexture fontTexture;
    SDL_Color color;
};

