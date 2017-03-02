#include "Particle.h"

GLfloat particleVerts[] = {
  -0.01f, -0.01f, 0.0f,
  -0.01f, 0.01f, 0.0f,
  0.01f, 0.01f, 0.0f,
  0.01f, -0.0f, 0.0f 
};

Particle::Particle() {
  size = 50;
  mesh = new MeshComponent(particleVerts, 12);
  mesh->SetColor(0.8f, 0.0f, 0.0f);
  positions = new glm::vec3[size];
  velocities = new glm::vec3[size];
  float angle;
  for (int i = 0; i < size; i++) {
    angle = (rand() % 1000) / 150.0f;
    velocities[i] = glm::vec3(cos(angle) / (rand() % 5), 
                              sin(angle) / (rand() % 5), 0.0f);
  }
  lifeSpan = 1.0f;
  lifeRemaining = lifeSpan;
}

Particle::~Particle() {
  delete mesh;
  delete positions;
  delete velocities;
}

void Particle::Update(float deltaTime) {
  lifeRemaining -= deltaTime;
  if (lifeRemaining < 0.0f) {
    Destroy();
  }
  glm::vec3 color = mesh->GetColor();
  color = glm::vec3(color.x - 0.01f, color.y - 0.01f, color.z - 0.01f);
  mesh->SetColor(color);
  for(int i = 0; i < size; i++){
  positions[i] += velocities[i] * deltaTime;
  mesh->position = positions[i];
  mesh->Draw();
  }
}

void Particle::SetPosition(glm::vec3 pos) {
  for (int i = 0; i < size; i++) {
    positions[i] = pos;
  }
}

void Particle::SetVelocity(glm::vec3 vel) {
  velocity = vel;
}

void Particle::SetColor(glm::vec3 col) {
  mesh->SetColor(col);
}

void Particle::SetLifeSpan(float newLifeSpan) {
  lifeRemaining = newLifeSpan;
}
