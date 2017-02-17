#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
#include "../Engine/Components/CollisionCircle2DComponent.h"

class Bullet : public GameObject {
public:
  Bullet();
  ~Bullet();

  void Update();

  void SetPosition(glm::vec3 pos);

  void SetRotation(float rot);

  void SetFriendly(bool newFriendly);

  glm::vec3 velocity;
  bool friendly;
  CollisionCircle2DComponent *cCircle;
private:
  MeshComponent* mesh;
  float lifeSpan;
  float lifeTimer;
};
#endif
