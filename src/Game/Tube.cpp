#include "Tube.h"

GLfloat verts[] = {
  -0.10f, -0.24f, -4.0f,
  0.10f, -0.24f, -4.0f,
  0.10f, -0.24f, 0.0f,
  -0.10f, -0.24f, 0.0f,
  -0.10f, -0.24f, -4.0f,
  -0.24f, -0.10f, -4.0f,
  -0.24f, -0.10f, 0.0f,
  -0.10f, -0.24f, 0.0f,
  -0.24f, -0.10f, 0.0f,
  -0.24f, 0.10f, 0.0f,
  -0.24f, 0.10f, -4.0f,
  -0.24f, -0.10f, -4.0f,
  -0.24f, 0.10f, -4.0f,
  -0.10f, 0.24f, -4.0f,
  -0.10f, 0.24f,  0.0f,
  -0.24f, 0.10f, 0.0f,
  -0.10f, 0.24f, 0.0f,
  0.10f,  0.24f, 0.0f,
  0.10f, 0.24f, -4.0f,
  -0.10f, 0.24f, -4.0f,
  0.10f, 0.24f, -4.0f,
  0.24f, 0.10f, -4.0f,
  0.24f, 0.10f, 0.0f,
  0.10f, 0.24f, 0.0f,
  0.24f, 0.10f, 0.0f,
  0.24f, -0.10f, 0.0f, 
  0.24f, -0.10f, -4.0f,
  0.24f, 0.10f, -4.0f,
  0.24f, -0.10f, -4.0f,
  0.10f, -0.24f, -4.0f,
  0.10f, -0.24f, 0.0f,
  0.24f, -0.10f, 0.0f,
  0.10f, -0.24f, 0.0f,
  -0.10f, -0.24f, 0.0f
};

Tube::Tube() {
  mesh = new MeshComponent(verts, 102);
  mesh->SetColor(0.5f, 0.5f, 0.5f);
}

Tube::~Tube(){
  delete mesh;
}

void Tube::Update(float deltaTime) {
  mesh->Draw();
}
