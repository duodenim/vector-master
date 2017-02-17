

#ifndef PONGGL_SHADER_H
#define PONGGL_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glew.h>
#include <glm.hpp>

//Shader Uniform Setup
const int NUM_UNIFORMS = 2;
const GLchar MODEL_UNIFORM_NAME[] = "model";
const GLchar VIEW_UNIFORM_NAME[] = "view";
const GLchar PROJECTION_UNIFORM_NAME[] = "projection";
const GLchar COLOR_UNIFORM_NAME[] = "color";

class Shader
{
 public:

  GLuint Program;

  Shader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);
  ~Shader();

  void Use();

  GLint GetUniformByName(const GLchar* name);

  void SetShaderUniformByIndex(const GLuint index, glm::mat4 newValue);
  void SetShaderUniformByIndex(const GLuint index, glm::vec3 newValue);

  GLuint modelUniform;
  GLuint colorUniform;
  GLuint viewUniform;
  GLuint projectionUniform;
};
#endif //PONGGL_SHADER_H
