#include "sillyrabbit/graphics/Camera/FreeViewCamera.hpp"

namespace sr { namespace graphics {

FreeViewCamera::FreeViewCamera()
{ }

FreeViewCamera::FreeViewCamera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector)
 : LookCamera(cameraPosition, cameraTarget, upVector)
{ }

FreeViewCamera::~FreeViewCamera()
{ }

void FreeViewCamera::setKeyLayout(sf::Keyboard::Key forward, sf::Keyboard::Key left, sf::Keyboard::Key backward, sf::Keyboard::Key right)
{
    keyForward = forward;
    keyLeft = left;
    keyBackward = backward;
    keyRight = right;
}

void FreeViewCamera::onKeyboard(const sf::Time& dt)
{
    if(sf::Keyboard::isKeyPressed(keyForward))
    {
        setPosition(getPosition() + (cameraSpeed * cameraFront * dt.asSeconds()));
    }
    if(sf::Keyboard::isKeyPressed(keyBackward))
    {
        setPosition(getPosition() - (cameraSpeed * cameraFront * dt.asSeconds()));
    }
    if(sf::Keyboard::isKeyPressed(keyLeft))
    {
        setPosition(getPosition() - glm::normalize(glm::cross(cameraFront, cameraUp)) * dt.asSeconds() * cameraSpeed);
    }
    if(sf::Keyboard::isKeyPressed(keyRight))
    {
        setPosition(getPosition() + glm::normalize(glm::cross(cameraFront, cameraUp)) * dt.asSeconds() * cameraSpeed);
    }
}


} }
