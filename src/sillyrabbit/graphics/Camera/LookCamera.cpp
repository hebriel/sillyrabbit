#include "sillyrabbit/graphics/Camera/LookCamera.hpp"
#include <iostream>

namespace sr { namespace graphics {

LookCamera::LookCamera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector)
    : Camera(cameraPosition, cameraTarget, upVector), sensivity(0.05f)
{
    //ctor
}

LookCamera::LookCamera()
{ }

LookCamera::~LookCamera()
{
    //dtor
}

void LookCamera::onMouse(const glm::vec2& mouseDelta)
{
    glm::vec2 delta = mouseDelta * sensivity;
    setYaw(getYaw() + delta.x);
    setPitch(getPitch() + delta.y);

    if(getPitch() > 89.0f)
      setPitch(89.0f);
    else if(getPitch() < -89.0f)
      setPitch(-89.0f);

    glm::vec3 front;
    front.x = std::cos(glm::radians(getYaw())) * std::cos(glm::radians(getPitch()));
    front.y = -std::sin(glm::radians(getPitch()));
    front.z = std::sin(glm::radians(getYaw())) * std::cos(glm::radians(getPitch()));


    cameraFront = glm::normalize(front);
}

} }
