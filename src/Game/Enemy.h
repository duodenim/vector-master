#ifndef ENEMY_H
#define ENEMY_H

#include "../Engine/GameObject.h"

class Enemy : public GameObject {
public:
  Enemy();
  ~Enemy();
  void Update(float deltaTime);
};
#endif
