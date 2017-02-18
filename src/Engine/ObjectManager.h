//
// Created by joseph on 12/27/16.
//

#ifndef PONGGL_OBJECTMANAGER_H
#define PONGGL_OBJECTMANAGER_H

#include <vector>
#include "GameObject.h"
#include "Components/CollisionComponent.h"

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
  void RemoveCollider(CollisionComponent* collider);

  GameObject* GetObjectByIndex(int index) { return objects [index]; }

  void DestroyAllObjects();

  void Update();

  void RegisterCollider(CollisionComponent* collider);
 private:
  std::vector<GameObject*> objects;
  std::vector<GameObject*> destroyQueue;
  std::vector<CollisionComponent*> colliders;
  void ClearDestroyQueue();
  void Remove(GameObject* object);
  void RunCollision();


};

#endif //PONGGL_OBJECTMANAGER_H
