#ifndef SILLYRABBIT_GRAPHICS_FREEVIEWCAMERA_HPP
#define SILLYRABBIT_GRAPHICS_FREEVIEWCAMERA_HPP

#include "LookCamera.hpp"
#include <SFML/Window.hpp>

namespace sr { namespace graphics {

class FreeViewCamera : public LookCamera
{
    public:
        FreeViewCamera();
        FreeViewCamera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f));
        virtual ~FreeViewCamera();

        void setKeyLayout(sf::Keyboard::Key forward, sf::Keyboard::Key left, sf::Keyboard::Key backward, sf::Keyboard::Key right);

        void onKeyboard(const sf::Time& dt);

        void setSpeed(float speed) {cameraSpeed = speed;}
        float getSpeed() {return cameraSpeed;}

    protected:

        float cameraSpeed;

        sf::Keyboard::Key keyForward, keyLeft, keyBackward, keyRight;

    private:
};

} }

#endif // SILLYRABBIT_GRAPHICS_FREEVIEWCAMERA_HPP
