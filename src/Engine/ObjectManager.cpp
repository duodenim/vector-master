//
// Created by joseph on 12/27/16.
//

#include "ObjectManager.h"
#include "EngineCore.h"
#include <algorithm>
ObjectManager::ObjectManager() {
 
}
void ObjectManager::DestroyObject(GameObject* object) {
  auto it = std::find(objects.begin(), objects.end(), object);
  int i = it - objects.begin();
  objects.erase(it);
  objects.shrink_to_fit();
  
}
void ObjectManager::DestroyAllObjects() {
  GameObject *temp;
  while(!objects.empty()) {
    temp = objects.back();
    delete temp;
  }
}

void ObjectManager::Update() {
  for (int i = 0; i < objects.size(); i++) {
    objects[i]->Update();
  }
}

