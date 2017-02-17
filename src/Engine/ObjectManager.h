//
// Created by joseph on 12/27/16.
//

#ifndef PONGGL_OBJECTMANAGER_H
#define PONGGL_OBJECTMANAGER_H

#include <vector>
#include "GameObject.h"

enum class EventTypes {
  EVENT_UPDATE
};
class ObjectManager {
 public:
  ObjectManager();

  template<typename T>
  T* SpawnObject() {
    T *object = new T();
    objects.push_back(object);
    return object;
  };

  void DestroyObject(GameObject* object);

  GameObject* GetObjectByIndex(int index) { return objects [index]; }

  void DestroyAllObjects();

  void Update();
 private:
  std::vector<GameObject*> objects;
  std::vector<std::function<void(void)>> UpdateFunctions;

};

#endif //PONGGL_OBJECTMANAGER_H
