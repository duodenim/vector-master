#include "Enemy.h"
#include "Bullet.h"
#include "Particle.h"
#include  "../Engine/EngineCore.h"
#include <cstdlib>
#include <cmath>

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
  mesh->rotation = (rand() % 1000) / 157.0f;
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
  mesh->rotation += 5.0f;
  mesh->Draw();
  if (mesh->position.z > 0.2f) {
    EngineCore::GetEngine()->GetWorld()->gameManager->EndGame();
  }
  if (mesh->position.z > 1.0f) {
    Destroy();
  }
  if (hitFrames == 0) {
    for (int i = 0; i < 50; i++) {
      Particle* part = EngineCore::GetEngine()->GetWorld()->SpawnObject<Particle>();
      part->SetPosition(mesh->position);
      float angle = (rand() % 1000) / 150.0f;
      part->SetVelocity(glm::vec3(cos(angle) / (rand() % 5), sin(angle) / (rand() % 5), 0.0f));
    } 
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
