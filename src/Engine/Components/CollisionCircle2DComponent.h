#ifndef COLLISION_CIRCLE_2D_H
#define COLLISION_CIRCLE_2D_H

#include "CollisionComponent.h"
#include <glm.hpp>
#include <vector>

class CollisionCircle2DComponent : public CollisionComponent {
public:
  CollisionCircle2DComponent();
  ~CollisionCircle2DComponent();

  void SetRadius(float newRadius);

  bool CheckCollision(CollisionComponent* other);

  glm::vec3 position;

private:
  float radius;

};

#endif
