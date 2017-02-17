#include "Tube.h"

GLfloat verts[] = {
  -0.40f, -0.40f, -4.0f,
  -0.40f, -0.40f, 0.0f,
  0.40f, -0.40f, 0.0f,
  0.40f, -0.40f, -4.0f,
  -0.40f, -0.40f, -4.0f,
  -0.40f, 0.40f, -4.0f,
  -0.40f, 0.40f, 0.0f,
  -0.40f, -0.40f, 0.0f,
  0.40f, -0.40f, 0.0f,
  0.40f, 0.40f, 0.0f,
  0.40f, 0.40f, -4.0f,
  0.40f, -0.40f, -4.0f,
  0.40f, 0.40f, -4.0f,
  0.40f, 0.40f, 0.0f,
  -0.40f, 0.40f, 0.0f,
  -0.40f, 0.40f, -4.0f,
  0.40f, 0.40f, -4.0f,
  -0.40f, 0.40f, -4.0f
};

Tube::Tube() {
  mesh = new MeshComponent(verts, 54);
  mesh->SetColor(0.5f, 0.5f, 0.5f);
}

Tube::~Tube(){
  delete mesh;
}

void Tube::Update() {
  mesh->Draw();
}
