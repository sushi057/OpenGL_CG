#include "camera.h"

Camera::Camera(glmath::vec3 position, glmath::vec3 front, glmath::vec3 up, float _yaw, float _pitch)
    : cameraPosition(position.x, position.y, position.z),
    cameraFront(front.x, front.y, front.z),
    cameraUp(up.x, up.y, up.z),
    yaw(_yaw),
    pitch(_pitch)
{
    cameraRight = glmath::normalize(glmath::cross(cameraFront, cameraUp));
    sensitivity = 0.25f;
}

glmath::mat4 Camera::GetLookAtMatrix() const {
    return glmath::lookAt(cameraPosition, cameraPosition + glmath::normalize(cameraFront), cameraUp);
}

void Camera::processKeyboardEvent(CameraDirection direction, float deltaTime) {
    float cameraSpeed = 0.4 * deltaTime;

    if (direction == CameraDirection::FORWARD) {
        cameraPosition += cameraSpeed * cameraFront.unitVector();
    }
    if (direction == CameraDirection::LEFT) {
        cameraPosition -= cameraSpeed * glmath::normalize(glmath::cross(cameraFront, cameraUp));
    }
    if (direction == CameraDirection::REVERSE) {
        cameraPosition -= cameraSpeed * glmath::normalize(cameraFront);
    }
    if (direction == CameraDirection::RIGHT) {
        cameraPosition += cameraSpeed * glmath::normalize(glmath::cross(cameraFront, cameraUp));
    }
}

void Camera::processMouseEvent(float xOffset, float yOffset, bool constrainScreen) {
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (constrainScreen)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }
    glmath::vec3 front;

    front.x = cos(to_radians(yaw)) * cos(to_radians(pitch));
    front.y = sin(to_radians(pitch));
    front.z = sin(to_radians(yaw)) * cos(to_radians(pitch));

    cameraFront = glmath::normalize(front);
}