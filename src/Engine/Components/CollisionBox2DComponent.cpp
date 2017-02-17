//
// Created by joseph on 12/31/16.
//

#include "CollisionBox2DComponent.h"

CollisionBox2DComponent::CollisionBox2DComponent() {

}
CollisionBox2DComponent::~CollisionBox2DComponent() {

}
void CollisionBox2DComponent::SetSize(float newWidth, float newHeight) {
  width = newWidth;
  height = newHeight;
}
bool CollisionBox2DComponent::CheckCollision(CollisionBox2DComponent *other) {

  bool collision = position.x + (width / 2.0f) > other->position.x - (other->width / 2.0f);
  collision &= other->position.x + (other->width / 2.0f) > position.x - (width / 2.0f);

  collision &= position.y + (height / 2.0f) > other->position.y - (other->height / 2.0f);
  collision &= other->position.y + (other->height / 2.0f) > position.y - (height/ 2.0f);
  if(collision)
    return true;
  else
    return false;
}
void CollisionBox2DComponent::AddCollisionWatcher(CollisionBox2DComponent *newWatchObject) {
  watchObjects.push_back(newWatchObject);
}
bool CollisionBox2DComponent::CheckAllCollisions() {
  size_t watchSize = watchObjects.size();
  for(int i = 0; i < watchSize; ++i) {
    if(CheckCollision(watchObjects[i]))
      return true;
  }
  return false;
}

