//
// Created by joseph on 12/27/16.
//

#include "ObjectManager.h"
#include "EngineCore.h"
#include <algorithm>
ObjectManager::ObjectManager() {

}
void ObjectManager::DestroyObject(GameObject* object) {
  destroyQueue.push_back(object);
}
void ObjectManager::DestroyAllObjects() {
  GameObject *temp;
  while(!objects.empty()) {
    temp = objects.back();
    objects.pop_back();
    delete temp;
  }
}

void ObjectManager::Update() {
  float deltaTime = EngineCore::GetEngine()->deltaTime;
  ClearDestroyQueue();
  RunCollision();
  for (int i = 0; i < objects.size(); i++) {
    objects[i]->Update(deltaTime);
  }
  
  
}

void ObjectManager::ClearDestroyQueue() {
  GameObject *temp;
  while(!destroyQueue.empty()) {
    temp = destroyQueue.back();
    destroyQueue.pop_back();
    Remove(temp);
  }
}
void ObjectManager::Remove(GameObject* object) {
  auto it = std::find(objects.begin(), objects.end(), object);
  if (it != objects.end()) {
    objects.erase(it);
    objects.shrink_to_fit();
    delete object;
  }

}

void ObjectManager::RegisterCollider(CollisionComponent* collider) {
  colliders.push_back(collider);
}

void ObjectManager::RunCollision() {
  if (colliders.size() < 2) {
    return;
  }
  for(int i = 0; i < colliders.size() - 1; i++) {
    for(int k = i + 1; k < colliders.size(); k++) {
      if(colliders[i]->CheckCollision(colliders[k])) {
        if(colliders[i]->owner != NULL && colliders[k]->owner != NULL) {
          colliders[i]->owner->Collision(colliders[k]->owner);
          colliders[k]->owner->Collision(colliders[i]->owner);
        }
      }
    }
  }
}

void ObjectManager::RemoveCollider(CollisionComponent *collider) {
  auto it = std::find(colliders.begin(), colliders.end(), collider);
  colliders.erase(it);
  colliders.shrink_to_fit();
}
