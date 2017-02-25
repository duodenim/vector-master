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
  cBox->SetOwner(this);
  bulletHitBox = new CollisionCircle2DComponent();
  bulletHitBox->SetRadius(0.05f);
  bulletHitBox->SetOwner(this);
  lastFireState = false;
  mesh->rotation = 0.0f;
  netX = 0;
  netY = 0;
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

  //Determine player position
  netY = (int)(iComponent->GetKeyState(upKey));
  netY -= (int)(iComponent->GetKeyState(downKey));

  netX = (int)(iComponent->GetKeyState(rightKey));
  netX -= (int)(iComponent->GetKeyState(leftKey));

  if (netX != 0 || netY != 0) {
    glm::vec3 newPosition = glm::vec3();
    newPosition.x = (float)(netX) / 2.08f;
    newPosition.y = (float)(netY) / 2.08f;
    if (netX != 0 && netY != 0) {
      //Force position onto the diagonal edge
      newPosition.x = newPosition.x / 1.414f;
      newPosition.y = newPosition.y / 1.414f;
    }

    SetPosition(newPosition);
    if (netX > 0) {
      mesh->rotation = glm::degrees(atan(netY / netX)) + 180.0f;
    }
    else if (netX < 0) {
      mesh->rotation = glm::degrees(atan(netY / netX));
    }
    else {
      mesh->rotation = -90.0f * netY;
    }
  }
  if (iComponent->GetKeyState(GLFW_KEY_SPACE) && !lastFireState) {
    Bullet *bullet = world->SpawnObject<Bullet>();
    bullet->SetPosition(cBox->position);
    lastFireState = true;
  }
  else if (!iComponent->GetKeyState(GLFW_KEY_SPACE)) {
    lastFireState = false;
  }

  mesh->position = cBox->position;
  bulletHitBox->position = cBox->position;

  mesh->Draw();
}
void Player::Collision(GameObject* other) {
}
void Player::SetPosition(glm::vec3 newPosition) {
  mesh->position = newPosition;
  cBox->position = newPosition;
  bulletHitBox->position = newPosition;
}
