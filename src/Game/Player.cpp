//
// Created by joseph on 12/30/16.
//

#include "Player.h"
#include "../Engine/EngineCore.h"
#include "Bullet.h"
#include <cmath>

GLfloat playerVerticies[] = {
    -0.03f, 0.05f, 0.0f,
    0.0f, 0.1f, 0.0f,
    0.05f, 0.05f, 0.0f,
    0.0f, 0.05f, 0.0f,
    0.0f, -0.05f, 0.0f,
    0.05f, -0.05f, 0.0f,
    0.0f, -0.1f, 0.0f,
    -0.03f, -0.05f, 0.0f,
};

GLfloat playerVerts[] = {
  -0.05f, 0.0f, 0.0f,
  -0.03f, -0.05f, 0.0f,
  0.05f, -0.05f, 0.0f,
  0.0f, 0.0f, 0.0f,
  0.05f, 0.05f, 0.0f,
  -0.03f, 0.05f, 0.0f
};
Player::Player() {
  mesh = new MeshComponent(playerVerts, 18);
	mesh->SetColor(0.2f, 0.9f, 0.2f);
  iComponent = new InputComponent();
  cBox = new CollisionBox2DComponent();
  cBox->SetSize(0.08f, 0.2f);
  bulletHitBox = new CollisionCircle2DComponent();
  bulletHitBox->SetRadius(0.05f);
  lastFireState = false;
  mesh->rotation = 0.0f;
  netX = 0.0f;
  netY = 0.0f;
  fireRate = 0.3f;
  nextFireTime = fireRate;

}
Player::~Player() {
  delete mesh;
  delete iComponent;
  delete cBox;
  delete bulletHitBox;
}
void Player::Update(float deltaTime) {

  World *world = EngineCore::GetEngine()->GetWorld();

  nextFireTime -= deltaTime;

  int upKey = GLFW_KEY_W;
  int downKey = GLFW_KEY_S;
  int rightKey = GLFW_KEY_D;
  int leftKey = GLFW_KEY_A;

  //Check collision on Y axis
  glm::vec3 lastPosition = cBox->position;
  if (iComponent->GetKeyState(upKey))
    cBox->position.y += 0.001f * deltaTime * 1000;
  if (iComponent->GetKeyState(downKey))
    cBox->position.y -= 0.001f * deltaTime * 1000;
  if(cBox->CheckAllCollisions())
    cBox->position = lastPosition;

  //Check collision on X axis
  lastPosition = cBox->position;
  if (iComponent->GetKeyState(rightKey))
    cBox->position.x += 0.001 * deltaTime * 1000;
  if (iComponent->GetKeyState(leftKey))
    cBox->position.x -= 0.001f * deltaTime * 1000;
  if (cBox->CheckAllCollisions())
    cBox->position = lastPosition;

  //Determine player rotation
  netY = (float)(iComponent->GetKeyState(GLFW_KEY_UP));
  netY -= (float)(iComponent->GetKeyState(GLFW_KEY_DOWN));

  netX = (float)(iComponent->GetKeyState(GLFW_KEY_RIGHT));
  netX -= (float)(iComponent->GetKeyState(GLFW_KEY_LEFT));

  if (netX != 0.0f || netY != 0.0f) {
    if (netX >= 0.0f) {
      mesh->rotation = glm::degrees(atan(netY / netX));
    }
    else {
      mesh->rotation = glm::degrees(atan(netY / netX)) + 180.0f;
    }
  }
  if ((netX != 0.0f || netY != 0.0f) && nextFireTime < 0.0f)
  {
    nextFireTime = fireRate;
    lastFireState = true;
    //Spawn bullet
    Bullet* bullet = world->SpawnObject<Bullet>();
    bullet->SetPosition(cBox->position);
    bullet->SetRotation(mesh->rotation);
  }

  mesh->position = cBox->position;
  bulletHitBox->position = cBox->position;

  mesh->Draw();
}
void Player::AddCollisionWatcher(CollisionBox2DComponent *box) {
  cBox->AddCollisionWatcher(box);
}
void Player::AddBulletCollisionWatcher(CollisionCircle2DComponent * box) {
  bulletHitBox->AddCollisionWatcher(box);
}
void Player::SetPosition(glm::vec3 newPosition) {
  mesh->position = newPosition;
  cBox->position = newPosition;
  bulletHitBox->position = newPosition;
}
