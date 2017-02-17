#include "CollisionCircle2DComponent.h"
#include <cmath>

CollisionCircle2DComponent::CollisionCircle2DComponent() {
}

CollisionCircle2DComponent::~CollisionCircle2DComponent() {
}

void CollisionCircle2DComponent::SetRadius(float newRadius) {
  radius = newRadius;
}

void CollisionCircle2DComponent::AddCollisionWatcher(CollisionCircle2DComponent * newWatchObject) {
  watchObjects.push_back(newWatchObject);
}

bool CollisionCircle2DComponent::CheckCollision(CollisionCircle2DComponent * other){
  float dx = other->position.x - this->position.x;
  float dy = other->position.y - this->position.y;

  float distance = sqrt(pow(dx, 2) + pow(dy, 2));

  return (distance < (this->radius + other->radius));
}

bool CollisionCircle2DComponent::CheckAllCollisions() {
  size_t watchSize = watchObjects.size();
  for (int i = 0; i < watchSize; ++i) {
    if (CheckCollision(watchObjects[i]))
      return true;
  }
  return false;
}
