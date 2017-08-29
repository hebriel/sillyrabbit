#include "sillyrabbit/graphics/Camera.hpp"

namespace sr { namespace graphics {

Camera::Camera()
{

}

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector)
   : cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)), cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
{
    setPosition(cameraPosition);
    target = cameraTarget;
    up = upVector;

    direction = glm::normalize(getPosition() - target);
    cameraRight = glm::normalize(glm::cross(up, direction));
    cameraRight = glm::cross(up, cameraRight);
}

glm::mat4 Camera::lookAtTarget()
{
    return glm::lookAt(getPosition(), target, up);
}

glm::mat4 Camera::look()
{
    return glm::lookAt(getPosition(), getPosition() + cameraFront, cameraUp);
}


Camera::~Camera()
{
    //dtor
}

} }
