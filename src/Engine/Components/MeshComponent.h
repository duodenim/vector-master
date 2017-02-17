//
// Created by joseph on 12/30/16.
//

#ifndef PONGGL_MESH_H
#define PONGGL_MESH_H

#include "../Component.h"
#include "../Shader.h"
#include "../Renderer.h"
#include <glew.h>
#include <glm.hpp>


class MeshComponent : public Component{
public:
    MeshComponent(GLfloat *vertexData, GLuint size);
    ~MeshComponent();
    void Draw();

    glm::vec3 position;
    float rotation;

	void SetColor(glm::vec3 newColor);
	void SetColor(float red, float blue, float green);

private:
    Renderer *renderer;
    Shader *shader;
    GLuint vao;
    GLuint vbo;
    GLuint numVerticies;

    glm::mat4 modelMatrix;

	glm::vec3 color;

    void UpdateTransforms();

};


#endif //PONGGL_MESH_H
