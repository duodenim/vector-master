#ifndef PARTICLE_H
#define PARTICLE_H
#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"

class Particle : public GameObject {
public:
  Particle();
  ~Particle();
  void Update(float deltaTime);
  glm::vec3 velocity;
  void SetPosition(glm::vec3 pos);
  void SetVelocity(glm::vec3 vel);
  void SetColor(glm::vec3 col);
  void SetLifeSpan(float newLifeSpan);
private:
  MeshComponent* mesh;
  int size;
  glm::vec3* positions;
  glm::vec3* velocities;
  float lifeSpan;
  float lifeRemaining;
};
#endif