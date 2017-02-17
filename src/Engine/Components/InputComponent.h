//
// Created by joseph on 12/31/16.
//

#ifndef PONGGL_INPUTCOMPONENT_H
#define PONGGL_INPUTCOMPONENT_H

#include "../InputManager.h"

class InputComponent {
 public:
  InputComponent();
  ~InputComponent();
  bool GetKeyState(int key);
 private:
  InputManager *inputManager;

};

#endif //PONGGL_INPUTCOMPONENT_H
