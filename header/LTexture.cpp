#include "LTexture.h"
LTexture::LTexture() {
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}
LTexture::~LTexture() {
    free();
}

bool LTexture::loadFromFile(std::string path,SDL_Renderer* renderer) {
    free();
    bool success = true;
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("surface loading failed\n");
        success = false;
    } else {
        SDL_SetSurfaceColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(renderer , loadedSurface);
        if (newTexture == NULL) {
            printf("texture creating failed\n");
            success = false;
        } else {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_DestroySurface(loadedSurface);
    }
    mTexture = newTexture;
    // char i = 'a';
    return mTexture != NULL;
    // return i;
}

#ifdef SDL_TTF_MAJOR_VERSION
bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer *renderer, TTF_Font *font) {
    free();
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, textureText.c_str(), textColor);
    if (textSurface == NULL) {
        printf("text surface creating failed %s\n",SDL_GetError());
    } else {
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == NULL) {
            printf("texture creating failed%s\n",SDL_GetError());
        } else {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_DestroySurface(textSurface);
    }
    return mTexture != NULL;
}
#endif

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::free() {
    if (mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(float x,float y,SDL_Renderer* renderer,SDL_FRect* clip,double angle,SDL_FPoint* center,SDL_RendererFlip flip) {

    SDL_FRect renderQuad {x,y,mWidth,mHeight};
    if (clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderTextureRotated(renderer, mTexture, clip, &renderQuad,angle,center,flip);
}

int LTexture::getHeight() {
    return mHeight;
}
int LTexture::getWidth() {
    return mWidth;
}