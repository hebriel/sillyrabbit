#ifndef SILLYRABBIT_OBJECTS_GAMEOBJECT_HPP
#define SILLYRABBIT_OBJECTS_GAMEOBJECT_HPP

#include "../utils/Math.hpp"

namespace sr { namespace objects {

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        glm::vec3 getPosition() {return m_position;}
        void setPosition(glm::vec3 position) {m_position = position;}

        float getPitch() {return m_pitch;}
        float getYaw() {return m_yaw;}
        float getRoll() {return m_roll;}

        void setPitch(float pitch)  {m_pitch = pitch;}
        void setYaw(float yaw) {m_yaw = yaw;}
        void setRoll(float roll) {m_roll = roll;}

        glm::vec3 getRotation() {return glm::vec3(m_pitch, m_yaw, m_roll);}
        void setRotation(glm::vec3 rotation);

    protected:

    private:

        float m_pitch, m_yaw, m_roll; /**Euler angles**/
        glm::vec3 m_position;

};

} }

#endif // SILLYRABBIT_OBJECTS_GAMEOBJECT_HPP
