#ifndef TUBE_H
#define TUBE_H

#include "../Engine/GameObject.h"
#include "../Engine/Components/MeshComponent.h"
class Tube : public GameObject {
public:
  Tube();
  ~Tube();
  void Update(float deltaTime);
private:
  MeshComponent* mesh;
};

#endif
