#include <SDL3/SDL_render.h>
#include <cstddef>
#include <iostream>
#include "header/Button.hpp"
#include "header/framework3.hpp"
#include <unistd.h>
#define FPS_INTERVAL 1.0
// LTexture texture1;
// LTexture texture2;
int main() {
  framework3 frame("test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600);

  bool running = true;
  Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
  Uint32 fps_current; //the current FPS.
  Uint32 fps_frames = 0; 
  // texture1.loadFromFile("art/enemyFlyingAlt_1.png", frame.getRenderer());
  // texture2.loadFromFile("art/enemyFlyingAlt_2.png", frame.getRenderer());  
  // LTexture textarr[] = { texture1, texture2};
  SDL_Event e;
  int frames = 0;
  while (running) {
    while(SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }
    
    SDL_SetRenderDrawColor(frame.getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderClear(frame.getRenderer());

    // for (int i = 0; i < 2; i++) {
    //   textarr[i].loadFromFile("art/enemyFlyingAlt_1.png", frame.getRenderer());
    //   textarr[i].render(50.f, 50.f, frame.getRenderer());
      
    // }
    // textarr[frames].render(50.f , 50.f, frame.getRenderer());
    // frames++;
    // if (frames >= 2) {
    //   frames = 0;
    // }
    color color = { 255,0,0,255 };
    SDL_FRect rect = { 100,100,30,30};
    Button but(100,100,30,30);
    but.draw(frame.getRenderer(), color);
    // SDL_SetRenderDrawColor(frame.getRenderer(), 255, 0, 0, 255);
    // SDL_RenderFillRect(frame.getRenderer(), &rect);
    
    
    SDL_RenderPresent(frame.getRenderer());
    fps_frames++;
    if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
    {
      fps_lasttime = SDL_GetTicks();
      fps_current = fps_frames;
      SDL_Log("fps: %i\n",fps_current);
      fps_frames = 60;
    }
  }
  return 0;
}
