#include "CameraComponent.h"
#include <gtc/matrix_transform.hpp>
#include "../EngineCore.h"

CameraComponent::CameraComponent() {
	position = glm::vec3(0.0f, 0.02f, 1.0f);
	viewTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	aspect = 1.0f;
	fov = 45.5f;
	view = glm::lookAt(position, viewTarget, glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(fov, 0.5625f, 0.1f, 100.0f);

}

CameraComponent::~CameraComponent() {

}

void CameraComponent::SetAsMainCamera() {
	EngineCore* engine = EngineCore::GetEngine();
	engine->GetRenderer()->SetMainCamera(this);
}

void CameraComponent::RecalulatePosition(){
	view = glm::lookAt(position, viewTarget, glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(fov, 0.5625f, 0.1f, 100.0f);
}
