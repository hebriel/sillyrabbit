#ifndef SILLYRABBIT_GRAPHICS_CAMERA_HPP
#define SILLYRABBIT_GRAPHICS_CAMERA_HPP

#include "../objects/GameObject.hpp"

namespace sr { namespace graphics {

class Camera : public objects::GameObject
{
    public:
        Camera();
        Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f));
        virtual ~Camera();

        void setTarget(glm::vec3 cameraTarget) {target = cameraTarget;}
        glm::vec3 getTarget() {return target;}

        glm::mat4 lookAtTarget();
        glm::mat4 look();

    protected:

        glm::vec3 target;
        glm::vec3 direction;

        glm::vec3 up;

        glm::vec3 cameraRight;
        glm::vec3 cameraUp;

        glm::vec3 cameraFront;

    private:

};

} }

#endif // SILLYRABBIT_GRAPHICS_CAMERA_HPP
