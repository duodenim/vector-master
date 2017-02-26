#ifndef SCOREDSIPLAY_H
#define SCOREDISPLAY_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
#include <vector>
class ScoreDisplay : public GameObject {
public:
  ScoreDisplay();
  ~ScoreDisplay();
  void Update(float deltaTime);
private:
  std::vector<MeshComponent*> text;
  int score;
  float scoreTimer;
};
#endif