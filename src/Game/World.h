//
// Created by joseph on 12/31/16.
//

#ifndef PONGGL_WORLD_H
#define PONGGL_WORLD_H

#include "../Engine/ObjectManager.h"

class World {
 public:
  World();
  ~World();

  void CreateWorld();
  void DestroyWorld();

  template <typename T>
  T* SpawnObject(){
    return objectManager->SpawnObject<T>();
  };

 private:
  ObjectManager *objectManager;


};

#endif //PONGGL_WORLD_H
