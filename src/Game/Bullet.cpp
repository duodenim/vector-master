#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <gtx/rotate_vector.hpp>

GLfloat bulletVerts[] = {
  0.05f, 0.0f, 0.0f,
  0.043f, 0.025f, 0.0f,
  0.035f, 0.035f, 0.0f,
  0.025f, 0.043f, 0.0f,
  0.0f, 0.05f, 0.0f,
  -0.025f, 0.043f, 0.0f,
  -0.035f, 0.035f, 0.0f,
  -0.043f, 0.025f, 0.0f,
  -0.05f, 0.0f, 0.0f,
  -0.043f, -0.025f, 0.0f,
  -0.035f, -0.035f, 0.0f,
  -0.025f, -0.043f, 0.0f,
  0.0f, -0.05f, 0.0f,
  0.025f, -0.043f, 0.0f,
  0.035f, -0.035f, 0.0f,
  0.043f, -0.025f, 0.0f
};

Bullet::Bullet() {
  mesh = new MeshComponent(bulletVerts, 48);
  mesh->SetColor(0.9f, 0.9f, 0.2f);
  mesh->position = glm::vec3(0.0f, 0.0f, 0.0f);
  velocity = glm::vec3(0.0f, 0.0f, -1.0f);
  lifeSpan = 5.0f;
  lifeTimer = lifeSpan;
  cCircle = new CollisionCircle2DComponent();
  cCircle->SetRadius(0.05f);
  cCircle->SetOwner(this);
  cCircle->position = glm::vec3(0.0f, 0.0f, 0.0f);
  hitFrames = -1;
  friendly = true;
}

Bullet::~Bullet() {
  delete mesh;
  delete cCircle;
}

void Bullet::Update(float deltaTime) {
  mesh->position += velocity * deltaTime;
  cCircle->position = mesh->position;
  lifeTimer -= deltaTime;
  mesh->Draw();
  if (lifeTimer < 0.0f) {
    Destroy();
  }
  if (hitFrames == 0) {
    Destroy();
  }
  else if (hitFrames > 0) {
    hitFrames--;
  }
  

}

void Bullet::Collision(GameObject * other) {
  Enemy* enemy = dynamic_cast<Enemy*>(other);
  if (enemy != NULL && friendly) {
    hitFrames = 2;
    return;
  }
  Player* player = dynamic_cast<Player*>(other);
  if (player != NULL && !friendly) {
    hitFrames = 2;
    return;
  }
}

void Bullet::SetPosition(glm::vec3 pos) {
  mesh->position = pos;
  cCircle->position = pos;
}

void Bullet::SetRotation(float rot) {
  mesh->rotation = rot;
  velocity = glm::rotate(velocity, glm::radians(rot), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Bullet::SetFriendly(bool newFriendly) {
  friendly = newFriendly;
  if (!friendly) {
    mesh->SetColor(0.9f, 0.2f, 0.2f);
  }
  else {
    mesh->SetColor(0.9f, 0.9f, 0.2f);
  }
}
