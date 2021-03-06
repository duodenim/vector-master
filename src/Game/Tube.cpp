#include "Tube.h"

GLfloat verts[] = {
  -0.20f, -0.48f, -4.0f,
  0.20f, -0.48f, -4.0f,
  0.20f, -0.48f, 0.0f,
  -0.20f, -0.48f, 0.0f,
  -0.20f, -0.48f, -4.0f,
  -0.48f, -0.20f, -4.0f,
  -0.48f, -0.20f, 0.0f,
  -0.20f, -0.48f, 0.0f,
  -0.48f, -0.20f, 0.0f,
  -0.48f, 0.20f, 0.0f,
  -0.48f, 0.20f, -4.0f,
  -0.48f, -0.20f, -4.0f,
  -0.48f, 0.20f, -4.0f,
  -0.20f, 0.48f, -4.0f,
  -0.20f, 0.48f,  0.0f,
  -0.48f, 0.20f, 0.0f,
  -0.20f, 0.48f, 0.0f,
  0.20f,  0.48f, 0.0f,
  0.20f, 0.48f, -4.0f,
  -0.20f, 0.48f, -4.0f,
  0.20f, 0.48f, -4.0f,
  0.48f, 0.20f, -4.0f,
  0.48f, 0.20f, 0.0f,
  0.20f, 0.48f, 0.0f,
  0.48f, 0.20f, 0.0f,
  0.48f, -0.20f, 0.0f, 
  0.48f, -0.20f, -4.0f,
  0.48f, 0.20f, -4.0f,
  0.48f, -0.20f, -4.0f,
  0.20f, -0.48f, -4.0f,
  0.20f, -0.48f, 0.0f,
  0.48f, -0.20f, 0.0f,
  0.20f, -0.48f, 0.0f,
  -0.20f, -0.48f, 0.0f
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
