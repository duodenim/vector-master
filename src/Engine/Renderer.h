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
#define GL_DESIRED_MINOR_VERSION 5
#define GL_FALLBACK_MAJOR_VERSION 3
#define GL_FALLBACK_MINOR_VERSION 3
#define GLEW_DESIRED_VERSION GLEW_VERSION_4_5

class Renderer {
 public:
  Renderer(int width, int height);
  void RegisterObject(GLfloat *vertexData, GLuint size, GLuint *outVBO, GLuint *outVAO);
  void DeleteObject(GLuint *VBO, GLuint *VAO);
  void Draw(GLuint vao, GLuint numVerticies, Shader* shader);
  void BeginFrame();
  void EndFrame(); 
  void SetMainCamera(CameraComponent* camera);

 private:
  void GLEW_Init();

  CameraComponent* mainCamera;
  GLuint cameraUBO;

};

#endif //PONGGL_RENDERER_H
