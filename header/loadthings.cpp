#include "loadthings.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rwops.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "pyidaungsu.h"
#include "font_data.h"

loadFont::loadFont(int ptsize,int loadFromWhat) {
    if (loadFromWhat == 1) {
        lFont = TTF_OpenFont(path.c_str(), ptsize);
        if (lFont == NULL) {
            SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "font loading failed\n");
        }
    } else if(loadFromWhat ==2){
        loadFontRaw(ptsize);
    } else if (loadFromWhat == 3) {
        loadMMFontRaw(ptsize);
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

void loadFont::loadMMFontRaw(int ptsize) {
    lFont = TTF_OpenFontRW(SDL_RWFromConstMem(Resources_Pyidaungsu_2_5_3_Regular_ttf, Resources_Pyidaungsu_2_5_3_Regular_ttf_len), SDL_TRUE, ptsize);
    if (lFont == NULL) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "font loading failed pyidaungsu\n");
    }
}

void loadFont::setPath(std::string fontPath) {
    fontPath = this->path;
}  

void loadFont::fontRender(float x, float y,SDL_Renderer* renderer, SDL_FRect *dst) {
    fontTexture.render(x, y,renderer, dst);
}

void loadFont::loadFontWithText(std::string text, SDL_Color textColor, SDL_Renderer *renderer) {
    fontTexture.loadFromRenderedText(text, textColor, renderer, lFont);
}

void loadFont::setTextColor(SDL_Color& color) {
    color = this->color;
}

void loadFont::loadAgain(int ptsize, int loadFromWhat) {
    if (loadFromWhat == 2) {
        loadFontRaw(ptsize);
    } else if (loadFromWhat == 3) {
        loadMMFontRaw(ptsize);
    }
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
