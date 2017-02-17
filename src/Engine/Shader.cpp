#include "Shader.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

Shader::Shader(const GLchar *vertexShaderPath, const GLchar *fragmentShaderPath) {

  std::ifstream vertexFile;
  std::ifstream fragmentFile;
  int vertexFileLength;
  int fragmentFileLength;

  vertexFile.open(vertexShaderPath, std::ios::binary);
  if(vertexFile.fail()) {
    std::cout << "ERROR OPENING VERTEX SHADER FILE" << std::endl;
    return;
  }
  fragmentFile.open(fragmentShaderPath, std::ios::binary);
  if(fragmentFile.fail()) {
    std::cout << "ERROR OPENING FRAGMENT SHADER FILE" << std::endl;
    return;
  }
  vertexFile.seekg(0, vertexFile.end);
  vertexFileLength = vertexFile.tellg();
  vertexFile.seekg(0, vertexFile.beg);

  fragmentFile.seekg(0, fragmentFile.end);
  fragmentFileLength = fragmentFile.tellg();
  fragmentFile.seekg(0, fragmentFile.beg);

  GLchar *vertexShaderCode = new GLchar[vertexFileLength + 1];
  GLchar *fragmentShaderCode = new GLchar[fragmentFileLength + 1];

  vertexFile.read(vertexShaderCode, vertexFileLength);
  fragmentFile.read(fragmentShaderCode, fragmentFileLength);

  vertexShaderCode[vertexFileLength] = '\0';
  fragmentShaderCode[fragmentFileLength] = '\0';

  vertexFile.close();
  fragmentFile.close();

  GLuint vertexShader, fragmentShader;
  GLint success;
  GLchar infolog[512];

	//Compile/link shaders
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
    std::cout << "VERTEX SHADER COMPILE ERROR\n" << infolog << std::endl;
  }

  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
    std::cout << "FRAGMENT SHADER COMPILE ERROR\n" << infolog << std::endl;
  }

  Program = glCreateProgram();
  glAttachShader(Program, vertexShader);
  glAttachShader(Program, fragmentShader);
  glLinkProgram(Program);

  glGetProgramiv(Program, GL_LINK_STATUS, &success);
  if(!success)
  {
    glGetProgramInfoLog(Program, 512, NULL, infolog);
    std::cout << "SHADER LINKER ERROR\n" << infolog << std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  delete[] vertexShaderCode;
  delete[] fragmentShaderCode;

  //Setup uniforms
  modelUniform = GetUniformByName(MODEL_UNIFORM_NAME);
  colorUniform = GetUniformByName(COLOR_UNIFORM_NAME);
  viewUniform = GetUniformByName(VIEW_UNIFORM_NAME);
  projectionUniform = GetUniformByName(PROJECTION_UNIFORM_NAME);
}

Shader::~Shader() {
	glDeleteProgram(Program);
}

void Shader::Use(){
  glUseProgram(Program);
}

GLint Shader::GetUniformByName(const GLchar* name) {
	return glGetUniformLocation(Program, name);
}

void Shader::SetShaderUniformByIndex(const GLuint index, glm::mat4 newValue) {
	glUniformMatrix4fv(index, 1, GL_FALSE, glm::value_ptr(newValue));
}

void Shader::SetShaderUniformByIndex(const GLuint index, glm::vec3 newValue) {
	glUniform3f(index, newValue.x, newValue.y, newValue.z);
}
