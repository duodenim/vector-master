//
// Created by joseph on 12/23/16.
//

#include "Renderer.h"
#include <gtc/type_ptr.hpp>

Renderer::Renderer(int width, int height) {
  GLEW_Init();
  glViewport(0, 0, width, height);
  glEnable(GL_DEPTH_TEST);

  //Setup uniform buffer object
  glGenBuffers(1, &cameraUBO);
  glBindBuffer(GL_UNIFORM_BUFFER, cameraUBO);
  glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
  glBindBufferBase(GL_UNIFORM_BUFFER, 0, cameraUBO);
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  glEnableVertexAttribArray(POSITION_LAYOUT_LOC);
  glVertexAttribFormat(POSITION_LAYOUT_LOC, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(POSITION_LAYOUT_LOC, 0);

  glLineWidth(2.0f);

}
Renderer::~Renderer() {
  glBindVertexArray(0);
  glDeleteVertexArrays(1, &VAO);
}
void Renderer::RegisterObject(GLfloat *vertexData, GLuint size, GLuint *outVBO) {

  glGenBuffers(1, outVBO);
  glBindBuffer(GL_ARRAY_BUFFER, *outVBO);
  glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);
}
void Renderer::DeleteObject(GLuint *VBO) {
  glDeleteBuffers(1, VBO);
}
void Renderer::GLEW_Init() {
  glewExperimental = GL_TRUE;
  glewInit();
}
void Renderer::Draw(GLuint vbo, GLuint numVerticies, Shader* shader) {
  glBindVertexBuffer(0, vbo, 0, 3 * sizeof(GLfloat));
  glDrawArrays(GL_LINE_LOOP, 0, numVerticies);
}
void Renderer::BeginFrame() {
  glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (mainCamera) {
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(mainCamera->view));
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(mainCamera->projection));
  }
}
void Renderer::SetMainCamera(CameraComponent* camera) {
	mainCamera = camera;
}
