#ifndef ENEMY_H
#define ENEMY_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
#include "../Engine/Components/CollisionCircle2DComponent.h"

class Enemy : public GameObject {
public:
  Enemy();
  ~Enemy();
  void Update(float deltaTime);
  void Collision(GameObject* other);
  void SetPosition(glm::vec3 pos);
private:
  MeshComponent* mesh;
  CollisionCircle2DComponent* cCircle;
  glm::vec3 velocity;
};
#endif
