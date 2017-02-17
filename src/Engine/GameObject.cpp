//
// Created by joseph on 12/23/16.
//

#include "GameObject.h"
#include "EngineCore.h"
GameObject::GameObject() {

}
GameObject::~GameObject() {
  EngineCore::GetEngine()->GetObjectManager()->DestroyObject(this);
}

void GameObject::Update() {

}
void GameObject::Collision(GameObject* other) {
  
}
