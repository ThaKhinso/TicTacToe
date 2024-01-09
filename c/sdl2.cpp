#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int WALKING_ANIMATION_FRAMES = 2;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* stickManTextures[WALKING_ANIMATION_FRAMES] = {nullptr};

bool initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    gWindow = SDL_CreateWindow("Stick Man Walking Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!gRenderer) {
        return false;
    }

    return true;
}

bool loadMedia() {
    // Load stick man images
    for (int i = 1; i <= WALKING_ANIMATION_FRAMES; ++i) {
        std::string imagePath = "art/enemyFlyingAlt_" + std::to_string(i) + ".png";
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (!surface) {
            return false;
        }

        stickManTextures[i] = SDL_CreateTextureFromSurface(gRenderer, surface);
        SDL_FreeSurface(surface);

        if (!stickManTextures[i]) {
            return false;
        }
    }

    return true;
}

void close() {
    for (int i = 0; i < WALKING_ANIMATION_FRAMES; ++i) {
        SDL_DestroyTexture(stickManTextures[i]);
    }

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

int main() {
    if (!initialize()) {
        return 1;
    }

    if (!loadMedia()) {
        return 2;
    }

    bool quit = false;
    SDL_Event e;

    int frame = 0; // Current animation frame

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the renderer
        SDL_RenderClear(gRenderer);

        // Render the stick man at the current frame
        SDL_Rect destRect = {100, 100, 100, 100}; // Adjust position and size as needed
        SDL_RenderCopy(gRenderer, stickManTextures[frame], NULL, &destRect);

        // Update the screen
        SDL_RenderPresent(gRenderer);

        // Move to the next frame (toggle between frames)
        frame = (frame + 1) % WALKING_ANIMATION_FRAMES;

        // Add a small delay to control the animation speed
        SDL_Delay(100); // Adjust as needed
    }

    close();
    return 0;
}
