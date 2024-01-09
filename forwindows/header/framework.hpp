#include <SDL2/SDL.h>
class framework {
public:
    framework() = default;
    framework(int32_t screenwidth,int32_t screenheight);
    ~framework();
    int32_t getwidth();
    int32_t getheight();
    SDL_Renderer* getRenderer();

private:
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;

};