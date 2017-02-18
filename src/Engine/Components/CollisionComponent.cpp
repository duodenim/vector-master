#include "CollisionComponent.h"
#include "../EngineCore.h"

CollisionComponent::CollisionComponent() {
  owner = NULL;
  EngineCore::GetEngine()->GetObjectManager()->RegisterCollider(this);
}
CollisionComponent::~CollisionComponent() {
  EngineCore::GetEngine()->GetObjectManager()->RemoveCollider(this);
}
bool CollisionComponent::CheckCollision(CollisionComponent* other) {

}

void CollisionComponent::SetOwner(GameObject* newOwner) {
  owner = newOwner;
}
