//
// Created by joseph on 12/27/16.
//

#include "InputManager.h"

InputManager::InputManager(GLFWwindow* window) {
	
  this->window = window;
	//Reset key states
	for (int i = 0; i < NUM_KEYS; i++) {
		keys[i] = false;
	}

}
void InputManager::PollInputs() {
  glfwPollEvents();
}
bool InputManager::GetKeyState(int key) {
  return glfwGetKey(window, key);
}
