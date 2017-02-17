//
// Created by joseph on 12/23/16.
//

#include "GameObject.h"
#include "EngineCore.h"
GameObject::GameObject() {

}
GameObject::~GameObject() {

}

void GameObject::Update(float deltaTime) {

}
void GameObject::Collision(GameObject* other) {

}

void GameObject::Destroy() {
  EngineCore::GetEngine()->GetObjectManager()->DestroyObject(this);
}
