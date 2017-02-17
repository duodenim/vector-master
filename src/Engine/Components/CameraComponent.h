#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

#include "../Component.h"
#include <glm.hpp>

class CameraComponent : public Component {
public:
	CameraComponent();
	~CameraComponent();
	void RecalulatePosition();

	glm::vec3 position;
	glm::vec3 viewTarget;
	void SetAsMainCamera();
	glm::mat4 view;
	glm::mat4 projection;
private:
	bool orthographic;
	float aspect;
	float fov;
};

#endif
