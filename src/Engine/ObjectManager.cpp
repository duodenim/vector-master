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
  for (int i = 0; i < objects.size(); i++) {
    objects[i]->Update(deltaTime);
  }
  ClearDestroyQueue();
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
  objects.erase(it);
  objects.shrink_to_fit();
  delete object;
}
