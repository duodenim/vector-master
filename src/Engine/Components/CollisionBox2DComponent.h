//
// Created by joseph on 12/31/16.
//

#ifndef COLLISIONBOX2DCOMPONENT_H
#define COLLISIONBOX2DCOMPONENT_H

#include <glm.hpp>
#include <vector>
#include "../Component.h"

class CollisionBox2DComponent : public Component{
 public:
  CollisionBox2DComponent();
  ~CollisionBox2DComponent();

  void SetSize(float newWidth, float newHeight);

  void AddCollisionWatcher(CollisionBox2DComponent* newWatchObject);

  bool CheckCollision(CollisionBox2DComponent* other);

  bool CheckAllCollisions();

  glm::vec3 position;
 private:
  std::vector<CollisionBox2DComponent*> watchObjects;
  float width, height;

};

#endif //PONGGL_COLLISIONBOX2DCOMPONENT_H
