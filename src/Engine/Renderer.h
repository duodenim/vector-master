//
// Created by joseph on 12/23/16.
//

#ifndef PONGGL_RENDERER_H
#define PONGGL_RENDERER_H

#include <glew.h>
#include "Components/CameraComponent.h"
#include "Shader.h"

//Wrapper for gl calls to draw objects to the screen
const int POSITION_LAYOUT_LOC = 0;

//Desired OpenGL parameters
#define GL_DESIRED_MAJOR_VERSION 4
#define GL_DESIRED_MINOR_VERSION 3
#define GLEW_DESIRED_VERSION GLEW_VERSION_4_3

class Renderer {
 public:
  Renderer(int width, int height);
  ~Renderer();
  void RegisterObject(GLfloat *vertexData, GLuint size, GLuint *outVBO);
  void DeleteObject(GLuint *VBO);
  void Draw(GLuint vbo, GLuint numVerticies, Shader* shader);
  void BeginFrame();
  void EndFrame();
  void SetMainCamera(CameraComponent* camera);

 private:
  void GLEW_Init();

  CameraComponent* mainCamera;
  GLuint cameraUBO;
  GLuint VAO; //All verticies will be specified using the same layout, so global VAO is OK

};

#endif //PONGGL_RENDERER_H
