//
// Created by joseph on 12/31/16.
//

#ifndef PONGGL_WALL_H
#define PONGGL_WALL_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
#include "../Engine/Components/CollisionBox2DComponent.h"

class Wall : public GameObject{
 public:
  Wall();
  ~Wall();
  void Update();
  void SetPosition(glm::vec3 newPosition);

  CollisionBox2DComponent *cBox;
 private:
  MeshComponent *mesh;


};

#endif //PONGGL_WALL_H
