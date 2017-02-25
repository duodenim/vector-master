#include "Enemy.h"
#include "Bullet.h"

GLfloat enemyVerts[] = {
  0.0f, 0.06f, 0.0f,
  0.02f, 0.02f, 0.0f,
  0.06f, 0.0f, 0.0f,
  0.02f, -0.02f, 0.0f,
  0.0f, -0.06f, 0.0f, 
  -0.02f, -0.02f, 0.0f,
  -0.06f, 0.0f, 0.0f,
  -0.02f, 0.02f, 0.0f,
};
Enemy::Enemy() {
  mesh = new MeshComponent(enemyVerts, 24);
  mesh->SetColor(1.0f, 0.0f, 0.0f);
  mesh->position = glm::vec3(0.24f, 0.0f, -4.0f);
  velocity = glm::vec3(0.0f, 0.0f, 0.3f);
  mesh->rotation = 0.0f;
  cCircle = new CollisionCircle2DComponent();
  cCircle->SetOwner(this);
  cCircle->SetRadius(0.12f);
  cCircle->position = mesh->position;
  hitFrames = -1;
}

Enemy::~Enemy() {
  delete mesh;
  delete cCircle;
}

void Enemy::Update(float deltaTime) {
  cCircle->position += velocity * deltaTime;
  mesh->position = cCircle->position;
  mesh->Draw();
  if (mesh->position.z > 0.1f) {
    exit(0);
  }
  if (hitFrames == 0) {
    Destroy();
  }
  else if (hitFrames > 0) {
    hitFrames--;
  }
}

void Enemy::Collision(GameObject * other) {
  Bullet* bullet = dynamic_cast<Bullet*>(other);
  if (bullet != NULL) {
    if (bullet->friendly) {
      if (bullet->cCircle->position.z - cCircle->position.z > 0.0f) {
        hitFrames = 2;
      }
      else {
        hitFrames = 0;
      }
    }
  }
}

void Enemy::SetPosition(glm::vec3 pos) {
  mesh->position = pos;
  cCircle->position = pos;
}

void Enemy::SetSpeed(float speed) {
  velocity = glm::vec3(0.0f, 0.0f, speed);
}
