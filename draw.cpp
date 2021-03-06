#include "draw.h"
#include "settings.h"
#include <SDL2/SDL.h>
#define COLORE(color) \
  color[0] * 0xFF, color[1] * 0xFF, color[2] * 0xFF, color[3] * 0xFF
void DrawCircle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius) {
  const int32_t diameter = (radius * 2);

  int32_t x = (radius - 1);
  int32_t y = 0;
  int32_t tx = 1;
  int32_t ty = 1;
  int32_t error = (tx - diameter);

  while (x >= y) {
    //  Each of the following renders an octant of the circle
    SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
    SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
    SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

    if (error <= 0) {
      ++y;
      error += ty;
      ty += 2;
    }

    if (error > 0) {
      --x;
      tx += 2;
      error += (tx - diameter);
    }
  }
}

void RenderGriglia(SDL_Renderer *renderer, unsigned int SCREEN_WIDTH, unsigned int SCREEN_HEIGHT, int scala) {
  for (unsigned int i = 0; i < SCREEN_WIDTH; i = i + scala) {
    if (scala > 20) {
      SDL_SetRenderDrawColor(renderer, COLORE(coloreGrigliaSecondario));

      int precisione = (scala / 10);
      for (unsigned int z = i + precisione; z < i + scala; z += precisione) {
        SDL_RenderDrawLine(renderer, z, 0, z, SCREEN_HEIGHT);
      }
    }

    SDL_SetRenderDrawColor(renderer, COLORE(coloreGrigliaPrimario));
    SDL_RenderDrawLine(renderer, i, 0, i, SCREEN_HEIGHT);
  }
  for (unsigned int j = 0; j < SCREEN_HEIGHT; j = j + scala) {
    if (scala > 20) {
      SDL_SetRenderDrawColor(renderer, COLORE(coloreGrigliaSecondario));

      int precisione = (scala / 10);
      for (unsigned int k = j + precisione; k < j + scala; k += precisione) {
        SDL_RenderDrawLine(renderer, 0, k, SCREEN_WIDTH, k);
      }
    }

    SDL_SetRenderDrawColor(renderer, COLORE(coloreGrigliaPrimario));
    SDL_RenderDrawLine(renderer, 0, j, SCREEN_WIDTH, j);
  };
}
