//
// Created by joseph on 12/31/16.
//

#include "../EngineCore.h"
#include "InputComponent.h"
InputComponent::InputComponent() {
  inputManager = EngineCore::GetEngine()->GetInputManager();
}
InputComponent::~InputComponent() {

}
bool InputComponent::GetKeyState(int key) {
  return inputManager->GetKeyState(key);
}
