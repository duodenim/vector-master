//
// Created by joseph on 12/30/16.
//

#ifndef PONGGL_PLAYER_H
#define PONGGL_PLAYER_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
#include "../Engine/Components/InputComponent.h"
#include "../Engine/Components/CollisionBox2DComponent.h"
#include "../Engine/Components/CollisionCircle2DComponent.h"


class Player : public GameObject {
 public:
  Player();
  ~Player();
  void Update(float deltaTime);
  void Collision(GameObject* other);

  void SetPosition(glm::vec3 newPosition);

  CollisionBox2DComponent *cBox;
  CollisionCircle2DComponent *bulletHitBox;
 private:
  MeshComponent *mesh;
  InputComponent *iComponent;


  bool lastFireState;

  //Directional inputs
  int netX;
  int netY;

  float fireRate;
  float nextFireTime;
};

#endif //PONGGL_PLAYER_H
