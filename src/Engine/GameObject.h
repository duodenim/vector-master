//
// Created by joseph on 12/23/16.
//

#ifndef PONGGL_WORLDOBJECT_H
#define PONGGL_WORLDOBJECT_H

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "Renderer.h"
#include <functional>



class GameObject {
 public:
  GameObject();
  virtual ~GameObject();
  virtual void Update(float deltaTime);
  virtual void Collision(GameObject* other);
  void Destroy();
};

#endif //PONGGL_WORLDOBJECT_H
