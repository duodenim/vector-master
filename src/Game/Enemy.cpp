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
}

Enemy::~Enemy() {
  delete mesh;
  delete cCircle;
}

void Enemy::Update(float deltaTime) {
  cCircle->position += velocity * deltaTime;
  mesh->position = cCircle->position;
  mesh->Draw();
}

void Enemy::Collision(GameObject * other) {
  Bullet* bullet = dynamic_cast<Bullet*>(other);
  if (bullet != NULL) {
    std::cout << "enemy hit";
    if (bullet->friendly) {
      Destroy();
    }
  }
}

void Enemy::SetPosition(glm::vec3 pos) {
  mesh->position = pos;
  cCircle->position = pos;
}
