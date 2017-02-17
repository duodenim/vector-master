//
// Created by joseph on 12/27/16.
//

#ifndef PONGGL_INPUTMANAGER_H
#define PONGGL_INPUTMANAGER_H
#include <GLFW/glfw3.h>

const int NUM_KEYS = 1024;
class InputManager {
 public:
  InputManager(GLFWwindow* window);
  void PollInputs();

  bool GetKeyState(int key);

 private:
  bool keys[NUM_KEYS];
  GLFWwindow* window;

};

#endif //PONGGL_INPUTMANAGER_H
