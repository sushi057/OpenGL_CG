#pragma once
#include <matrix.h>


enum class CameraDirection {
	FORWARD,
	REVERSE,
	LEFT,
	RIGHT
};


struct Camera {
	glmath::vec3 cameraPosition, cameraFront, cameraUp, cameraRight;

	float sensitivity;

	float yaw, pitch;

	Camera(glmath::vec3 position = glmath::vec3(0.0f, 0.0f, 0.0f), glmath::vec3 front = glmath::vec3(0.0f, 0.0f, -1.0f), glmath::vec3 up = glmath::vec3(0.0f, 1.0f, 0.0f), float _yaw = -90.0f, float _pitch = 0.0f);

	glmath::mat4 GetLookAtMatrix() const;

	void processKeyboardEvent(CameraDirection direction, float deltaTime);

	void processMouseEvent(float xOffset, float yOffset, bool constrainScreen = true);

	void updateVectors();
};