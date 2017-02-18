//
// Created by joseph on 12/31/16.
//

#ifndef COLLISIONBOX2DCOMPONENT_H
#define COLLISIONBOX2DCOMPONENT_H

#include <glm.hpp>
#include <vector>
#include "../Component.h"
#include "CollisionComponent.h"

class CollisionBox2DComponent : public CollisionComponent {
 public:
  CollisionBox2DComponent();
  ~CollisionBox2DComponent();

  void SetSize(float newWidth, float newHeight);

  bool CheckCollision(CollisionComponent* other);

  glm::vec3 position;
 private:
  float width, height;

};

#endif //PONGGL_COLLISIONBOX2DCOMPONENT_H
