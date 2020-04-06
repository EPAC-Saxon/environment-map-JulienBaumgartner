#include "Camera.h"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>

namespace sgl {

	Camera::Camera(
		const glm::vec3& position /*= { 0.f, 0.f, 0.f }*/, 
		const glm::vec3& front /*= { 0.f, 0.f, -1.f }*/, 
		const glm::vec3& up /*= { 0.f, 1.f, 0.f }*/) :
		position_(position),
		front_(front),
		up_(up)
	{
#pragma message ("You have to complete this code!")
	}

	const glm::mat4 Camera::GetLookAt() const
	{
#pragma message ("You have to complete this code!")
		return {};
	}

	void Camera::UpdateCameraVectors()
	{
#pragma message ("You have to complete this code!")
	}

}	// End namespace sgl.
