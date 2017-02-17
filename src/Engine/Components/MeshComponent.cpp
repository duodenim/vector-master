//
// Created by joseph on 12/30/16.
//

#include "MeshComponent.h"
#include "../EngineCore.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

MeshComponent::MeshComponent(GLfloat *vertexData, GLuint size) {
    renderer = EngineCore::GetEngine()->GetRenderer();
    shader = new Shader("vertex.glsl", "fragment.glsl");
    renderer->RegisterObject(vertexData, size, &vbo);
    numVerticies = size / 3;
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = 0.0f;

		color = glm::vec3(0.8f, 1.0f, 1.0f);
		shader->Use();
		shader->SetShaderUniformByIndex(shader->colorUniform, color);
}
MeshComponent::~MeshComponent(){
    delete shader;
    renderer->DeleteObject(&vbo);
}
void MeshComponent::Draw() {
    shader->Use();
    UpdateTransforms();
    renderer->Draw(vbo, numVerticies, shader);
}
void MeshComponent::SetColor(glm::vec3 newColor) {
	color = newColor;
	shader->Use();
	shader->SetShaderUniformByIndex(shader->colorUniform, color);
}
void MeshComponent::SetColor(float red, float green, float blue) {
	color = glm::vec3(red, green, blue);
	shader->Use();
	shader->SetShaderUniformByIndex(shader->colorUniform, color);
}
void MeshComponent::UpdateTransforms() {
    modelMatrix = glm::mat4();
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));

	shader->SetShaderUniformByIndex(shader->modelUniform, modelMatrix);
}
