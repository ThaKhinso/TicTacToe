#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>

struct LTexture {
public:
    LTexture();
    ~LTexture();

    bool loadFromFile(std::string path,SDL_Renderer* renderer);

    #ifdef SDL_TTF_MAJOR_VERSION
    bool loadFromRenderedText(std::string textureText,SDL_Color textColor,SDL_Renderer* renderer, TTF_Font* font);
    #endif
    void free();
    void setColor(Uint8 red,Uint8 green,Uint8 blue);
    void setAlpha(Uint8 alpha);
    void setBlendMode(SDL_BlendMode blending);
    void render(float x,float y,SDL_Renderer* renderer,SDL_FRect* clip = NULL,double angle = 0.0,SDL_FPoint* center=NULL,SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE);

    int getWidth();
    int getHeight();
private:
    SDL_Texture* mTexture;
    float mWidth;
    float mHeight;
};
#endif