#ifndef COLLISION_CIRCLE_2D_H
#define COLLISION_CIRCLE_2D_H

#include "../Component.h"
#include <glm.hpp>
#include <vector>

class CollisionCircle2DComponent : public Component {
public:
  CollisionCircle2DComponent();
  ~CollisionCircle2DComponent();

  void SetRadius(float newRadius);

  void AddCollisionWatcher(CollisionCircle2DComponent* newWatchObject);

  bool CheckCollision(CollisionCircle2DComponent* other);

  bool CheckAllCollisions();

  glm::vec3 position;

private:
  float radius;

  std::vector<CollisionCircle2DComponent*> watchObjects;

};

#endif