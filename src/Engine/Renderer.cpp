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

  glLineWidth(2.0f);

}
void Renderer::RegisterObject(GLfloat *vertexData, GLuint size, GLuint *outVBO, GLuint *outVAO) {

	//OpenGL 4.5 initialization
  /*
	glCreateBuffers(1, outVBO);
	glNamedBufferData(*outVBO, size * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

	glCreateVertexArrays(1, outVAO);
	glVertexArrayAttribFormat(*outVAO, POSITION_LAYOUT_LOC, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(*outVAO, POSITION_LAYOUT_LOC, 0);
	glEnableVertexArrayAttrib(*outVAO, POSITION_LAYOUT_LOC);

	glVertexArrayVertexBuffer(*outVAO, 0, *outVBO, 0, 3 * sizeof(GLfloat));*/

  glGenBuffers(1, outVBO);
  glGenVertexArrays(1, outVAO);
  glBindVertexArray(*outVAO);
  glBindBuffer(GL_ARRAY_BUFFER, *outVBO);
  glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);
  glVertexAttribPointer(POSITION_LAYOUT_LOC, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
void Renderer::DeleteObject(GLuint *VBO, GLuint *VAO) {
  glDeleteBuffers(1, VBO);
  glDeleteVertexArrays(1, VAO);
}
void Renderer::GLEW_Init() {
  glewExperimental = GL_TRUE;
  glewInit();
}
void Renderer::Draw(GLuint vao, GLuint numVerticies, Shader* shader) {
  glBindVertexArray(vao);
  glDrawArrays(GL_LINE_LOOP, 0, numVerticies);
  glBindVertexArray(0);
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
