#ifndef SILLYRABBIT_GRAPHICS_LOOKCAMERA_HPP
#define SILLYRABBIT_GRAPHICS_LOOKCAMERA_HPP

#include "../Camera.hpp"

namespace sr { namespace graphics {

class LookCamera : public sr::graphics::Camera
{
    public:
        LookCamera();
        LookCamera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f));
        virtual ~LookCamera();

        void onMouse(const glm::vec2& mouseDelta);

    protected:

        float sensivity;

    private:
};

} }

#endif // SILLYRABBIT_GRAPHICS_LOOKCAMERA_H
