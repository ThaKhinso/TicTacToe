#include "loadthings.h"
#include "font_data.h"

loadFont::loadFont(std::string path,int ptsize,int loadFromWhat) {
    if (loadFromWhat == 1) {
        lFont = TTF_OpenFont(path.c_str(), ptsize);
        if (lFont == NULL) {
            SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "font loading failed\n");
        }
    } else if(loadFromWhat ==2){
        loadFontRaw(ptsize);
    }
    
}

loadFont::~loadFont() {
    this->free();
}

void loadFont::loadFontRaw(int ptsize) {
    lFont = TTF_OpenFontRW(SDL_RWFromConstMem(lazy_ttf, lazy_ttf_len),SDL_TRUE, ptsize);
    if (lFont == NULL) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "font loading raw failed\n");
    }
}

void loadFont::fontRender(int x, int y,SDL_Renderer* renderer, SDL_Rect *dst) {
    fontTexture.render(x, y,renderer, dst);
}

void loadFont::loadFontWithText(std::string text, SDL_Color textColor, SDL_Renderer *renderer) {
    fontTexture.loadFromRenderedText(text, textColor, renderer, lFont);
}

void loadFont::setTextColor(SDL_Color& color) {
    color = this->color;
}

void loadFont::loadAgain(int ptsize) {
    loadFontRaw(ptsize);
}

void loadFont::free() {
    if (lFont!= NULL) {
        TTF_CloseFont(lFont);
        lFont = NULL;
    }
}

TTF_Font* loadFont::getFont() {
    return lFont;
}

LTexture loadFont::getTexture() {
    return fontTexture;
}
