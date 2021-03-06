
#pragma once
#include <SDL2/SDL.h>

#include <vector>

#include "../draw.h"
#include "../graph.h"
#include "../settings.h"
#include "sorgente.h"
#include "vector.h"
#include <vector>

class CaricaLineaDiForza {
public:
  CaricaLineaDiForza(float xpos, float ypos);
  void computeVectors(std::vector<Sorgente> &Sorgenti);
  void render(SDL_Renderer *renderer);
  void addForce(vector2 vettore);
  void emptyVectors();
  void changePosizioneIniziale();

private:
  vector2 posizioneIniziale;
  int currentStep = 0;
  vector2 campoelettrico;
  vector2 position;
  Graph ramo;
  std::vector<vector2>::iterator it;
  std::vector<vector2> vettori;
};

void spawnLinee(std::vector<CaricaLineaDiForza> &linee, std::vector<Sorgente>::iterator &it);
