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
		UpdateCameraVectors();
	}

	const glm::mat4 Camera::GetLookAt() const
	{
		return glm::lookAt(position_, front_ - position_, up_);
	}

	void Camera::UpdateCameraVectors()
	{
		float yaw_rad = glm::radians(yaw_);
		float pitch_rad = glm::radians(pitch_);

		front_ = position_ + glm::vec3({ glm::cos(pitch_rad) * glm::cos(yaw_rad),
										glm::sin(pitch_rad),
										glm::cos(pitch_rad)* glm::sin(yaw_rad) });
		front_ = glm::normalize(front_);
		right_ = glm::cross({0,1,0},front_);
		right_ = glm::normalize(right_);
		up_ = glm::cross(front_, right_);
		up_ = glm::normalize(up_);

	}

}	// End namespace sgl.
