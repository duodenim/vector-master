//
// Created by joseph on 12/31/16.
//

#include "Wall.h"

GLfloat wallVerticies[] = {
    -1.0f, 0.05f, 0.0f,
    1.0f, 0.05f, 0.0f,
    1.0f, -0.05f, 0.0f,
    1.0f, -0.05f, 0.0f,
    -1.0f, -0.05f, 0.0f,
    -1.0f, 0.05f, 0.0f
};

GLuint wallVertexSize = 18;
Wall::Wall() {
  mesh = new MeshComponent(wallVerticies, 18);
  cBox = new CollisionBox2DComponent();
  cBox->SetSize(2.0f, 0.1f);
  cBox->SetOwner(this);
}
Wall::~Wall() {
  delete mesh;
  delete cBox;
}
void Wall::Update(float deltaTime) {
  mesh->Draw();
}
void Wall::SetPosition(glm::vec3 newPosition) {

  mesh->position = newPosition;
  cBox->position = newPosition;
}
