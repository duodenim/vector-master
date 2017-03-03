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
  bool countScore;
  void ResetScore();
private:
  std::vector<MeshComponent*> font;
  int score;
  float scoreTimer;
  
};
#endif