#include "Particle.h"

GLfloat particleVerts[] = {
  -0.01f, -0.01f, 0.0f,
  -0.01f, 0.01f, 0.0f,
  0.01f, 0.01f, 0.0f,
  0.01f, -0.0f, 0.0f 
};

Particle::Particle() {
  mesh = new MeshComponent(particleVerts, 12);
  mesh->SetColor(0.8f, 0.0f, 0.0f);
  velocity = glm::vec3(0.0f, 1.0f, 0.0f);
  lifeSpan = 1.0f;
  lifeRemaining = lifeSpan;
}

Particle::~Particle() {
  delete mesh;
}

void Particle::Update(float deltaTime) {
  mesh->position += velocity * deltaTime;
  lifeRemaining -= deltaTime;
  if (lifeRemaining < 0.0f) {
    Destroy();
  }
  glm::vec3 color = mesh->GetColor();
  color = glm::vec3(color.x - 0.01f, color.y, color.z);
  mesh->SetColor(color);
  mesh->Draw();
}

void Particle::SetPosition(glm::vec3 pos) {
  mesh->position = pos;
}

void Particle::SetVelocity(glm::vec3 vel) {
  velocity = vel;
}
